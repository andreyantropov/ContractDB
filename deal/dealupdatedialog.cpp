#include "dealupdatedialog.h"
#include "ui_dealupdatedialog.h"

DealUpdateDialog::DealUpdateDialog(QString currentSec, QString currentDeal, QString currentOrg, QString currentTheme, QString currentItem, QString currentDate, QString currentDealLink, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DealUpdateDialog)
{
    ui->setupUi(this);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251"));

    //���������� ���� ������
    db = QSqlDatabase::database();

    //��������� �����-����� � ������������ � �������� �������
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

    //�������-�����
    //��� ������� �� ������ "���������" ��������� ������ � ��
    connect(ui->saveButton, SIGNAL(clicked()),
            this, SLOT(slotSaveButtonClicked()));
    //��� ������� �� ������ "������" ��������� ����������
    connect(ui->rejectButton, SIGNAL(clicked()),
            this, SLOT(reject()));
}

/*���������, ����������� ��������� � ��������� � ���� ������
���� ��� ���� ���������, �� ��������� ������
���� ������ ������� ��������, �� �������� ��������� copyDir
��������� ������� ������ ���������� � ��������� � �����������*/
void DealUpdateDialog::slotSaveButtonClicked()
{
    if(ui->dealEdit->text().isEmpty() || ui->themeEdit->text().isEmpty() || ui->itemEdit->text().isEmpty() || ui->secCombo->currentText() == "-" || ui->orgCombo->currentText() == "-")
        Alert(tr("���� ��� ��������� ����� �� ���������."));
    else if(!QRegExp("^([^<>#/|*?\"]*)$").exactMatch(ui->dealEdit->text()))
        Alert(tr("��� ���������� �������� ������������ �������: /|:*?<>�\\\" ��� ������."));
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
            //������� ������� ��� ��������� ������ � ��
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
                        Alert(tr("��������� ������� ���������."));
                    else
                        //�������� ���������� ������ ����� � �����
                        if(QDir(QApplication::applicationDirPath() + "/deal/deal/"+tSec).mkpath(tDeal))
                        {
                            QApplication::setOverrideCursor(Qt::WaitCursor);
                            copyDir(QDir(currentLink), QDir(QApplication::applicationDirPath() + "/deal/deal/"+tSec+"/"+tDeal), db);
                            Alert(tr("��������� ������� ���������."));
                            QApplication::restoreOverrideCursor();
                        }
                        else
                            Alert(tr("�� ������� ������� ����� ����������. ��������, ���������� � ����� ������ ��� ����������."));
                }
                else
                    Alert(tr("���������� � ����� ������ ��� ����������."));
            }
            else
                Alert(tr("�� ������� ��������� ���������."));
            db.close();
        }
        else
            Alert(tr("�� ������� �������� ������ � ���� ������."));
        this->accept();
    }
}

DealUpdateDialog::~DealUpdateDialog()
{
    delete ui;
}
