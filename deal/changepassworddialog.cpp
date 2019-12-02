#include "changepassworddialog.h"
#include "ui_changepassworddialog.h"

ChangePasswordDialog::ChangePasswordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangePasswordDialog)
{
    ui->setupUi(this);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251"));

    //���������� ���� ������
    db = QSqlDatabase::database();

    //������������� ����� ����� �������� password
    ui->currentPasswordEdit->setEchoMode(QLineEdit::Password);
    ui->newPasswordEdit->setEchoMode(QLineEdit::Password);
    ui->confirmPasswordEdit->setEchoMode(QLineEdit::Password);

    //�������-�����
    //��� ������� �� ������ "���������" �������� ������ ������
    //�� �����
    connect(ui->saveButton, SIGNAL(clicked()),
            this, SLOT(slotSaveButtonClicked()));
    //��� ������� �� ������ "��������" ��������� ����
    //��������� ������
    connect(ui->rejectButton, SIGNAL(clicked()),
            this, SLOT(reject()));
}

/*���������, ��������� ���������� ���� t_pas � ��
��������� ������������ ����� ������� � ������ �������.*/
void ChangePasswordDialog::slotSaveButtonClicked()
{
    //��������� ������� ������ �� ��
    if(db.open())
    {
        QSqlQuery query;
        query.exec("SELECT t_pas FROM password");
        if(query.next())
        {
            //��������� ������������ ����� ������� �������
            if(ui->currentPasswordEdit->text() == query.value(0).toString())
                //��������� ���������� ������ ������
                if(ui->newPasswordEdit->text() == ui->confirmPasswordEdit->text())
                {
                    //������ ������ � ��
                    query.prepare("UPDATE password "
                                  "SET t_pas = '"+ui->newPasswordEdit->text()+"'");
                    if(query.exec())
                    {
                        Alert(tr("������ ������� �������"));
                        this->accept();
                    }
                    else
                        Alert(tr("�� ������� �������� ������"));
                }
                else
                    Alert(tr("������ �� ���������"));
            else
                Alert(tr("������� ������ ������ ������"));
        }
        db.close();
    }
    else
        Alert(tr("�� ������� ������� ���� ������."));
}

/*���������� ������*/
ChangePasswordDialog::~ChangePasswordDialog()
{
    delete ui;
}
