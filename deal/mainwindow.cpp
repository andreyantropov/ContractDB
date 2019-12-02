#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QApplication::setStyle(new QCleanlooksStyle);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251"));

    //���������� ���� ������
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QApplication::applicationDirPath() + "/deal.db");

    //������� ������ ������
    applicationModel = new MySqlQueryModel;
    dealModel = new MySqlQueryModel;

    //��������� ������������ �����
    applicationHeaderList << tr(" ") << tr("������") << tr("�������") << tr("�����������") << tr("���� ����������") << tr("����") << tr("�������") << tr("��� ���������") << tr("����������") << tr("������") << tr("�������������");
    dealHeaderList << tr(" ") << tr("������") << tr("�������") << tr("�����������") << tr("���� ����������") << tr("����") << tr("�������") << tr("�������������");

    //��������� � �������� ������
    slotRefreshFilter();
    slotFilterButtonClicked(false);

    //�������� ������ "��������" � "�������" �� ������������� �������������
    ui->addApplicationButton->hide();
    ui->addDealButton->hide();
    ui->deleteApplicationButton->hide();
    ui->deleteDealButton->hide();

    //��������� �������
    slotUpdateApplicationTable();
    slotUpdateDealTable();

    //�������-�����
    //��� ������� �� ������ "�����������" ��������
    //���������� ���� ��� ����� ������
    connect(ui->loginButton, SIGNAL(clicked()),
            this, SLOT(slotLoginButtonClicked()));
    //��� ������� �� ������ "������� ������" ��������
    //���� ��� ����� ������
    connect(ui->changePasswordButton, SIGNAL(clicked()),
            this, SLOT(slotChangePasswordButtonClicked()));
    //��� ������� �� ������ "������" ��������/����������
    //������ ������
    connect(ui->filterButton, SIGNAL(clicked(bool)),
            this, SLOT(slotFilterButtonClicked(bool)));
    //��� ������� �� ������ ���������� ��������� ��� �
    //��������� ����
    connect(ui->applicationTable, SIGNAL(clicked(QModelIndex)),
            this, SLOT(slotFileOpen()));
    //��� ����� �������� �������� �����-�����, �����������
    //�� ������, ������ ���������� �������
    connect(ui->secCombo, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(slotUpdateApplicationTable()));
    //��� ����� �������� �������� �����-�����, �����������
    //�� ����� ��������, ������ ���������� �������
    connect(ui->dealEdit, SIGNAL(textEdited(QString)),
            this, SLOT(slotUpdateApplicationTable()));
    //��� ����� �������� �������� �����-�����, �����������
    //�� ���� ��������, ������ ���������� �������
    connect(ui->themeCombo, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(slotUpdateApplicationTable()));
    //��� ����� �������� �������� �����-�����, �����������
    //�� ��� ����������, ������ ���������� �������
    connect(ui->typeCombo, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(slotUpdateApplicationTable()));
    //��� ����� �������� �������� �����-�����, �����������
    //�� ������� �����������, ������ ���������� �������
    connect(ui->orgCombo, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(slotUpdateApplicationTable()));
    //��� ����� �������� �������� ���� "��", ������ ���������� �������
    connect(ui->sinceDate, SIGNAL(dateChanged(QDate)),
            this, SLOT(slotUpdateApplicationTable()));
    //��� ����� �������� �������� ���� "�����", ������ ���������� �������
    connect(ui->toDate, SIGNAL(dateChanged(QDate)),
            this, SLOT(slotUpdateApplicationTable()));
    //��� ��������� ����-�����, ����������� �� ���� ����������
    //��������, ������ ���������� �������
    connect(ui->dateGroupBox, SIGNAL(toggled(bool)),
            this, SLOT(slotUpdateApplicationTable()));
    //��� ������� �� ������ "��������" ��������� ����������
    //���� �����-������
    connect(ui->resetButton, SIGNAL(clicked()),
            this, SLOT(slotRefreshFilter()));
    //��� ������� �� ������ "��������" ��������� �����
    //���������� � ������� ����������
    connect(ui->addApplicationButton, SIGNAL(clicked()),
            this, SLOT(slotAddApplicationButtonClicked()));
    //��� ������� �� ������ "��������" ��������� �����
    //������� � ������� ���������
    connect(ui->addDealButton, SIGNAL(clicked()),
            this, SLOT(slotAddDealButtonClicked()));
    //��� ������� �� ������ "�������" ������� ��������� ��������
    //������� ����������
    connect(ui->deleteApplicationButton, SIGNAL(clicked()),
            this, SLOT(slotDeleteApplicationButtonClicked()));
    //��� ������� �� ������ "�������" ������� ��� ���������
    //�������� ������� ���������
    connect(ui->deleteDealButton, SIGNAL(clicked()),
            this, SLOT(slotDeleteDealButtonClicked()));
    //��� ����� �������� ���� "��" �����������, �����
    //����� �������� �� ��������� �������� ���� "�����"
    connect(ui->sinceDate, SIGNAL(dateChanged(QDate)),
            this, SLOT(slotSinceDateChanged(QDate)));
    //��� ����� �������� ���� "�����" �����������, �����
    //����� �������� �� ���� ������ �������� ���� "��"
    connect(ui->toDate, SIGNAL(dateChanged(QDate)),
            this, SLOT(slotToDateChanged(QDate)));
}

