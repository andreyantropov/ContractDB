#include "applicationupdatedialog.h"
#include "ui_applicationupdatedialog.h"

ApplicationUpdateDialog::ApplicationUpdateDialog(QString currentSec, QString currentDeal, QString currentType, QString currentApplication, QString currentApplicationLink, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ApplicationUpdateDialog)
{
    ui->setupUi(this);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251"));

    //Подключаем базу данных
    db = QSqlDatabase::database();

    //Добавляем лист в комбо-бокс, отвечающий за типы документов
    ui->typeCombo->fillComboBox("SELECT t_type "
                                "FROM type", db);
    //Заполняем комбо-бокс, отвечающий за сектора и заполняем его текущим значением
    ui->secCombo->fillComboBox("SELECT t_sec "
                               "FROM deal", db);
    ui->secCombo->setCurrentIndex(ui->secCombo->getIndex(currentSec));
    //Заполняем комбо-бокс, отвечающий за договора и заполняем его текущим значением
    ui->dealCombo->fillComboBox("SELECT n_deal "
                                "FROM sec, deal "
                                "WHERE deal.n_sec = sec.n_sec "
                                "AND t_sec = '"+ui->secCombo->currentText()+"'", db);
    ui->dealCombo->setCurrentIndex(ui->dealCombo->getIndex(currentDeal));
    //Заполняем комбо-бокс, отвечающий за тип приложения и заполняем его текущим значением
    ui->typeCombo->setCurrentIndex(ui->typeCombo->getIndex(currentType));
    //Заполняем поле "Приложение" текущим значением
    ui->applicationEdit->setText(currentApplication);
    //Заполняем поле "Ссылка на приложение" текущей ссылкой
    ui->linkEdit->setText(currentApplicationLink);
    currentLink = currentApplicationLink;
    //Фокусируемся на выпадающем меню секторов
    ui->secCombo->setFocus();

    //СИГНАЛЫ-СЛОТЫ
    //При изменении содержимого комбо-бокса, отвечающего за сектор
    //меняем содержимое комбо-бокса, отвечающего за договора,
    //закрепленные за конкрентым сектором
    connect(ui->secCombo, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(slotSecComboChanged(QString)));
    //При нажатии на кнопку "Сохранить" сохраняем изменения в базе
    connect(ui->saveButton, SIGNAL(clicked()),
            this, SLOT(slotSaveButtonClicked()));
    //При нажатии на кнопку "Отменить" закрываем окно редактирования
    connect(ui->rejectButton, SIGNAL(clicked()),
            this, SLOT(reject()));
    //При нажатии на кнопку "Выбрать файл" открываем браузер файлов
    connect(ui->selectFileButton, SIGNAL(clicked()),
            this, SLOT(slotSelectFileButtonClicked()));
    //При нажатии на кнопку WinScan2PDF открываем соответствующее приложение
    connect(ui->winScanButton, SIGNAL(clicked()),
            this, SLOT(slotWinScanButtonClicked()));
}

/*Процедура, принимающая на вход ссылку на старый файл, ссылку на новый файл
и ссылку на поле для ввода ссылок
Заменяет старый файл на новый.*/
bool ApplicationUpdateDialog::removeFile(QString oldLink, QString newLink, QLineEdit *linkEdit)
{
    if(oldLink == newLink)
    {
        if(oldLink != linkEdit->text())
        {
            if(!QFile(oldLink).remove())
                return false;
        }
        else
            return true;
    }
    if(QFile::copy(linkEdit->text(), newLink))
    {
        if(oldLink != newLink)
            if(!QFile(oldLink).remove())
                return false;
        return true;
    }
    else
        return false;
}

/*Процедура, принимающая на вход строки:
tDeal - номер договора,
tType - тип договора,
tApplication - имя приложения,
tLink - ссылку на копируемый файл,
fileName - новое расположение копируемого приложения.
Сохраняет новое приложение в базу данных или выдает сообщение об ошибке,
если не удается сохранить приложение*/
void ApplicationUpdateDialog::saveFile(QString tSec, QString tDeal, QString tType, QString tApplication, QString fileName)
{
    if(db.open())
    {
        QSqlQuery correctAppQuery;
        correctAppQuery.prepare("UPDATE app "
                                "SET n_deal = '"+tDeal+"', n_type = (SELECT n_type "
                                                                     "FROM type "
                                                                     "WHERE t_type = '"+tType.replace("_", " ")+"'), "
                                "t_app = '"+tApplication.replace("_", " ")+"', t_app_link = '"+fileName+"' "
                                "WHERE t_app_link = '"+currentLink+"'");

        if(correctAppQuery.exec())
        {
            QApplication::setOverrideCursor(Qt::WaitCursor);
            removeFile(currentLink, fileName, ui->linkEdit) ? Alert(tr("Изменения успешно сохранены")) : Alert(tr("Не удалось сохранить изменения"));
            QApplication::restoreOverrideCursor();
        }
        else
            Alert(tr("Не удалось сохранить изменения"));
        db.close();
    }
    else
        Alert(tr("Не удалось открыть базу данных."));
    this->accept();
}

