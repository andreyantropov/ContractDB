#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QApplication::setStyle(new QCleanlooksStyle);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251"));

    //Подключаем базу данных
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QApplication::applicationDirPath() + "/deal.db");

    //Создаем модели таблиц
    applicationModel = new MySqlQueryModel;
    dealModel = new MySqlQueryModel;

    //Заполняем заголовочные листы
    applicationHeaderList << tr(" ") << tr("Сектор") << tr("Договор") << tr("Организация") << tr("Дата заключения") << tr("Тема") << tr("Предмет") << tr("Тип документа") << tr("Приложение") << tr("Ссылка") << tr("Редактировать");
    dealHeaderList << tr(" ") << tr("Сектор") << tr("Договор") << tr("Организация") << tr("Дата заключения") << tr("Тема") << tr("Предмет") << tr("Редактировать");

    //Заполняем и скрываем фильтр
    slotRefreshFilter();
    slotFilterButtonClicked(false);

    //Скрываем кнопки "Добавить" и "Удалить" от незалогиненых пользователей
    ui->addApplicationButton->hide();
    ui->addDealButton->hide();
    ui->deleteApplicationButton->hide();
    ui->deleteDealButton->hide();

    //Заполняем таблицы
    slotUpdateApplicationTable();
    slotUpdateDealTable();

    //СИГНАЛЫ-СЛОТЫ
    //При нажатии на кнопку "Авторизация" вызываем
    //диалоголое окно для ввода пароля
    connect(ui->loginButton, SIGNAL(clicked()),
            this, SLOT(slotLoginButtonClicked()));
    //При нажатии на кнопку "Сменить пароль" вызываем
    //окно для смены пароля
    connect(ui->changePasswordButton, SIGNAL(clicked()),
            this, SLOT(slotChangePasswordButtonClicked()));
    //При нажатии на кнопку "Фильтр" скрывает/показывает
    //фильтр данных
    connect(ui->filterButton, SIGNAL(clicked(bool)),
            this, SLOT(slotFilterButtonClicked(bool)));
    //При нажатии на ссылку приложения открывает его в
    //отдельном окне
    connect(ui->applicationTable, SIGNAL(clicked(QModelIndex)),
            this, SLOT(slotFileOpen()));
    //При смене текущего значения комбо-бокса, отвечающего
    //за сектор, меняем содержимое таблицы
    connect(ui->secCombo, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(slotUpdateApplicationTable()));
    //При смене текущего значения комбо-бокса, отвечающего
    //за номер договора, меняем содержимое таблицы
    connect(ui->dealEdit, SIGNAL(textEdited(QString)),
            this, SLOT(slotUpdateApplicationTable()));
    //При смене текущего значения комбо-бокса, отвечающего
    //за тему договора, меняем содержимое таблицы
    connect(ui->themeCombo, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(slotUpdateApplicationTable()));
    //При смене текущего значения комбо-бокса, отвечающего
    //за тип приложения, меняем содержимое таблицы
    connect(ui->typeCombo, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(slotUpdateApplicationTable()));
    //При смене текущего значения комбо-бокса, отвечающего
    //за смежную организацию, меняем содержимое таблицы
    connect(ui->orgCombo, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(slotUpdateApplicationTable()));
    //При смене текущего значения поля "До", меняем содержимое таблицы
    connect(ui->sinceDate, SIGNAL(dateChanged(QDate)),
            this, SLOT(slotUpdateApplicationTable()));
    //При смене текущего значения поля "После", меняем содержимое таблицы
    connect(ui->toDate, SIGNAL(dateChanged(QDate)),
            this, SLOT(slotUpdateApplicationTable()));
    //При активации груп-бокса, отвечающего за даты заключения
    //договора, меняем содержимое таблицы
    connect(ui->dateGroupBox, SIGNAL(toggled(bool)),
            this, SLOT(slotUpdateApplicationTable()));
    //При нажатии на кнопку "Очистить" обновляет содержимое
    //всех комбо-боксов
    connect(ui->resetButton, SIGNAL(clicked()),
            this, SLOT(slotRefreshFilter()));
    //При нажатии на кнопку "Добавить" добавляет новое
    //приложение в таблицу приложений
    connect(ui->addApplicationButton, SIGNAL(clicked()),
            this, SLOT(slotAddApplicationButtonClicked()));
    //При нажатии на кнопку "Добавить" добавляет новый
    //договор в таблицу договоров
    connect(ui->addDealButton, SIGNAL(clicked()),
            this, SLOT(slotAddDealButtonClicked()));
    //При нажатии на кнопку "Удалить" удаляет выбранные элементы
    //таблицы приложений
    connect(ui->deleteApplicationButton, SIGNAL(clicked()),
            this, SLOT(slotDeleteApplicationButtonClicked()));
    //При нажатии на кнопку "Удалить" удаляет все выбранные
    //элементы таблицы договоров
    connect(ui->deleteDealButton, SIGNAL(clicked()),
            this, SLOT(slotDeleteDealButtonClicked()));
    //При смене значения поля "До" отслеживает, чтобы
    //новое значение не превышало значение поля "После"
    connect(ui->sinceDate, SIGNAL(dateChanged(QDate)),
            this, SLOT(slotSinceDateChanged(QDate)));
    //При смене значения поля "После" отслеживает, чтобы
    //новое значение не юыдл меньше значения поля "До"
    connect(ui->toDate, SIGNAL(dateChanged(QDate)),
            this, SLOT(slotToDateChanged(QDate)));
}