/*���������, ����������� �� ���� ���� newDate.
���� ���� newDate ������ �������� �������� ���� toDate
- ������������� � ���� sinceDate �������� toDate*/
void MainWindow::slotSinceDateChanged(QDate newDate)
{
    if(newDate > ui->toDate->date())
    {
        QDate date = ui->toDate->date();
        ui->sinceDate->setDate(date);
    }
}

/*���������, ����������� �� ���� ���� newDate.
���� ���� newDate ������ �������� �������� ���� sinceDate
- ������������� � ���� toDate �������� sinceDate*/
void MainWindow::slotToDateChanged(QDate newDate)
{
    if(newDate < ui->sinceDate->date())
    {
        QDate date = ui->sinceDate->date();
        ui->toDate->setDate(date);
    }
}

/*���������, ����������� �� ���� ���� isHide.
��������/���������� ������ � ����������� �� �������� �����*/
void MainWindow::slotFilterButtonClicked(bool isHide)
{
    if(!isHide)
    {
        //������ ������
        ui->label_9->hide();
        ui->label_10->hide();
        ui->label_11->hide();
        ui->label_12->hide();
        ui->label_13->hide();
        //������ �����������
        ui->line->hide();
        ui->line_2->hide();
        ui->line_3->hide();
        ui->line_4->hide();
        ui->line_5->hide();
        ui->line_6->hide();
        //������ ���������� ����
        ui->orgCombo->hide();
        ui->dealEdit->hide();
        ui->secCombo->hide();
        ui->themeCombo->hide();
        ui->typeCombo->hide();
        //������ ��������
        ui->dateGroupBox->hide();
        //������ ������ "��������"
        ui->resetButton->hide();
        //������������� ������ "������" ���� true
        ui->filterButton->setCheckable(true);
    }
    else
    {
        //���������� ������
        ui->label_9->show();
        ui->label_10->show();
        ui->label_11->show();
        ui->label_12->show();
        ui->label_13->show();
        //���������� �����������
        ui->line->show();
        ui->line_2->show();
        ui->line_3->show();
        ui->line_4->show();
        ui->line_5->show();
        ui->line_6->show();
        //���������� ���������� ����
        ui->orgCombo->show();
        ui->dealEdit->show();
        ui->secCombo->show();
        ui->themeCombo->show();
        ui->typeCombo->show();
        //���������� ��������
        ui->dateGroupBox->show();
        //���������� ������� "��������"
        ui->resetButton->show();
        //������������� ������ "������" ���� false
        ui->filterButton->setCheckable(false);
    }
}

/*���������, ����������� �� ���� ��������� �� ������ model � ������ ���������� headerList.
��������� ��������� �������� ������ model ����������� �� headerList*/
void MainWindow::fillHeaders(QSqlQueryModel *model, QStringList headerList)
{
    for(int i = 0; i < headerList.size(); i++)
        model->setHeaderData(i, Qt::Horizontal, headerList[i]);
}

/*���������, ����������� �� ���� ��������� �� ������� table.
��������� ������ ������� ������� ����������*/
void MainWindow::insertCheckBox(QTableView *table)
{
    for(int i = 0; i < table->model()->rowCount(); i++)
    {
        QCheckBox *checkBox = new QCheckBox;
        ui->user->text().isEmpty() ? checkBox->setEnabled(false) : checkBox->setEnabled(true);
        table->setIndexWidget(table->model()->index(i, 0), checkBox);
    }
}

