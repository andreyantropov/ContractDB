#ifndef MYDIRFUNCTIONS_H
#define MYDIRFUNCTIONS_H

#include <QDir>
#include <QFile>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>

void copyDir(QDir fromDir, QDir toDir, QSqlDatabase db); //��������� ����������� �����
void deleteDir(QString path); //��������� �������� �����

#endif // MYDIRFUNCTIONS_H
