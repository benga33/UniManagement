#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QFile>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug() << "Program start";

    // Dobijamo putanju glavnog foldera projekta (gdje se nalazi .exe u build/debug)
    QString dbPath = QCoreApplication::applicationDirPath() + "/university.db";

    // Ako baza ne postoji, kreiraj je
    if (!QFile::exists(dbPath)) {
        qDebug() << "Baza ne postoji, kreiram novu...";
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);

    if (!db.open()) {
        qDebug() << "Greška pri konekciji na bazu:" << db.lastError().text();
        return -1;
    }

    // Kreiraj tabelu ako ne postoji
    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS student ("
                    "id TEXT PRIMARY KEY,"
                    "name TEXT,"
                    "subject TEXT)")) {
        qDebug() << "Greška pri kreiranju tabele:" << query.lastError().text();
        return -1;
    } else {
        qDebug() << "Tabela student je spremna!";
    }

    MainWindow w;
    w.show();

    return a.exec();
}