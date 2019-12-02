#ifndef MYSQLQUERYMODEL_H
#define MYSQLQUERYMODEL_H

#include <QSqlQueryModel>

class MySqlQueryModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit MySqlQueryModel(QObject *parent = 0);

    void setQuery(const QSqlQuery &query);
    
signals:
    
public slots:
    
};

#endif // MYSQLQUERYMODEL_H
