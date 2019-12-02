#include "mysqlquerymodel.h"

MySqlQueryModel::MySqlQueryModel(QObject *parent) :
    QSqlQueryModel(parent)
{
}

void MySqlQueryModel::setQuery(const QSqlQuery &query)
{
    QSqlQueryModel::setQuery(query);
    this->insertColumn(0);
    this->insertColumn(this->columnCount());
}