/*Процедура, принимающая на вход строку currentText, содержащую значение
элемента correctSec.
Очищает QComboBox correctDeal и заполняет его данными, связанными
со строкой currentText*/
void ApplicationUpdateDialog::slotSecComboChanged(QString currentText)
{
    ui->dealCombo->fillComboBox("SELECT n_deal "
                                "FROM sec, deal "
                                "WHERE deal.n_sec = sec.n_sec "
                                "AND t_sec = '"+currentText+"'", db);
}

/*Процедура, открывающая окно QFileDialog (браузер файлов) для выбора файла для
загрузки в базу данных на замену старому файлу.
Если файл выбран, то заполняет поле correctAppLink ссылкой на новый файл.
Иначе - оставляет ссылку на старый файл*/
void ApplicationUpdateDialog::slotSelectFileButtonClicked()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Select File"), "D:/", "All types (*.*);;PDF Files (*.pdf);;DOC Files (*.doc)");
    path.isEmpty() ? ui->linkEdit->setText(currentLink) : ui->linkEdit->setText(path);
}

/*Процедура, открывающая программу FineReader для сканирования нового документа*/
void ApplicationUpdateDialog::slotWinScanButtonClicked()
{
    QString pth = "K:/WinScan2PDF.exe";
    if(QProcess::execute("cmd start /c \""+pth+"\"") == -2)
        Alert(tr("Не удалось открыть WinScan2PDF для сканирования нового приложения"));
}

/*Процедура, сохраняющая изменения данных о приложениях в базе данных
Если все поля заполнены, то проверяет существование папки для данного договора
Если такой папки не существует, то создает ее
Процеряет существование в этой папке документа с таким же именем
Если файла не существует, то переносит приложение туда, а из старой папки - удаляет
Обновляет данные о приложении в базе данных
Обновляет таблицу с информацией о приложениях
Переходит к таблице вывода информации о приложениях*/
void ApplicationUpdateDialog::slotSaveButtonClicked()
{
    if(ui->applicationEdit->text().isEmpty() || ui->linkEdit->text().isEmpty() || (ui->secCombo->currentText() == "-") || (ui->dealCombo->currentText() == "-"))
        Alert(tr("Одно или несколько полей не заполнены"));
    else if(!QRegExp("^([^<>#/|*?\"]*)$").exactMatch(ui->applicationEdit->text()))
        Alert(tr("Имя файла содержит недопустимые символы: /|:*?<>\\\""));
    else if(!QFile::exists(ui->linkEdit->text()))
        Alert(tr("Файл, указанный по ссылке - отсутствует."));
    else
    {
        QString tSec, tDeal, tType, tApplication, tLink;
        tSec = ui->secCombo->currentText();
        tDeal = ui->dealCombo->currentText();
        tType = ui->typeCombo->currentText();
        tApplication = ui->applicationEdit->text();
        tLink = ui->linkEdit->text();
        //Проверяем, существует ли для текущего приложения соответствующая папка
        //Если не существует, то создаем ее
        if(!QDir(QApplication::applicationDirPath() + "/deal/deal/"+tSec+"/"+tDeal+"/"+tType.replace(" ", "_")+"").exists())
            if(!QDir(QApplication::applicationDirPath() + "/deal/deal/"+tSec+"/"+tDeal+"").mkpath(tType))
            {
                Alert(tr("Не удалось сохранить приложение а базу данных."));
                return;
            }
        if(!QFile::exists(QApplication::applicationDirPath() + "/deal/deal/"+tSec+"/"+tDeal+"/"+tType.replace(" ", "_")+"/"+tApplication.replace(" ", "_")+"."+tLink.split('.').back()+"") || (currentLink == QApplication::applicationDirPath() + "/deal/deal/"+tSec+"/"+tDeal+"/"+tType.replace(" ", "_")+"/"+tApplication.replace(" ", "_")+"."+tLink.split('.').back()+""))
            saveFile(tSec, tDeal, tType, tApplication, QApplication::applicationDirPath() + "/deal/deal/"+tSec+"/"+tDeal+"/"+tType.replace(" ", "_")+"/"+tApplication.replace(" ", "_")+"."+tLink.split('.').back()+"");
        else
            Alert(tr("Файл с таким именем уже существует"));
    }
}

ApplicationUpdateDialog::~ApplicationUpdateDialog()
{
    delete ui;
}
