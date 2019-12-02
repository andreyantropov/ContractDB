#include "applicationdialog.h"
#include "ui_applicationdialog.h"

ApplicationDialog::ApplicationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ApplicationDialog)
{
    ui->setupUi(this);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251"));

    //���������� ���� ������
    db = QSqlDatabase::database();

    //��������� �����-�����, ���������� �� ������ � ����� ��������
    ui->secCombo->fillComboBox("SELECT t_sec "
                               "FROM deal", db);
    ui->dealCombo->fillComboBox("SELECT n_deal "
                                "FROM sec, deal "
                                "WHERE deal.n_sec = sec.n_sec "
                                "AND t_sec = '"+ui->dealCombo->currentText()+"'", db);
    //��������� �����-����, ���������� �� ��� ����������
    ui->typeCombo->fillComboBox("SELECT t_type "
                                "FROM type", db);

    //�������-�����
    //��� ��������� ����������� �����-�����, ����������� �� ������
    //������ ���������� �����-�����, ����������� �� ��������,
    //������������ �� ���������� ��������
    connect(ui->secCombo, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(slotSecComboChanged(QString)));
    //��� ������� �� ������ "���������" ��������� ������ � ����
    connect(ui->saveButton, SIGNAL(clicked()),
            this, SLOT(slotSaveButtonClicked()));
    //��� ������� �� ������ "������" ��������� ����������
    connect(ui->rejectButton, SIGNAL(clicked()),
            this, SLOT(reject()));
    //��� ������� �� ������ "������� ����" ��������� ������� ������
    connect(ui->selectFileButton, SIGNAL(clicked()),
            this, SLOT(slotSelectFileButtonClicked()));
    //��� ������� �� ������ WinScan2PDF ��������� ��������������� ����������
    connect(ui->winScanButton, SIGNAL(clicked()),
            this, SLOT(slotWinScanButtonClicked()));
}

/*���������, ����������� �� ���� ������:
tDeal - ����� ��������,
tType - ��� ��������,
tApplication - ��� ����������,
tLink - ������ �� ���������� ����
� ���� file - ����� ������������ ����������� ����������.
��������� ����� ���������� � ���� ������ ��� ������ ��������� �� ������,
���� �� ������� ��������� ����������*/
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
            //�������� ��������� ���� � ����
            QFile::copy(tLink, fileName) ? Alert(tr("���������� ������� ���������")) : Alert(tr("�� ������� ��������� ����������."));
            QApplication::restoreOverrideCursor();
        }
        else
            Alert(tr("�� ������� ��������� ����������"));
        db.close();
    }
    else
        Alert(tr("�� ������� ������� ���� ������."));
    this->accept();
}

/*���������, ����������� �� ���� ������ currentText, ���������� ��������
�������� secCombo. ������� � ��������� ������� dealCombo �������, � ������������
�� ������� currentText*/
void ApplicationDialog::slotSecComboChanged(QString currentText)
{
    ui->dealCombo->fillComboBox("SELECT n_deal "
                                "FROM sec, deal "
                                "WHERE deal.n_sec = sec.n_sec "
                                "AND t_sec = '"+currentText+"'", db);
}

/*���������, ����������� ����� ���������� � ���� ������
���� ��� ���� ���������, �� ���������, ���������� �� ���
����� ��� ������� ���� ����������. ���� ���, �� ������� �� � ���������
������������� ���������� � ����� �� ������
���� ���������� � ����� �� ������ ��� �� ����������, ��
������� ��� � ��������� ���������� � ��� � ���� ������*/
void ApplicationDialog::slotSaveButtonClicked()
{
    if(ui->applicationEdit->text().isEmpty() || ui->linkEdit->text().isEmpty() || (ui->secCombo->currentText() == "-") || (ui->dealCombo->currentText() == "-"))
        Alert(tr("���� ��� ��������� ����� �� ���������"));
    else if(!QRegExp("^([^<>#/|*?\"]*)$").exactMatch(ui->applicationEdit->text()))
        Alert(tr("��� ����� �������� ������������ �������: /|:*?<>\\\""));
    else
    {
        QString tApplication, tLink, tDeal, tType, tSec;
        tApplication = ui->applicationEdit->text();
        tLink = ui->linkEdit->text();
        tSec = ui->secCombo->currentText();
        tType = ui->typeCombo->currentText();
        tDeal = ui->dealCombo->currentText();
        //���������, ���������� �� ��� �������� ���������� ��������������� �����
        //���� �� ����������, �� ������� ��
        if(!QDir(QApplication::applicationDirPath() + "/deal/deal/"+tSec+"/"+tDeal+"/"+tType.replace(" ", "_")+"").exists())
            if(!QDir(QApplication::applicationDirPath() + "/deal/deal/"+tSec+"/"+tDeal+"").mkpath(tType))
            {
                Alert(tr("�� ������� ��������� ���������� � ���� ������."));
                return;
            }
        if(!QFile::exists(QApplication::applicationDirPath() + "/deal/deal/"+tSec+"/"+tDeal+"/"+tType+"/"+tApplication.replace(" ", "_")+"."+tLink.split('.').back()+""))
            saveFile(tDeal, tType, tApplication, tLink, QApplication::applicationDirPath() + "/deal/deal/"+tSec+"/"+tDeal+"/"+tType+"/"+tApplication.replace(" ", "_")+"."+tLink.split('.').back()+"");
        else
            Alert(tr("���� � ����� ������ ��� ����������"));
    }
}

/*���������, ����������� ���� QFileDialog (������� ������) ��� ������ ����� ���
�������� � ���� ������. ��������� ���� linkEdit ������� �� ����*/
void ApplicationDialog::slotSelectFileButtonClicked()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Select File"), "D:/", "All types (*.*);;PDF Files (*.pdf);;DOC Files (*.doc)");
    ui->linkEdit->setText(path);
}

/*���������, ����������� ��������� WinScan2PDF ��� ������������ ������ ���������*/
void ApplicationDialog::slotWinScanButtonClicked()
{
    QString pth = "K:/WinScan2PDF.exe";
    if(QProcess::execute("cmd start /c \""+pth+"\"") == -2)
        Alert(tr("�� ������� ������� WinScan2PDF ��� ������������ ������ ����������"));
}

ApplicationDialog::~ApplicationDialog()
{
    delete ui;
}
