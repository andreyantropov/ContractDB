#include "MyDirFunctions.h"

/*���������, ����������� �� ���� ������ path.
����������� ������� ���������� �����, ���������������
�� ���� path*/
void deleteDir(QString path)
{
    //������� ������� �����
    QDir dir(path);
    //������� ������� ������ � �����, ������������ � �������� �����
    QStringList dirList = dir.entryList(QDir::Dirs);
    QStringList fileList = dir.entryList(QDir::Files);
    //������� �����
    for(int i = 0; i < fileList.size(); i++)
        QFile(dir.path() + "/" + fileList[i]).remove();
    //����������� ������� �������� ����� ���������� deleteDir
    //������� ������ �����
    for(int i = 2; i < dirList.size(); i++)
        deleteDir(dir.path() + "/" + dirList[i]);
    //������� �������� �����
    dir.rmpath(dir.path());
}

/*���������, ����������� �� ���� ��� �������� QDir(�����): fromDir � toDir.
�������� ���������� ������ ����� �� ������. ����������� ������� ����������
������ �����*/
void copyDir(QDir fromDir, QDir toDir, QSqlDatabase db)
{
    //������� ������� ������ � �����, ������������
    //� ����� fromDir
    QStringList dirs = fromDir.entryList(QDir::Dirs);
    QStringList files = fromDir.entryList(QDir::Files);
    for(int i = 0; i < files.size(); i++)
    {
        QFile::copy(fromDir.path() + "/" + files[i], toDir.path() + "/" + files[i]);
        //������ ���������� ������ � ��
        if(db.open())
        {
            QSqlQuery query;
            query.prepare("UPDATE app SET t_app_link = '"+toDir.path() + "/" + files[i]+"' WHERE t_app_link = '"+fromDir.path() + "/" + files[i]+"'");
            query.exec();
            db.close();
            QFile(fromDir.path() + "/" + files[i]).remove();
        }
    }
    //����������� �������� ���������� ����� fromDir � ����� toDir
    for(int i = 2; i < dirs.size(); i++)
    {
        toDir.mkpath(dirs[i]);
        copyDir(fromDir.path() + "/" + dirs[i], toDir.path() + "/" + dirs[i], db);
    }
    //������� ����� fromDir
    fromDir.rmpath(fromDir.path());
}
