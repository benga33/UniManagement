#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addbox.h"
#include "findbox.h"
#include "updatebox.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , addbox(new addBox(this))
    , findbox(new findBox(this))
    , updatebox(new updateBox(this))
{
    ui->setupUi(this);

    // Povezivanje dugmadi
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::addFun);
    connect(addbox, &addBox::enterInfo, this, &MainWindow::getInfo);

    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::searchFun);
    connect(findbox, &findBox::onSearch, this, &MainWindow::onFind);

    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::updateFun);
    connect(updatebox, &updateBox::newSub, this, &MainWindow::onUpdate);

    // Kreiranje tabele ako ne postoji
    QSqlQuery query;
    if(!query.exec("CREATE TABLE IF NOT EXISTS student (id TEXT PRIMARY KEY, name TEXT, subject TEXT)")) {
        qDebug() << "Greška pri kreiranju tabele:" << query.lastError().text();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete addbox;
    delete findbox;
    delete updatebox;
}

// Otvara prozor za dodavanje studenta
void MainWindow::addFun()
{
    addbox->show();
}

// Dodaje studenta u bazu
void MainWindow::getInfo(const QString &rn, const QString &n, const QString &s)
{
    QSqlQuery query;
    query.prepare("INSERT OR REPLACE INTO student (id, name, subject) VALUES (?, ?, ?)");
    query.addBindValue(rn);
    query.addBindValue(n);
    query.addBindValue(s);

    if(!query.exec()) {
        QMessageBox::warning(this, "Error", "Greška pri unosu: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Success", "Student Added/Updated Successfully!");
    }
}

// Otvara prozor za pretragu studenta
void MainWindow::searchFun()
{
    findbox->show();
}

// Pretražuje studenta po ID
void MainWindow::onFind(const QString &rn)
{
    QSqlQuery query;
    query.prepare("SELECT name, subject FROM student WHERE id = ?");
    query.addBindValue(rn);

    if(!query.exec()) {
        QMessageBox::warning(this, "Error", "Greška pri pretrazi: " + query.lastError().text());
        return;
    }

    if(query.next()) {
        QString name = query.value(0).toString();
        QString subject = query.value(1).toString();
        QMessageBox::information(this, "Success", "RollNo: " + rn + "\nName: " + name + "\nSubject: " + subject);
    } else {
        QMessageBox::information(this, "Error", "Student not found!");
    }
}

// Otvara prozor za update studenta
void MainWindow::updateFun()
{
    updatebox->show();
}

// Ažurira predmet studenta po ID
void MainWindow::onUpdate(const QString &rn, const QString &s)
{
    QSqlQuery query;
    query.prepare("UPDATE student SET subject = ? WHERE id = ?");
    query.addBindValue(s);
    query.addBindValue(rn);

    if(!query.exec()) {
        QMessageBox::warning(this, "Error", "Greška pri update-u: " + query.lastError().text());
        return;
    }

    if(query.numRowsAffected() > 0) {
        QMessageBox::information(this, "Success", "Subject updated successfully!");
    } else {
        QMessageBox::information(this, "Error", "Student not found!");
    }
}