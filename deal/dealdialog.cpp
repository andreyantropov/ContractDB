#include "dealdialog.h"
#include "ui_dealdialog.h"

DealDialog::DealDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DealDialog)
{
    ui->setupUi(this);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251"));

    //Подключаем базу данных
    db = QSqlDatabase::database();

    //Заполняем комбо-боксы в соответствии с текущими данными
    ui->secCombo->fillComboBox("SELECT t_sec "
                               "FROM deal", db);
    ui->orgCombo->fillComboBox("SELECT t_org "
                               "FROM org", db);

    //СИГНАЛЫ-СЛОТЫ
    //При нажатии на кнопку "Сохранить" сохраняем новый
    //договор в базе
    connect(ui->saveButton, SIGNAL(clicked()),
            this, SLOT(slotSaveButtonClicked()));
    //При нажатии на кнопку "Отменить" закрываем диалоговое окно
    connect(ui->rejectButton, SIGNAL(clicked()),
            this, SLOT(reject()));
}

/*Процедура, сохраняющая новый договор в базу данных
Если все поля заполнены, то проверяет: существует ли такой договор
уже или нет
Если такого договора не существует, то создает новую папку с именем договора
и сохраняет его в базу данных
Дополняет QComboBox'ы dealSelect и dealSelectOut новыми данными
Очищает содержимое полей на вкладке 'Договора'
Обновляет таблицу вывода договоров*/
void DealDialog::slotSaveButtonClicked()
{
    if(ui->dealEdit->text().isEmpty() || ui->themeEdit->text().isEmpty() || ui->itemEdit->text().isEmpty() || (ui->secCombo->currentText() == "-") || (ui->orgCombo->currentText() == "-"))
        Alert(tr("Одно или несколько полей не заполнены."));
    else if(!QRegExp("^([^<>#/|*?\"]*)$").exactMatch(ui->dealEdit->text()))
        Alert(tr("Имя директории содержит недопустимые символы: /|:*?№<>\\\" или пробел."));
    else
    {
        QString tDeal, tItem, tSec, tTheme, tOrg, dDate;
        tDeal = ui->dealEdit->text();
        tTheme = ui->themeEdit->text();
        tItem = ui->itemEdit->text();
        tSec = ui->secCombo->currentText();
        tOrg = ui->orgCombo->currentText();
        dDate = ui->dateEdit->dateToDB();

        QDir dir(QApplication::applicationDirPath() + "/deal/deal/"+tSec+"");
        if(!QDir(QApplication::applicationDirPath() + "/deal/deal/"+tSec+"/"+tDeal+"").exists())
        {
            if(db.open())
            {
                QSqlQuery querySec, queryDoc;

                //Добавляем договор в БД
                querySec.prepare("INSERT INTO sec (n_deal, n_sec) "
                                 "VALUES ('"+tDeal+"', (SELECT n_sec "
                                                        "FROM deal "
                                                        "WHERE t_sec = '"+tSec+"'))");
                queryDoc.prepare("INSERT INTO doc (n_deal, t_theme, t_item, n_org, d_date) "
                                 "VALUES ('"+tDeal+"', '"+tTheme+"', '"+tItem+"', (SELECT n_org "
                                                                                   "FROM org "
                                                                                   "WHERE t_org = '"+tOrg+"'), "
                                 "'"+dDate+"')");

                if(querySec.exec() && queryDoc.exec())
                {
                    QApplication::setOverrideCursor(Qt::WaitCursor);
                    //Создаем соответствующую папку в системе
                    dir.mkpath(tDeal) ? Alert(tr("Договор успешно сохранен.")) : Alert(tr("Не удалось создать новую директорию. Возможно, директория с таким именем уже существует."));
                    QApplication::restoreOverrideCursor();
                }
                else
                    Alert(tr("Не удалось сохранить договор а базе данных."));
                db.close();
            }
            else
                Alert(tr("Не удалось открыть базу данных."));
            this->accept();
        }
        else
            Alert(tr("Директория с таким именем уже существует."));
    }
}

DealDialog::~DealDialog()
{
    delete ui;
}
