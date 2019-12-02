#include "applicationdialog.h"
#include "ui_applicationdialog.h"

ApplicationDialog::ApplicationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ApplicationDialog)
{
    ui->setupUi(this);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251"));

    //Подключаем базу данных
    db = QSqlDatabase::database();

    //Заполняем комбо-боксы, отвечающие за сектор и номер договора
    ui->secCombo->fillComboBox("SELECT t_sec "
                               "FROM deal", db);
    ui->dealCombo->fillComboBox("SELECT n_deal "
                                "FROM sec, deal "
                                "WHERE deal.n_sec = sec.n_sec "
                                "AND t_sec = '"+ui->dealCombo->currentText()+"'", db);
    //Заполняем комбо-бокс, отвечающий за тип приложения
    ui->typeCombo->fillComboBox("SELECT t_type "
                                "FROM type", db);

    //СИГНАЛЫ-СЛОТЫ
    //При изменении содержимого комбо-бокса, отвечающего за сектор
    //меняем содержимое комбо-бокса, отвечающего за договора,
    //закрепленные за конкрентым сектором
    connect(ui->secCombo, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(slotSecComboChanged(QString)));
    //При нажатии на кнопку "Сохранить" сохраняем данные в базу
    connect(ui->saveButton, SIGNAL(clicked()),
            this, SLOT(slotSaveButtonClicked()));
    //При нажатии на кнопку "Отмена" закрываем приложение
    connect(ui->rejectButton, SIGNAL(clicked()),
            this, SLOT(reject()));
    //При нажатии на кнопку "Выбрать файл" открываем браузер файлов
    connect(ui->selectFileButton, SIGNAL(clicked()),
            this, SLOT(slotSelectFileButtonClicked()));
    //При нажатии на кнопку WinScan2PDF открываем соответствующее приложение
    connect(ui->winScanButton, SIGNAL(clicked()),
            this, SLOT(slotWinScanButtonClicked()));
}

/*Процедура, принимающая на вход строки:
tDeal - номер договора,
tType - тип договора,
tApplication - имя приложения,
tLink - ссылку на копируемый файл
и файл file - новое расположение копируемого приложения.
Сохраняет новое приложение в базу данных или выдает сообщение об ошибке,
если не удается сохранить приложение*/
void ApplicationDialog::saveFile(QString tDeal, QString tType, QString tApplication, QString tLink, QString fileName)
{
    if(db.open())
    {
        QSqlQuery queryApp;
        queryApp.prepare("INSERT INTO app (n_deal, n_type, t_app, t_app_link) "
                         "VALUES ('"+tDeal+"', (SELECT n_type "
                                                "FROM type "
                                                "WHERE t_type = '"+tType.replace("_", " ")+"'), "
                         "'"+tApplication.replace("_", " ")+"', '"+fileName+"')");
        if(queryApp.exec())
        {
            QApplication::setOverrideCursor(Qt::WaitCursor);
            //Копируем выбранный файл в базу
            QFile::copy(tLink, fileName) ? Alert(tr("Приложение успешно сохранено")) : Alert(tr("Не удалось сохранить приложение."));
            QApplication::restoreOverrideCursor();
        }
        else
            Alert(tr("Не удалось сохранить приложение"));
        db.close();
    }
    else
        Alert(tr("Не удалось открыть базу данных."));
    this->accept();
}

/*Процедура, принимающая на вход строку currentText, содержащую значение
элемента secCombo. Очищает и заполняет элемент dealCombo данными, в соответствии
со строкой currentText*/
void ApplicationDialog::slotSecComboChanged(QString currentText)
{
    ui->dealCombo->fillComboBox("SELECT n_deal "
                                "FROM sec, deal "
                                "WHERE deal.n_sec = sec.n_sec "
                                "AND t_sec = '"+currentText+"'", db);
}

/*Процедура, сохраняющая новые приложения в базу данных
Если все поля заполнены, то проверяет, существует ли уже
папка для данного типа приложений. Если нет, то создает ее и проверяет
существование приложения с таким же именем
Если приложения с такми же именем еще не существует, то
создает его и добавляет информацию о нем в базу данных*/
void ApplicationDialog::slotSaveButtonClicked()
{
    if(ui->applicationEdit->text().isEmpty() || ui->linkEdit->text().isEmpty() || (ui->secCombo->currentText() == "-") || (ui->dealCombo->currentText() == "-"))
        Alert(tr("Одно или несколько полей не заполнены"));
    else if(!QRegExp("^([^<>#/|*?\"]*)$").exactMatch(ui->applicationEdit->text()))
        Alert(tr("Имя файла содержит недопустимые символы: /|:*?<>\\\""));
    else
    {
        QString tApplication, tLink, tDeal, tType, tSec;
        tApplication = ui->applicationEdit->text();
        tLink = ui->linkEdit->text();
        tSec = ui->secCombo->currentText();
        tType = ui->typeCombo->currentText();
        tDeal = ui->dealCombo->currentText();
        //Проверяем, существует ли для текущего приложения соответствующая папка
        //Если не существует, то создаем ее
        if(!QDir(QApplication::applicationDirPath() + "/deal/deal/"+tSec+"/"+tDeal+"/"+tType.replace(" ", "_")+"").exists())
            if(!QDir(QApplication::applicationDirPath() + "/deal/deal/"+tSec+"/"+tDeal+"").mkpath(tType))
            {
                Alert(tr("Не удалось сохранить приложение в базу данных."));
                return;
            }
        if(!QFile::exists(QApplication::applicationDirPath() + "/deal/deal/"+tSec+"/"+tDeal+"/"+tType+"/"+tApplication.replace(" ", "_")+"."+tLink.split('.').back()+""))
            saveFile(tDeal, tType, tApplication, tLink, QApplication::applicationDirPath() + "/deal/deal/"+tSec+"/"+tDeal+"/"+tType+"/"+tApplication.replace(" ", "_")+"."+tLink.split('.').back()+"");
        else
            Alert(tr("Файл с таким именем уже существует"));
    }
}

/*Процедура, открывающая окно QFileDialog (браузер файлов) для выбора файла для
загрузки в базу данных. Заполняет поле linkEdit ссылкой на файл*/
void ApplicationDialog::slotSelectFileButtonClicked()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Select File"), "D:/", "All types (*.*);;PDF Files (*.pdf);;DOC Files (*.doc)");
    ui->linkEdit->setText(path);
}

/*Процедура, открывающая программу WinScan2PDF для сканирования нового документа*/
void ApplicationDialog::slotWinScanButtonClicked()
{
    QString pth = "K:/WinScan2PDF.exe";
    if(QProcess::execute("cmd start /c \""+pth+"\"") == -2)
        Alert(tr("Не удалось открыть WinScan2PDF для сканирования нового приложения"));
}

ApplicationDialog::~ApplicationDialog()
{
    delete ui;
}