/*Процедура, принимающая на ходе дату newDate.
Если дата newDate больше текущего значения поля toDate
- устанавливает в поле sinceDate значение toDate*/
void MainWindow::slotSinceDateChanged(QDate newDate)
{
    if(newDate > ui->toDate->date())
    {
        QDate date = ui->toDate->date();
        ui->sinceDate->setDate(date);
    }
}

/*Процедура, принимающая на ходе дату newDate.
Если дата newDate меньше текущего значения поля sinceDate
- устанавливает в поле toDate значение sinceDate*/
void MainWindow::slotToDateChanged(QDate newDate)
{
    if(newDate < ui->sinceDate->date())
    {
        QDate date = ui->sinceDate->date();
        ui->toDate->setDate(date);
    }
}

/*Процедура, принимающая на вход флаг isHide.
Скрывает/показывает фильтр в зависимости от значений флага*/
void MainWindow::slotFilterButtonClicked(bool isHide)
{
    if(!isHide)
    {
        //Прячем лейблы
        ui->label_9->hide();
        ui->label_10->hide();
        ui->label_11->hide();
        ui->label_12->hide();
        ui->label_13->hide();
        //Прячем разделители
        ui->line->hide();
        ui->line_2->hide();
        ui->line_3->hide();
        ui->line_4->hide();
        ui->line_5->hide();
        ui->line_6->hide();
        //Прячем выпадающие меню
        ui->orgCombo->hide();
        ui->dealEdit->hide();
        ui->secCombo->hide();
        ui->themeCombo->hide();
        ui->typeCombo->hide();
        //Прячем групбокс
        ui->dateGroupBox->hide();
        //Прячем кнопку "Очистить"
        ui->resetButton->hide();
        //Устанавливаем кнопке "Фильтр" флаг true
        ui->filterButton->setCheckable(true);
    }
    else
    {
        //Показываем лейблы
        ui->label_9->show();
        ui->label_10->show();
        ui->label_11->show();
        ui->label_12->show();
        ui->label_13->show();
        //Показываем разделители
        ui->line->show();
        ui->line_2->show();
        ui->line_3->show();
        ui->line_4->show();
        ui->line_5->show();
        ui->line_6->show();
        //Показываем выпадающие меню
        ui->orgCombo->show();
        ui->dealEdit->show();
        ui->secCombo->show();
        ui->themeCombo->show();
        ui->typeCombo->show();
        //Показываем групбокс
        ui->dateGroupBox->show();
        //Показываем окнопку "Очистить"
        ui->resetButton->show();
        //Устанавливаем кнопке "Фильтр" флаг false
        ui->filterButton->setCheckable(false);
    }
}

