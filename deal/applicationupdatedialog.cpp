#include "applicationupdatedialog.h"
#include "ui_applicationupdatedialog.h"

ApplicationUpdateDialog::ApplicationUpdateDialog(QString currentSec, QString currentDeal, QString currentType, QString currentApplication, QString currentApplicationLink, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ApplicationUpdateDialog)
{
    ui->setupUi(this);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251"));

    //���������� ���� ������
    db = QSqlDatabase::database();

    //��������� ���� � �����-����, ���������� �� ���� ����������
    ui->typeCombo->fillComboBox("SELECT t_type "
                                "FROM type", db);
    //��������� �����-����, ���������� �� ������� � ��������� ��� ������� ���������
    ui->secCombo->fillComboBox("SELECT t_sec "
                               "FROM deal", db);
    ui->secCombo->setCurrentIndex(ui->secCombo->getIndex(currentSec));
    //��������� �����-����, ���������� �� �������� � ��������� ��� ������� ���������
    ui->dealCombo->fillComboBox("SELECT n_deal "
                                "FROM sec, deal "
                                "WHERE deal.n_sec = sec.n_sec "
                                "AND t_sec = '"+ui->secCombo->currentText()+"'", db);
    ui->dealCombo->setCurrentIndex(ui->dealCombo->getIndex(currentDeal));
    //��������� �����-����, ���������� �� ��� ���������� � ��������� ��� ������� ���������
    ui->typeCombo->setCurrentIndex(ui->typeCombo->getIndex(currentType));
    //��������� ���� "����������" ������� ���������
    ui->applicationEdit->setText(currentApplication);
    //��������� ���� "������ �� ����������" ������� �������
    ui->linkEdit->setText(currentApplicationLink);
    currentLink = currentApplicationLink;
    //������������ �� ���������� ���� ��������
    ui->secCombo->setFocus();

    //�������-�����
    //��� ��������� ����������� �����-�����, ����������� �� ������
    //������ ���������� �����-�����, ����������� �� ��������,
    //������������ �� ���������� ��������
    connect(ui->secCombo, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(slotSecComboChanged(QString)));
    //��� ������� �� ������ "���������" ��������� ��������� � ����
    connect(ui->saveButton, SIGNAL(clicked()),
            this, SLOT(slotSaveButtonClicked()));
    //��� ������� �� ������ "��������" ��������� ���� ��������������
    connect(ui->rejectButton, SIGNAL(clicked()),
            this, SLOT(reject()));
    //��� ������� �� ������ "������� ����" ��������� ������� ������
    connect(ui->selectFileButton, SIGNAL(clicked()),
            this, SLOT(slotSelectFileButtonClicked()));
    //��� ������� �� ������ WinScan2PDF ��������� ��������������� ����������
    connect(ui->winScanButton, SIGNAL(clicked()),
            this, SLOT(slotWinScanButtonClicked()));
}

/*���������, ����������� �� ���� ������ �� ������ ����, ������ �� ����� ����
� ������ �� ���� ��� ����� ������
�������� ������ ���� �� �����.*/
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

/*���������, ����������� �� ���� ������:
tDeal - ����� ��������,
tType - ��� ��������,
tApplication - ��� ����������,
tLink - ������ �� ���������� ����,
fileName - ����� ������������ ����������� ����������.
��������� ����� ���������� � ���� ������ ��� ������ ��������� �� ������,
���� �� ������� ��������� ����������*/
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
            removeFile(currentLink, fileName, ui->linkEdit) ? Alert(tr("��������� ������� ���������")) : Alert(tr("�� ������� ��������� ���������"));
            QApplication::restoreOverrideCursor();
        }
        else
            Alert(tr("�� ������� ��������� ���������"));
        db.close();
    }
    else
        Alert(tr("�� ������� ������� ���� ������."));
    this->accept();
}

/*���������, ����������� �� ���� ������ currentText, ���������� ��������
�������� correctSec.
������� QComboBox correctDeal � ��������� ��� �������, ����������
�� ������� currentText*/
void ApplicationUpdateDialog::slotSecComboChanged(QString currentText)
{
    ui->dealCombo->fillComboBox("SELECT n_deal "
                                "FROM sec, deal "
                                "WHERE deal.n_sec = sec.n_sec "
                                "AND t_sec = '"+currentText+"'", db);
}

