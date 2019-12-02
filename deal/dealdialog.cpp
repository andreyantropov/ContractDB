#include "dealdialog.h"
#include "ui_dealdialog.h"

DealDialog::DealDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DealDialog)
{
    ui->setupUi(this);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251"));

    //���������� ���� ������
    db = QSqlDatabase::database();

    //��������� �����-����� � ������������ � �������� �������
    ui->secCombo->fillComboBox("SELECT t_sec "
                               "FROM deal", db);
    ui->orgCombo->fillComboBox("SELECT t_org "
                               "FROM org", db);

    //�������-�����
    //��� ������� �� ������ "���������" ��������� �����
    //������� � ����
    connect(ui->saveButton, SIGNAL(clicked()),
            this, SLOT(slotSaveButtonClicked()));
    //��� ������� �� ������ "��������" ��������� ���������� ����
    connect(ui->rejectButton, SIGNAL(clicked()),
            this, SLOT(reject()));
}

/*���������, ����������� ����� ������� � ���� ������
���� ��� ���� ���������, �� ���������: ���������� �� ����� �������
��� ��� ���
���� ������ �������� �� ����������, �� ������� ����� ����� � ������ ��������
� ��������� ��� � ���� ������
��������� QComboBox'� dealSelect � dealSelectOut ������ �������
������� ���������� ����� �� ������� '��������'
��������� ������� ������ ���������*/
void DealDialog::slotSaveButtonClicked()
{
    if(ui->dealEdit->text().isEmpty() || ui->themeEdit->text().isEmpty() || ui->itemEdit->text().isEmpty() || (ui->secCombo->currentText() == "-") || (ui->orgCombo->currentText() == "-"))
        Alert(tr("���� ��� ��������� ����� �� ���������."));
    else if(!QRegExp("^([^<>#/|*?\"]*)$").exactMatch(ui->dealEdit->text()))
        Alert(tr("��� ���������� �������� ������������ �������: /|:*?�<>\\\" ��� ������."));
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

                //��������� ������� � ��
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
                    //������� ��������������� ����� � �������
                    dir.mkpath(tDeal) ? Alert(tr("������� ������� ��������.")) : Alert(tr("�� ������� ������� ����� ����������. ��������, ���������� � ����� ������ ��� ����������."));
                    QApplication::restoreOverrideCursor();
                }
                else
                    Alert(tr("�� ������� ��������� ������� � ���� ������."));
                db.close();
            }
            else
                Alert(tr("�� ������� ������� ���� ������."));
            this->accept();
        }
        else
            Alert(tr("���������� � ����� ������ ��� ����������."));
    }
}

DealDialog::~DealDialog()
{
    delete ui;
}