/*Процедура, принимающая на вход указатель на модель model и список заголовков headerList.
Заполняет заголовки столбцов модели model заголовками из headerList*/
void MainWindow::fillHeaders(QSqlQueryModel *model, QStringList headerList)
{
    for(int i = 0; i < headerList.size(); i++)
        model->setHeaderData(i, Qt::Horizontal, headerList[i]);
}

/*Процедура, принимающая на вход указатель на таблицу table.
Заполняет первый столбец таблицы чекбоксами*/
void MainWindow::insertCheckBox(QTableView *table)
{
    for(int i = 0; i < table->model()->rowCount(); i++)
    {
        QCheckBox *checkBox = new QCheckBox;
        ui->user->text().isEmpty() ? checkBox->setEnabled(false) : checkBox->setEnabled(true);
        table->setIndexWidget(table->model()->index(i, 0), checkBox);
    }
}

/*Процедура, принимающая на вход указатель на таблицу table и тип таблицы (приложения/договора) type.
Создает кнопки редактирования и заполняет ими таблицу table. Привязывает кнопки к соответствующим
мапперам для отслеживания строки, в которой была нажата кнопка*/
void MainWindow::insertUpdateButtons(QTableView *table, bool type)
{
    for(int i = 0; i < table->model()->rowCount(); i++)
    {
        //Создаем кнопку "Редактировать"
        QPushButton *button = new QPushButton(tr("Редактировать"));
        button->setToolTip(tr("Редактировать такущий элемент"));
        //Блокируем ее, если пользователь не залогинен
        ui->user->text().isEmpty() ? button->setEnabled(false) : button->setEnabled(true);
        //Добавляем кнопку в таблицу
        table->setIndexWidget(table->model()->index(i, table->model()->columnCount() - 1), button);
        if(type)
        {
            //Привязываем к кнопке маппер
            QSignalMapper *applicationSignalMapper = new QSignalMapper(this);
            applicationSignalMapper->setMapping(button, i);
            connect(button, SIGNAL(clicked()),
                    applicationSignalMapper, SLOT(map()));
            connect(applicationSignalMapper, SIGNAL(mapped(int)),
                    this, SLOT(slotUpdateApplicationButtonClicked(int)));
        }
        else
        {
            //Привязываем к кнопке маппер
            QSignalMapper *dealSignalMapper = new QSignalMapper(this);
            dealSignalMapper->setMapping(button, i);
            connect(button, SIGNAL(clicked()),
                    dealSignalMapper, SLOT(map()));
            connect(dealSignalMapper, SIGNAL(mapped(int)),
                    this, SLOT(slotUpdateDealButtonClicked(int)));
        }
    }
}

/*Процедура, принимающая на вход указатель на таблицу table, указатель на модель таблицы model,
строку с запросом query и тип таблицы (приложения/договора) type.
Создает модель model через запрос query, заполняет заголовки, добавляет по столбцу
в начало и в конец модели, заполняет их чекбоксами и кнопками для редактирования.
Добавляет модель в таблицу, задает размер столбцов по-умолчанию*/
void MainWindow::fillTable(QTableView *table, MySqlQueryModel *model, QString query, QStringList headers, bool type)
{
    model->setQuery(query);
    fillHeaders(model, headers);
    table->setModel(model);
    //Заполняем первый столбец чекбоксами
    insertCheckBox(table);
    //Заполняем последний столбец кнопками "Редактировать"
    insertUpdateButtons(table, type);
    //Устанавливаем ширину столбцов
    setColumnsWidth(table, type);
}