/*���������, ����������� ���� QFileDialog (������� ������) ��� ������ ����� ���
�������� � ���� ������ �� ������ ������� �����.
���� ���� ������, �� ��������� ���� correctAppLink ������� �� ����� ����.
����� - ��������� ������ �� ������ ����*/
void ApplicationUpdateDialog::slotSelectFileButtonClicked()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Select File"), "D:/", "All types (*.*);;PDF Files (*.pdf);;DOC Files (*.doc)");
    path.isEmpty() ? ui->linkEdit->setText(currentLink) : ui->linkEdit->setText(path);
}

/*���������, ����������� ��������� FineReader ��� ������������ ������ ���������*/
void ApplicationUpdateDialog::slotWinScanButtonClicked()
{
    QString pth = "K:/WinScan2PDF.exe";
    if(QProcess::execute("cmd start /c \""+pth+"\"") == -2)
        Alert(tr("�� ������� ������� WinScan2PDF ��� ������������ ������ ����������"));
}

/*���������, ����������� ��������� ������ � ����������� � ���� ������
���� ��� ���� ���������, �� ��������� ������������� ����� ��� ������� ��������
���� ����� ����� �� ����������, �� ������� ��
��������� ������������� � ���� ����� ��������� � ����� �� ������
���� ����� �� ����������, �� ��������� ���������� ����, � �� ������ ����� - �������
��������� ������ � ���������� � ���� ������
��������� ������� � ����������� � �����������
��������� � ������� ������ ���������� � �����������*/
void ApplicationUpdateDialog::slotSaveButtonClicked()
{
    if(ui->applicationEdit->text().isEmpty() || ui->linkEdit->text().isEmpty() || (ui->secCombo->currentText() == "-") || (ui->dealCombo->currentText() == "-"))
        Alert(tr("���� ��� ��������� ����� �� ���������"));
    else if(!QRegExp("^([^<>#/|*?\"]*)$").exactMatch(ui->applicationEdit->text()))
        Alert(tr("��� ����� �������� ������������ �������: /|:*?<>\\\""));
    else if(!QFile::exists(ui->linkEdit->text()))
        Alert(tr("����, ��������� �� ������ - �����������."));
    else
    {
        QString tSec, tDeal, tType, tApplication, tLink;
        tSec = ui->secCombo->currentText();
        tDeal = ui->dealCombo->currentText();
        tType = ui->typeCombo->currentText();
        tApplication = ui->applicationEdit->text();
        tLink = ui->linkEdit->text();
        //���������, ���������� �� ��� �������� ���������� ��������������� �����
        //���� �� ����������, �� ������� ��
        if(!QDir(QApplication::applicationDirPath() + "/deal/deal/"+tSec+"/"+tDeal+"/"+tType.replace(" ", "_")+"").exists())
            if(!QDir(QApplication::applicationDirPath() + "/deal/deal/"+tSec+"/"+tDeal+"").mkpath(tType))
            {
                Alert(tr("�� ������� ��������� ���������� � ���� ������."));
                return;
            }
        if(!QFile::exists(QApplication::applicationDirPath() + "/deal/deal/"+tSec+"/"+tDeal+"/"+tType.replace(" ", "_")+"/"+tApplication.replace(" ", "_")+"."+tLink.split('.').back()+"") || (currentLink == QApplication::applicationDirPath() + "/deal/deal/"+tSec+"/"+tDeal+"/"+tType.replace(" ", "_")+"/"+tApplication.replace(" ", "_")+"."+tLink.split('.').back()+""))
            saveFile(tSec, tDeal, tType, tApplication, QApplication::applicationDirPath() + "/deal/deal/"+tSec+"/"+tDeal+"/"+tType.replace(" ", "_")+"/"+tApplication.replace(" ", "_")+"."+tLink.split('.').back()+"");
        else
            Alert(tr("���� � ����� ������ ��� ����������"));
    }
}

ApplicationUpdateDialog::~ApplicationUpdateDialog()
{
    delete ui;
}
