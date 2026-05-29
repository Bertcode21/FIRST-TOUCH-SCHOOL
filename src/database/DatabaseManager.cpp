#include "DatabaseManager.h"

#include <QSettings>
#include <QSqlError>
#include <QMessageBox>

#include <QDebug>
#include <iostream>

QSqlDatabase DatabaseManager::database;

bool DatabaseManager::connect()
{
    QSettings settings("config/config.ini", QSettings::IniFormat);

    QString dbName = settings.value("database/name").toString();

    // 🔥 SQLite connection ONLY
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(dbName);

    std::cout << "==============================" << std::endl;
    std::cout << "DATABASE CONFIGURATION" << std::endl;
    std::cout << "DATABASE FILE: " << dbName.toStdString() << std::endl;
    std::cout << "==============================" << std::endl;

    // Optional debug
    qDebug() << "Available drivers:" << QSqlDatabase::drivers();
    QString dbName = settings.value("database/name").toString();
    database.setDatabaseName(dbName);

    if (database.open())
    {
        std::cout << "DATABASE CONNECTED SUCCESSFULLY!" << std::endl;

        QMessageBox successBox;
        successBox.setWindowTitle("Database Status");
        successBox.setText("Database Connected Successfully!");
        successBox.exec();
       qDebug() << settings.fileName();
       qDebug() << "DB NAME:" << dbName;
        return true;
    }
    else
    {
        std::cout << "DATABASE CONNECTION FAILED!" << std::endl;
        std::cout << database.lastError().text().toStdString() << std::endl;

        QMessageBox errorBox;
        errorBox.setWindowTitle("Database Status");
        errorBox.setText("Database Connection Failed!");
        errorBox.exec();

        return false;
    }
}