/*
=================================================
THIS IS A GENERATED C++ SOURCE FILE. DO NOT MODIFY THIS FILE DIRECTLY.
=================================================
*/

#include <QApplication>
#include <QPushButton>

#include <QDebug>
#include <QSqlDatabase>

#include "database/DatabaseManager.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // OPTIONAL: Debug available SQL drivers
    qDebug() << "Available SQL Drivers:" << QSqlDatabase::drivers();

    // Try connecting to database
    DatabaseManager::connect();

    // Simple UI test window
    QPushButton button("First Touch School Management System");
    button.resize(500, 120);
    button.show();

    return app.exec();
}