/*���������, ����������� �� ���� ��������� �� ������� table � ��� ������� (����������/��������) type.
������� ������ �������������� � ��������� ��� ������� table. ����������� ������ � ���������������
�������� ��� ������������ ������, � ������� ���� ������ ������*/
void MainWindow::insertUpdateButtons(QTableView *table, bool type)
{
    for(int i = 0; i < table->model()->rowCount(); i++)
    {
        //������� ������ "�������������"
        QPushButton *button = new QPushButton(tr("�������������"));
        button->setToolTip(tr("������������� ������� �������"));
        //��������� ��, ���� ������������ �� ���������
        ui->user->text().isEmpty() ? button->setEnabled(false) : button->setEnabled(true);
        //��������� ������ � �������
        table->setIndexWidget(table->model()->index(i, table->model()->columnCount() - 1), button);
        if(type)
        {
            //����������� � ������ ������
            QSignalMapper *applicationSignalMapper = new QSignalMapper(this);
            applicationSignalMapper->setMapping(button, i);
            connect(button, SIGNAL(clicked()),
                    applicationSignalMapper, SLOT(map()));
            connect(applicationSignalMapper, SIGNAL(mapped(int)),
                    this, SLOT(slotUpdateApplicationButtonClicked(int)));
        }
        else
        {
            //����������� � ������ ������
            QSignalMapper *dealSignalMapper = new QSignalMapper(this);
            dealSignalMapper->setMapping(button, i);
            connect(button, SIGNAL(clicked()),
                    dealSignalMapper, SLOT(map()));
            connect(dealSignalMapper, SIGNAL(mapped(int)),
                    this, SLOT(slotUpdateDealButtonClicked(int)));
        }
    }
}

/*���������, ����������� �� ���� ��������� �� ������� table, ��������� �� ������ ������� model,
������ � �������� query � ��� ������� (����������/��������) type.
������� ������ model ����� ������ query, ��������� ���������, ��������� �� �������
� ������ � � ����� ������, ��������� �� ���������� � �������� ��� ��������������.
��������� ������ � �������, ������ ������ �������� ��-���������*/
void MainWindow::fillTable(QTableView *table, MySqlQueryModel *model, QString query, QStringList headers, bool type)
{
    model->setQuery(query);
    fillHeaders(model, headers);
    table->setModel(model);
    //��������� ������ ������� ����������
    insertCheckBox(table);
    //��������� ��������� ������� �������� "�������������"
    insertUpdateButtons(table, type);
    //������������� ������ ��������
    setColumnsWidth(table, type);
}

/*���������, ����������� �� ���� ������, ��������� ������������� str.
���� ������ ��������� � ������� �� ��, �� ������������ ��������
tab_1, tab_2, tab_4.
����� - ��������� �� � ������ ��������� � ���, ��� ������ ��������*/
void MainWindow::login(bool isPassword)
{
    if(isPassword)
    {
        ui->user->setText(tr("�������������"));
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
        Alert(tr("�������� ������"));
    }
}

/*�������, ����������� �� ���� ������ �� ������� QTableWidgetItem
���������� ������, ���������� � ���� ��������*/
QString MainWindow::getString(QTableView *table, QModelIndex index)
{
    return table->model()->data(index).toString();
}

/*���������, ����������� �� ���� ������ �� ������� �
�������� - type, ���������� �� ���� ������� (����������/��������)
�������� �� ���� �������� ������� � ������ �� ������ Stretch/ResizeToContents
������������� ������� ������� ������ 18px*/
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

/*���������, ����������� ���� QInputDialog, ���������� ���� ��� ����� ������.
�������� ������� login, ��������� � ��� ��������� ������ ��� �������� �� ������������.
��������� ������� � ������� � ����������� � ���������. ������������ �����������
������ ����������, ������������ �� ������� � ����������� � �����������*/
void MainWindow::slotLoginButtonClicked()
{
    QString str = QInputDialog::getText( 0,
                                         tr("�����������"),
                                         tr("������:"),
                                         QLineEdit::Password, "password");

    //��������� ������ �� ��
    if(db.open())
    {
        QSqlQuery query("SELECT t_pas FROM password");
        db.close();
        //���������� ������ � ��������� �������������
        if(query.next())
        {
            login(str == query.value(0).toString());
            slotUpdateApplicationTable();
            slotUpdateDealTable();
            ui->tabWidget->setCurrentIndex(0);
        }
    }
    else
        Alert(tr("�� ������� ������� ���� ������."));
}

