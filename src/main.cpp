#include <QApplication>

#include <QDebug>
#include <QSqlDatabase>

#include "database/DatabaseManager.h"
#include "windows/WelcomeWindow.h"
#include "database/DatabaseInitializer.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qDebug() << "Available SQL Drivers:"
             << QSqlDatabase::drivers();

    // Connect database
    DatabaseManager::connect();

    // Initialize database
    DatabaseInitializer::initialize();

    // Show welcome window
    WelcomeWindow window;

    window.show();

    return app.exec();
}