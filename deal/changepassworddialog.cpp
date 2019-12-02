#include "changepassworddialog.h"
#include "ui_changepassworddialog.h"

ChangePasswordDialog::ChangePasswordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangePasswordDialog)
{
    ui->setupUi(this);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251"));

    //Подключаем базу данных
    db = QSqlDatabase::database();

    //Устанавливаем полям ввода свойство password
    ui->currentPasswordEdit->setEchoMode(QLineEdit::Password);
    ui->newPasswordEdit->setEchoMode(QLineEdit::Password);
    ui->confirmPasswordEdit->setEchoMode(QLineEdit::Password);

    //СИГНАЛЫ-СЛОТЫ
    //При нажатии на кнопку "Сохранить" заменяет старый пароль
    //на новый
    connect(ui->saveButton, SIGNAL(clicked()),
            this, SLOT(slotSaveButtonClicked()));
    //При нажатии на кнопку "Отменить" закрывает окно
    //изменения пароля
    connect(ui->rejectButton, SIGNAL(clicked()),
            this, SLOT(reject()));
}

/*Процедура, меняющеая содержимое поля t_pas в БД
Проверяет правильность ввода старого и нового паролей.*/
void ChangePasswordDialog::slotSaveButtonClicked()
{
    //Извлекаем текущий пароль из БД
    if(db.open())
    {
        QSqlQuery query;
        query.exec("SELECT t_pas FROM password");
        if(query.next())
        {
            //Проверяем правильность ввода старого паролья
            if(ui->currentPasswordEdit->text() == query.value(0).toString())
                //Проверяем совпадение нового пароля
                if(ui->newPasswordEdit->text() == ui->confirmPasswordEdit->text())
                {
                    //Меняем пароль в БД
                    query.prepare("UPDATE password "
                                  "SET t_pas = '"+ui->newPasswordEdit->text()+"'");
                    if(query.exec())
                    {
                        Alert(tr("Пароль успешно изменен"));
                        this->accept();
                    }
                    else
                        Alert(tr("Не удалось изменить пароль"));
                }
                else
                    Alert(tr("Пароли не совпадают"));
            else
                Alert(tr("Неверно введен старый пароль"));
        }
        db.close();
    }
    else
        Alert(tr("Не удалось открыть базу данных."));
}

/*Деструктор класса*/
ChangePasswordDialog::~ChangePasswordDialog()
{
    delete ui;
}
