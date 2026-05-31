#include "DatabaseManager.h"

#include <QSqlError>
#include <QCoreApplication>
#include <QDebug>
#include <iostream>

QSqlDatabase DatabaseManager::database;

bool DatabaseManager::connect()
{
    // Create SQLite connection ONCE
    if (!QSqlDatabase::contains("main_connection"))
    {
        database = QSqlDatabase::addDatabase("QSQLITE", "main_connection");
    }
    else
    {
        database = QSqlDatabase::database("main_connection");
    }

    // FULL PATH to database file
    QString dbPath =
        QCoreApplication::applicationDirPath()
        + "/school_management.db";

    database.setDatabaseName(dbPath);

    // qDebug() << "DB PATH:" << dbPath;
    // qDebug() << "Available drivers:" << QSqlDatabase::drivers();

    if (database.open())
    {
        std::cout << "DATABASE CONNECTED SUCCESSFULLY!" << std::endl;
        return true;
    }
    else
    {
        std::cout << "DATABASE CONNECTION FAILED!" << std::endl;
        std::cout << database.lastError().text().toStdString() << std::endl;
        return false;
    }
}

QSqlDatabase DatabaseManager::getDatabase()
{
    return database;
}