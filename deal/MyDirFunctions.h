#ifndef MYDIRFUNCTIONS_H
#define MYDIRFUNCTIONS_H

#include <QDir>
#include <QFile>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>

void copyDir(QDir fromDir, QDir toDir, QSqlDatabase db); //Процедура копирования папок
void deleteDir(QString path); //Процедура удаления папок

#endif // MYDIRFUNCTIONS_H
