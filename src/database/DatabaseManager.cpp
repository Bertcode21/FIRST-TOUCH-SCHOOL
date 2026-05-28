
#include "DatabaseManager.h"

#include <QSettings>
#include <QSqlError>

#include <QMessageBox>

#include <iostream>

QSqlDatabase DatabaseManager::database;

bool DatabaseManager::connect()
{
    QSettings settings("config/config.ini", QSettings::IniFormat);

    QString host = settings.value("database/host").toString();
    int port = settings.value("database/port").toInt();

    QString dbName = settings.value("database/name").toString();
    QString username = settings.value("database/user").toString();
    QString password = settings.value("database/password").toString();

  database = QSqlDatabase::addDatabase("QSQLITE");

    database.setHostName(host);
    database.setPort(port);

    database.setDatabaseName(dbName);

    database.setUserName(username);
    database.setPassword(password);

    std::cout << "==============================" << std::endl;

    std::cout << "DATABASE CONFIGURATION" << std::endl;

    std::cout << "HOST: "
              << host.toStdString()
              << std::endl;

    std::cout << "PORT: "
              << port
              << std::endl;

    std::cout << "DATABASE: "
              << dbName.toStdString()
              << std::endl;

    std::cout << "USERNAME: "
              << username.toStdString()
              << std::endl;

    std::cout << "==============================" << std::endl;

    if(database.open())
    {
        std::cout << "DATABASE CONNECTED SUCCESSFULLY!"
                  << std::endl;

        QMessageBox successBox;

        successBox.setWindowTitle("Database Status");

        successBox.setText("Database Connected Successfully!");

        successBox.setStyleSheet(
            "QLabel{color:green;font-size:16px;}"
        );

        successBox.exec();

        return true;
    }
    else
    {
        std::cout << "DATABASE CONNECTION FAILED!"
                  << std::endl;

        std::cout << database.lastError()
                         .text()
                         .toStdString()
                  << std::endl;

        QMessageBox errorBox;

        errorBox.setWindowTitle("Database Status");

        errorBox.setText(
            "Database Connection Failed!"
        );

        errorBox.setStyleSheet(
            "QLabel{color:red;font-size:16px;}"
        );

        errorBox.exec();

        return false;
    }
}