/*���������, ���������� ���� ��������� ������*/
void MainWindow::slotChangePasswordButtonClicked()
{
    ChangePasswordDialog *changePasswordDialog = new ChangePasswordDialog(this);
    changePasswordDialog->exec();
}

/*���������.
������� ������������� ���������� row, �������� ����� ��������� ������. ������� ���
���� � QComboBox'� �� ������� �������������� ����������. ��������� ��
���������������� ������� �� ������� ������.
��������� � ���������� currentLink ������� ������ ��� �������������
���������� ������*/
void MainWindow::slotUpdateApplicationButtonClicked(int row)
{
    ApplicationUpdateDialog *applicationUpdateDialog = new ApplicationUpdateDialog(getString(ui->applicationTable, ui->applicationTable->model()->index(row, 1)),
                                                                                   getString(ui->applicationTable, ui->applicationTable->model()->index(row, 2)),
                                                                                   getString(ui->applicationTable, ui->applicationTable->model()->index(row, 7)),
                                                                                   getString(ui->applicationTable, ui->applicationTable->model()->index(row, 8)),
                                                                                   getString(ui->applicationTable, ui->applicationTable->model()->index(row, 9)),
                                                                                   this);
    //��� �������� ���� ��������� ������� ����������
    connect(applicationUpdateDialog, SIGNAL(accepted()),
            this, SLOT(slotUpdateApplicationTable()));
    applicationUpdateDialog->exec();
}

/*���������.
������� ������������� ���������� row, �������� ����� ��������� ������. �������
��� ���� � QComboBox'� �� ������� �������������� ���������.
��������� �� ���������������� ������� �� ������� ������.
��������� � ���������� currentDealLink ������ �� �����, � �������
�������� ���������� � ��������*/
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
    //��� �������� ���� ��������� ������
    connect(dealUpdateDialog, SIGNAL(accepted()),
            this, SLOT(slotRefreshFilter()));
    //��� �������� ���� ��������� ������ � ������� ���������
    connect(dealUpdateDialog, SIGNAL(accepted()),
            this, SLOT(slotUpdateDealTable()));
    dealUpdateDialog->exec();
}

/*���������, ����������� ������*/
void MainWindow::slotRefreshFilter()
{
    //��������� ���������� ����
    ui->secCombo->fillComboBox("SELECT t_sec "
                               "FROM deal", db);
    ui->themeCombo->fillComboBox("SELECT t_theme "
                                 "FROM doc", db);
    ui->typeCombo->fillComboBox("SELECT t_type "
                                "FROM type", db);
    ui->orgCombo->fillComboBox("SELECT t_org "
                               "FROM org", db);
    //������������� ��������� � ���� ������ ��������
    QCompleter *completer = new QCompleter(getCompleterList("SELECT n_deal "
                                                            "FROM doc"));
    ui->dealEdit->setCompleter(completer);
}

/*�������, ����������� �� ���� ������ qr - ������ � ��.
���������� ���� ����� � ����������� ����������*/
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

/*���������, ��������� ���������� �� ���� ������
������� ���� ��� ������������� ����������
���� ������������ ���������� ��������, �� ��������� ����,
��������������� �� ������, ��������� � �������. ����� ���������
��� ������ �� ����, ��� ������ �� ���������� ��������� � ������� �
�������.
��������� ������� ������ ������ � �����������
������������ �� ���� �������*/
void MainWindow::slotDeleteApplicationButtonClicked()
{
    //�������� ���������� ���� ��� �������������� ��������
    int answer = QMessageBox::question(this,
                 tr("�������������"),
                 tr("�� ������������� ������ ������� ������ ����������"),
                 QMessageBox::Yes | QMessageBox::No);
    if(answer == QMessageBox::Yes)
    {
        for(int i = 0; i < ui->applicationTable->model()->rowCount(); i++)
        {
            QCheckBox *checkBox = qobject_cast<QCheckBox*>(ui->applicationTable->indexWidget(ui->applicationTable->model()->index(i, 0)));
            if(checkBox->isChecked())
            {
                //������� ������ �� ��
                if(db.open())
                {
                    QSqlQuery queryDelete("DELETE FROM app "
                                          "WHERE t_app_link = '"+getString(ui->applicationTable, ui->applicationTable->model()->index(i, 9))+"'");
                    //������� ���� �� �������
                    if(queryDelete.exec())
                    {
                        QApplication::setOverrideCursor(Qt::WaitCursor);
                        QFile(getString(ui->applicationTable, ui->applicationTable->model()->index(i, 9))).remove();
                        QApplication::restoreOverrideCursor();
                    }
                    else
                        Alert(tr("�� ������� ������� ����"));
                    db.close();
                }
                else
                    Alert(tr("�� ������� ������� ���� ������."));
            }
        }
        slotUpdateApplicationTable();
    }
}