/*Процедура, принимающая на вход строку, введенную пользователем str.
Если строка совпадает с паролем из БД, то разблокирует элементы
tab_1, tab_2, tab_4.
Иначе - блокирует их и выдает сообщение о том, что пароль неверный*/
void MainWindow::login(bool isPassword)
{
    if(isPassword)
    {
        ui->user->setText(tr("Администратор"));
        ui->addApplicationButton->show();
        ui->addDealButton->show();
        ui->deleteApplicationButton->show();
        ui->deleteDealButton->show();
    }
    else
    {
        ui->user->setText("");
        ui->addApplicationButton->hide();
        ui->addDealButton->hide();
        ui->deleteApplicationButton->hide();
        ui->deleteDealButton->hide();
        Alert(tr("Неверный пароль"));
    }
}

/*Функция, принимающая на вход ссылку на элемент QTableWidgetItem
Возвращает строку, хранящуюся в этом элементе*/
QString MainWindow::getString(QTableView *table, QModelIndex index)
{
    return table->model()->data(index).toString();
}

/*Процедура, принимающая на вход ссылку на таблицу и
флаговую - type, отвечающую за типа таблицы (приложения/договора)
Проходит по всем столбцам таблицы и задает им ширину Stretch/ResizeToContents
Устанавливает первому столбцу ширину 18px*/
void MainWindow::setColumnsWidth(QTableView *table, bool type)
{
    table->setColumnWidth(0, 18);
    if(type)
        for(int i = 1; i < table->model()->columnCount(); i++)
            table->horizontalHeader()->setResizeMode(i, QHeaderView::ResizeToContents);
    else
    {
        for(int i = 1; i < table->model()->columnCount(); i++)
            table->horizontalHeader()->setResizeMode(i, QHeaderView::ResizeToContents);
    }
}

/*Процедура, открывающая окно QInputDialog, содержащее поле для ввода пароля.
Вызывает функцию login, передавая в нее введенный пароль для проверки на правильность.
Обновляет таблицы с данными о приложениях и договорах. Перекидывает настранницу
вывода информации, фокусируется на таблице с информацией о приложениях*/
void MainWindow::slotLoginButtonClicked()
{
    QString str = QInputDialog::getText( 0,
                                         tr("Авторизация"),
                                         tr("Пароль:"),
                                         QLineEdit::Password, "password");

    //Извлекаем пароль из БД
    if(db.open())
    {
        QSqlQuery query("SELECT t_pas FROM password");
        db.close();
        //Сравниваем пароль с введенным пользователем
        if(query.next())
        {
            login(str == query.value(0).toString());
            slotUpdateApplicationTable();
            slotUpdateDealTable();
            ui->tabWidget->setCurrentIndex(0);
        }
    }
    else
        Alert(tr("Не удалось открыть базу данных."));
}

/*Процедура, вызывающая окно изменения пароля*/
void MainWindow::slotChangePasswordButtonClicked()
{
    ChangePasswordDialog *changePasswordDialog = new ChangePasswordDialog(this);
    changePasswordDialog->exec();
}

/*Процедура.
Создает целочисленную переменную row, хранящую номер выбранной строки. Очищает все
поля и QComboBox'ы на вкладке редактирования приложений. Заполняет их
соответствующими данными из текущей строки.
Сохраняет в переменную currentLink текущую строку для идентефикации
изменяемой строки*/
void MainWindow::slotUpdateApplicationButtonClicked(int row)
{
    ApplicationUpdateDialog *applicationUpdateDialog = new ApplicationUpdateDialog(getString(ui->applicationTable, ui->applicationTable->model()->index(row, 1)),
                                                                                   getString(ui->applicationTable, ui->applicationTable->model()->index(row, 2)),
                                                                                   getString(ui->applicationTable, ui->applicationTable->model()->index(row, 7)),
                                                                                   getString(ui->applicationTable, ui->applicationTable->model()->index(row, 8)),
                                                                                   getString(ui->applicationTable, ui->applicationTable->model()->index(row, 9)),
                                                                                   this);
    //При закрытии окна обновляем таблицу приложений
    connect(applicationUpdateDialog, SIGNAL(accepted()),
            this, SLOT(slotUpdateApplicationTable()));
    applicationUpdateDialog->exec();
}

