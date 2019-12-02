#include "MyDirFunctions.h"

/*Процедура, принимающая на вход строку path.
Руккурсивно удаляет содержимое папки, располагающейся
по пути path*/
void deleteDir(QString path)
{
    //Создаем коревую папку
    QDir dir(path);
    //Создаем перечни файлов и папок, содержащихся в корневой папке
    QStringList dirList = dir.entryList(QDir::Dirs);
    QStringList fileList = dir.entryList(QDir::Files);
    //Удаляем файлы
    for(int i = 0; i < fileList.size(); i++)
        QFile(dir.path() + "/" + fileList[i]).remove();
    //Рекуррентно очищаем непустые папки процедурой deleteDir
    //удаляем пустые папки
    for(int i = 2; i < dirList.size(); i++)
        deleteDir(dir.path() + "/" + dirList[i]);
    //Удаляем корневую папку
    dir.rmpath(dir.path());
}

/*Процедура, принимающая на вход два элемента QDir(папка): fromDir и toDir.
Копирует содержимое первой папки во вторую. Реккурсивно удаляет содержимое
первой папки*/
void copyDir(QDir fromDir, QDir toDir, QSqlDatabase db)
{
    //Создаем перечни файлов и папок, содержащихся
    //в папке fromDir
    QStringList dirs = fromDir.entryList(QDir::Dirs);
    QStringList files = fromDir.entryList(QDir::Files);
    for(int i = 0; i < files.size(); i++)
    {
        QFile::copy(fromDir.path() + "/" + files[i], toDir.path() + "/" + files[i]);
        //Меняем содержимое ссылок в БД
        if(db.open())
        {
            QSqlQuery query;
            query.prepare("UPDATE app SET t_app_link = '"+toDir.path() + "/" + files[i]+"' WHERE t_app_link = '"+fromDir.path() + "/" + files[i]+"'");
            query.exec();
            db.close();
            QFile(fromDir.path() + "/" + files[i]).remove();
        }
    }
    //Рекуррентно копируем содержимое папку fromDir в папку toDir
    for(int i = 2; i < dirs.size(); i++)
    {
        toDir.mkpath(dirs[i]);
        copyDir(fromDir.path() + "/" + dirs[i], toDir.path() + "/" + dirs[i], db);
    }
    //Удаляем папку fromDir
    fromDir.rmpath(fromDir.path());
}