/*���������, ��������� �������� �� ���� ������
������ ���� ��� �������������
���� ������������ ���������� ��������, �� ��������� �����, ���������������
������� �������� � ������ �� ���� �������� �� ���� ������ (������ �� ����� ������������)
��������� ������� ������ ������ � ��������� � �����������*/
void MainWindow::slotDeleteDealButtonClicked()
{
    //�������� ���������� ���� ��� �������������� ��������
    int answer = QMessageBox::question(this,
                 tr("�������������"),
                 tr("�� ������������� ������ ������� ������� � ��� ����������, ������� � ���� ���������?"),
                 QMessageBox::Yes | QMessageBox::No);
    if(answer == QMessageBox::Yes)
    {
        for(int i = 0; i < ui->dealTable->model()->rowCount(); i++)
        {
            QCheckBox *checkBox = qobject_cast<QCheckBox*>(ui->dealTable->indexWidget(ui->dealTable->model()->index(i, 0)));
            if(checkBox->isChecked())
            {
                //������� ������ �� ��
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
                    //������� ���������� �� �������
                    if(queryDeleteApp.exec() && queryDeleteDoc.exec() && queryDeleteSec.exec())
                        deleteDir(QApplication::applicationDirPath() + "/deal/deal/"+getString(ui->dealTable, ui->dealTable->model()->index(i, 1))+"/"+getString(ui->dealTable, ui->dealTable->model()->index(i, 2)));
                    else
                        Alert(tr("�� ������� ������� �������"));
                    QApplication::restoreOverrideCursor();
                    db.close();
                }
                else
                    Alert(tr("�� ������� ������� ���� ������."));
            }
        }
        slotRefreshFilter();
        slotUpdateApplicationTable();
        slotUpdateDealTable();
    }
}

/*���������, ���������� ���������� ���� ��� ����������
������ ���������� � ��*/
void MainWindow::slotAddApplicationButtonClicked()
{
    ApplicationDialog *applicationDialog = new ApplicationDialog(this);
    //��� �������� ������� ��������� ������� ����������
    connect(applicationDialog, SIGNAL(accepted()),
            this, SLOT(slotUpdateApplicationTable()));
    applicationDialog->exec();
}

/*���������, ���������� ���������� ���� ��� ���������� ������
�������� � ��*/
void MainWindow::slotAddDealButtonClicked()
{
    DealDialog *dealDialog = new DealDialog(this);
    //��� �������� ������� ��������� ������
    connect(dealDialog, SIGNAL(accepted()),
            this, SLOT(slotRefreshFilter()));
    //��� �������� ������� ��������� ������� ���������
    connect(dealDialog, SIGNAL(accepted()),
            this, SLOT(slotUpdateDealTable()));
    dealDialog->exec();
}

/*��������� ������ ���������� � �����������
������� ���������� � ���� ��������� � ������������ � ���������� ���������
��������� ������ �� �������� � ������� ���������
��������� ������� ���������� �������*/
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
        //��������� ������� � ������������ � ��������
        fillTable(ui->applicationTable, applicationModel, qr, applicationHeaderList, true);
        db.close();
    }
    else
    {
        Alert(tr("�� ������� ������� ���� ������."));
        exit(0);
    }
}

/*��������� ������ ���������� � ���������
������� ����������� ��� ���� ��������� � ������� tableWidget_2*/
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
        Alert(tr("�� ������� ������� ���� ������."));
        exit(0);
    }
}

/*���������, ����������� ����, ��������������� �� ������, �� �������
����� ������������
P.S. ���� ��������� ����������� �����������*/
void MainWindow::slotFileOpen()
{
    if(ui->applicationTable->currentIndex().column() == 9)
    {
        if(QFile(getString(ui->applicationTable, ui->applicationTable->currentIndex())).exists())
            QProcess::startDetached("cmd start /c \""+getString(ui->applicationTable, ui->applicationTable->currentIndex())+"\"");
        else
            Alert(tr("���� ����������� ��� ���������."));
    }
}

/*���������� ������*/
MainWindow::~MainWindow()
{
    delete ui;
}