/*Процедура.
Создает целочисленную переменную row, хранящую номер выбранной строки. Очищает
все поля и QComboBox'ы на вкладке редактирования договоров.
Заполняет их соответствующими данными из текущей строки.
Сохраняет в переменную currentDealLink ссылку на папку, в которой
хранятся приложения к договору*/
void MainWindow::slotUpdateDealButtonClicked(int row)
{
    DealUpdateDialog *dealUpdateDialog = new DealUpdateDialog(getString(ui->dealTable, ui->dealTable->model()->index(row, 1)),
                                                              getString(ui->dealTable, ui->dealTable->model()->index(row, 2)),
                                                              getString(ui->dealTable, ui->dealTable->model()->index(row, 3)),
                                                              getString(ui->dealTable, ui->dealTable->model()->index(row, 5)),
                                                              getString(ui->dealTable, ui->dealTable->model()->index(row, 6)),
                                                              getString(ui->dealTable, ui->dealTable->model()->index(row, 4)),
                                                              QApplication::applicationDirPath() + "/deal/deal/"+getString(ui->dealTable, ui->dealTable->model()->index(row, 1))+"/"+getString(ui->dealTable, ui->dealTable->model()->index(row, 2)),
                                                              this);
    //При закрытии окна обновляем фильтр
    connect(dealUpdateDialog, SIGNAL(accepted()),
            this, SLOT(slotRefreshFilter()));
    //При закрытии окна обновляем данные в таблице договоров
    connect(dealUpdateDialog, SIGNAL(accepted()),
            this, SLOT(slotUpdateDealTable()));
    dealUpdateDialog->exec();
}

/*Процедура, обновляющая фильтр*/
void MainWindow::slotRefreshFilter()
{
    //Заполняем выпадающие меню
    ui->secCombo->fillComboBox("SELECT t_sec "
                               "FROM deal", db);
    ui->themeCombo->fillComboBox("SELECT t_theme "
                                 "FROM doc", db);
    ui->typeCombo->fillComboBox("SELECT t_type "
                                "FROM type", db);
    ui->orgCombo->fillComboBox("SELECT t_org "
                               "FROM org", db);
    //Устанавливаем комплитер к полю выбора договора
    QCompleter *completer = new QCompleter(getCompleterList("SELECT n_deal "
                                                            "FROM doc"));
    ui->dealEdit->setCompleter(completer);
}

/*Функция, принимающая на вход строку qr - запрос в БД.
Возвращает лист строк с полученными значениями*/
QStringList MainWindow::getCompleterList(QString qr)
{
    QStringList completerList;
    if(db.open())
    {
        QSqlQuery query(qr);
        while(query.next())
            completerList << query.value(0).toString();
        db.close();
    }
    return completerList;
}

/*Процедура, удаляющая проложения из базы данных
Выводит окно для подтверждения информации
Если пользователь подтвердил удаление, то удаляется файл,
располагающийся по ссылке, указанной в таблице. Затем удаляются
все данные из базы, где ссылка на приложение совпадает с ссылкой в
таблице.
Обновляет таблицу вывода данных о приложениях
Фокусируется на этой таблице*/
void MainWindow::slotDeleteApplicationButtonClicked()
{
    //Вызываем диалоговое окно для поддтверждения удаления
    int answer = QMessageBox::question(this,
                 tr("Подтверждение"),
                 tr("Вы действительно хотите удалить данное приложение"),
                 QMessageBox::Yes | QMessageBox::No);
    if(answer == QMessageBox::Yes)
    {
        for(int i = 0; i < ui->applicationTable->model()->rowCount(); i++)
        {
            QCheckBox *checkBox = qobject_cast<QCheckBox*>(ui->applicationTable->indexWidget(ui->applicationTable->model()->index(i, 0)));
            if(checkBox->isChecked())
            {
                //Удаляем данные из БД
                if(db.open())
                {
                    QSqlQuery queryDelete("DELETE FROM app "
                                          "WHERE t_app_link = '"+getString(ui->applicationTable, ui->applicationTable->model()->index(i, 9))+"'");
                    //Удаляем файл из системы
                    if(queryDelete.exec())
                    {
                        QApplication::setOverrideCursor(Qt::WaitCursor);
                        QFile(getString(ui->applicationTable, ui->applicationTable->model()->index(i, 9))).remove();
                        QApplication::restoreOverrideCursor();
                    }
                    else
                        Alert(tr("Не удалось удалить файл"));
                    db.close();
                }
                else
                    Alert(tr("Не удалось открыть базу данных."));
            }
        }
        slotUpdateApplicationTable();
    }
}

