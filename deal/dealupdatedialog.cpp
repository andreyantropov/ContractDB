#include "dealupdatedialog.h"
#include "ui_dealupdatedialog.h"

DealUpdateDialog::DealUpdateDialog(QString currentSec, QString currentDeal, QString currentOrg, QString currentTheme, QString currentItem, QString currentDate, QString currentDealLink, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DealUpdateDialog)
{
    ui->setupUi(this);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251"));

    //Подключаем базу данных
    db = QSqlDatabase::database();

    //Заполняем комбо-боксы в соответствии с текущими данными
    ui->secCombo->fillComboBox("SELECT t_sec "
                               "FROM deal", db);
    ui->secCombo->setCurrentIndex(ui->secCombo->getIndex(currentSec));
    ui->orgCombo->fillComboBox("SELECT t_org "
                               "FROM org", db);
    ui->orgCombo->setCurrentIndex(ui->orgCombo->getIndex(currentOrg));
    ui->dealEdit->setText(currentDeal);
    ui->themeEdit->setText(currentTheme);
    ui->itemEdit->setText(currentItem);
    ui->dateEdit->setDate(QDate::fromString(currentDate, "dd.MM.yyyy"));
    currentLink = currentDealLink;

    //СИГНАЛЫ-СЛОТЫ
    //При нажатии на кнопку "Сохранить" сохраняем данные в БД
    connect(ui->saveButton, SIGNAL(clicked()),
            this, SLOT(slotSaveButtonClicked()));
    //При нажатии на кнопку "Отмена" закрываем приложение
    connect(ui->rejectButton, SIGNAL(clicked()),
            this, SLOT(reject()));
}

/*Процедура, сохраняющая изменения о договорах в базе данных
Если все поля заполнены, то обновляет данные
Если запрос успешно выполнен, то вызывает процедуру copyDir
Обновляет таблицы вывода информации о договорах и приложениях*/
void DealUpdateDialog::slotSaveButtonClicked()
{
    if(ui->dealEdit->text().isEmpty() || ui->themeEdit->text().isEmpty() || ui->itemEdit->text().isEmpty() || ui->secCombo->currentText() == "-" || ui->orgCombo->currentText() == "-")
        Alert(tr("Одно или несколько полей не заполнены."));
    else if(!QRegExp("^([^<>#/|*?\"]*)$").exactMatch(ui->dealEdit->text()))
        Alert(tr("Имя директории содержит недопустимые символы: /|:*?<>№\\\" или пробел."));
    else
    {
        QString tSec, tDeal, tTheme, tItem, tOrg, dDate;
        tSec = ui->secCombo->currentText();
        tOrg = ui->orgCombo->currentText();
        tDeal = ui->dealEdit->text();
        tTheme = ui->themeEdit->text();
        tItem = ui->itemEdit->text();
        dDate = ui->dateEdit->dateToDB();
        if(db.open())
        {
            //Готовим запросы для изменения данных в БД
            QSqlQuery correctSecQuery, correctDocQuery, correctAppQuery;
            correctAppQuery.prepare("UPDATE app "
                                    "SET n_deal = '"+tDeal+"' "
                                    "WHERE n_deal = '"+currentLink.split('/').back()+"'");
            correctDocQuery.prepare("UPDATE doc "
                                    "SET n_deal = '"+tDeal+"', t_item = '"+tItem+"', t_theme = '"+tTheme+"', n_org = (SELECT n_org "
                                                                                                                      "FROM org "
                                                                                                                      "WHERE t_org = '"+tOrg+"'), "
                                    "d_date = '"+dDate+"' "
                                    "WHERE n_deal = '"+currentLink.split('/').back()+"'");
            correctSecQuery.prepare("UPDATE sec "
                                    "SET n_deal = '"+tDeal+"', n_sec = (SELECT n_sec "
                                                                        "FROM deal "
                                                                        "WHERE t_sec = '"+tSec+"') "
                                    "WHERE n_deal = '"+currentLink.split('/').back()+"'");

            if(correctAppQuery.exec() && correctDocQuery.exec() && correctSecQuery.exec())
            {
                if(!QDir(QApplication::applicationDirPath() + "/deal/deal/"+tSec+"/"+tDeal).exists() || (QDir(QApplication::applicationDirPath() + "/deal/deal/"+tSec+"/"+tDeal) == QDir(currentLink)))
                {
                    if(QDir(QApplication::applicationDirPath() + "/deal/deal/"+tSec+"/"+tDeal) == QDir(currentLink))
                        Alert(tr("Изменения успешно сохранены."));
                    else
                        //Копируем содержимое старой папки в новую
                        if(QDir(QApplication::applicationDirPath() + "/deal/deal/"+tSec).mkpath(tDeal))
                        {
                            QApplication::setOverrideCursor(Qt::WaitCursor);
                            copyDir(QDir(currentLink), QDir(QApplication::applicationDirPath() + "/deal/deal/"+tSec+"/"+tDeal), db);
                            Alert(tr("Изменения успешно сохранены."));
                            QApplication::restoreOverrideCursor();
                        }
                        else
                            Alert(tr("Не удалось создать новую директорию. Возможно, директория с таким именем уже существует."));
                }
                else
                    Alert(tr("Директория с таким именем уже существует."));
            }
            else
                Alert(tr("Не удалось сохранить изменения."));
            db.close();
        }
        else
            Alert(tr("Не удалось получить доступ к базе данных."));
        this->accept();
    }
}

DealUpdateDialog::~DealUpdateDialog()
{
    delete ui;
}