/*Процедура, удаляющая договоры из базы данных
Выдает окно для подтверждения
Если пользователь подтвердил удаление, то удаляется папка, соответствующая
данному договору и данные об этом договоре из базы данных (вместе со всеми приложениями)
Обновляет таблицы вывода данных о договорах и приложениях*/
void MainWindow::slotDeleteDealButtonClicked()
{
    //Вызываем диалоговое окно для поддтверждения удаления
    int answer = QMessageBox::question(this,
                 tr("Подтверждение"),
                 tr("Вы действительно хотите удалить договор и все приложения, которые к нему относятся?"),
                 QMessageBox::Yes | QMessageBox::No);
    if(answer == QMessageBox::Yes)
    {
        for(int i = 0; i < ui->dealTable->model()->rowCount(); i++)
        {
            QCheckBox *checkBox = qobject_cast<QCheckBox*>(ui->dealTable->indexWidget(ui->dealTable->model()->index(i, 0)));
            if(checkBox->isChecked())
            {
                //Удаляем данные из БД
                if(db.open())
                {
                    QApplication::setOverrideCursor(Qt::WaitCursor);
                    QSqlQuery queryDeleteApp, queryDeleteSec, queryDeleteDoc;
                    queryDeleteApp.prepare("DELETE FROM app "
                                           "WHERE n_deal = '"+getString(ui->dealTable, ui->dealTable->model()->index(i, 2))+"'");
                    queryDeleteDoc.prepare("DELETE FROM doc "
                                           "WHERE n_deal = '"+getString(ui->dealTable, ui->dealTable->model()->index(i, 2))+"'");
                    queryDeleteSec.prepare("DELETE FROM sec "
                                           "WHERE n_deal = '"+getString(ui->dealTable, ui->dealTable->model()->index(i, 2))+"'");
                    //Удаляем директорию из системы
                    if(queryDeleteApp.exec() && queryDeleteDoc.exec() && queryDeleteSec.exec())
                        deleteDir(QApplication::applicationDirPath() + "/deal/deal/"+getString(ui->dealTable, ui->dealTable->model()->index(i, 1))+"/"+getString(ui->dealTable, ui->dealTable->model()->index(i, 2)));
                    else
                        Alert(tr("Не удалось удалить договор"));
                    QApplication::restoreOverrideCursor();
                    db.close();
                }
                else
                    Alert(tr("Не удалось открыть базу данных."));
            }
        }
        slotRefreshFilter();
        slotUpdateApplicationTable();
        slotUpdateDealTable();
    }
}

/*Процедура, вызывающая диалоговое окно для добавления
нового приложения в БД*/
void MainWindow::slotAddApplicationButtonClicked()
{
    ApplicationDialog *applicationDialog = new ApplicationDialog(this);
    //При закрытии диалога обновляем таблицу приложений
    connect(applicationDialog, SIGNAL(accepted()),
            this, SLOT(slotUpdateApplicationTable()));
    applicationDialog->exec();
}

/*Процедура, вызывающая диалоговое окно для добавления нового
договора в БД*/
void MainWindow::slotAddDealButtonClicked()
{
    DealDialog *dealDialog = new DealDialog(this);
    //При закрытии диалога обновляем фильтр
    connect(dealDialog, SIGNAL(accepted()),
            this, SLOT(slotRefreshFilter()));
    //При закрытии диалога обновляем таблицу договоров
    connect(dealDialog, SIGNAL(accepted()),
            this, SLOT(slotUpdateDealTable()));
    dealDialog->exec();
}

/*Процедура вывода информации о приложениях
Выводит информацию о всех договорах в соответствии с выбранными фильтрами
Сортирует данные по секторам и номерам договорам
Заполняет таблицу выбранными данными*/
void MainWindow::slotUpdateApplicationTable()
{
    if(db.open())
    {
        QString qr = "SELECT t_sec, doc.n_deal, t_org, strftime('%d.%m.%Y', d_date), t_theme, t_item, t_type, t_app, t_app_link "
                     "FROM deal, sec, doc, app, type, org "
                     "WHERE deal.n_sec = sec.n_sec "
                     "AND sec.n_deal = doc.n_deal "
                     "AND doc.n_deal = app.n_deal "
                     "AND app.n_type = type.n_type "
                     "AND doc.n_org = org.n_org";
        if(ui->secCombo->currentText() != "-")
            qr += " AND t_sec = '"+ui->secCombo->currentText()+"'";
        if(!ui->dealEdit->text().isEmpty())
            qr += " AND doc.n_deal LIKE '%"+ui->dealEdit->text()+"%'";
        if(ui->themeCombo->currentText() != "-")
            qr += " AND t_theme = '"+ui->themeCombo->currentText()+"'";
        if(ui->typeCombo->currentText() != "-")
            qr += " AND t_type = '"+ui->typeCombo->currentText()+"'";
        if(ui->orgCombo->currentText() != "-")
            qr += " AND t_org = '"+ui->orgCombo->currentText()+"'";
        if(ui->dateGroupBox->isChecked())
            qr += " AND d_date > '"+ui->sinceDate->dateToDB()+"'"
                  " AND d_date < '"+ui->toDate->dateToDB()+"'";
        qr += " ORDER BY t_sec, doc.n_deal ASC";
        //Заполняем таблицу в соответствии с запросом
        fillTable(ui->applicationTable, applicationModel, qr, applicationHeaderList, true);
        db.close();
    }
    else
    {
        Alert(tr("Не удалось открыть базу данных."));
        exit(0);
    }
}

/*Процедура вывода информации о договорах
Выводит информациюю обо ВСЕХ договорах в таблицу tableWidget_2*/
void MainWindow::slotUpdateDealTable()
{
    if(db.open())
    {
        QString qr = "SELECT t_sec, doc.n_deal, t_org, strftime('%d.%m.%Y', d_date), t_theme, t_item "
                     "FROM deal, sec, doc, org "
                     "WHERE deal.n_sec = sec.n_sec "
                     "AND sec.n_deal = doc.n_deal "
                     "AND doc.n_org = org.n_org";
        qr += " ORDER BY t_sec, doc.n_deal ASC";
        QSqlQuery query;
        query.exec(qr);
        fillTable(ui->dealTable, dealModel, qr, dealHeaderList, false);
        db.close();
    }
    else
    {
        Alert(tr("Не удалось открыть базу данных."));
        exit(0);
    }
}

/*Процедура, открывающая файл, располагающийся по ссылке, на которую
нажал пользователь
P.S. файл откроется стандартным приложением*/
void MainWindow::slotFileOpen()
{
    if(ui->applicationTable->currentIndex().column() == 9)
    {
        if(QFile(getString(ui->applicationTable, ui->applicationTable->currentIndex())).exists())
            QProcess::startDetached("cmd start /c \""+getString(ui->applicationTable, ui->applicationTable->currentIndex())+"\"");
        else
            Alert(tr("Файл отсутствует или поврежден."));
    }
}

/*Деструктор класса*/
MainWindow::~MainWindow()
{
    delete ui;
}
