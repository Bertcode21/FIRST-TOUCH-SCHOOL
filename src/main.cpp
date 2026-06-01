#include <QApplication>

#include <QDebug>
#include <QIcon>
#include <QFile>
#include <QSqlDatabase>

#include "database/DatabaseManager.h"
#include "windows/WelcomeWindow.h"
#include "windows/SetupWindow.h"
#include "windows/LoginWindow.h"
#include "database/DatabaseInitializer.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qDebug() << "Available SQL Drivers:"
             << QSqlDatabase::drivers();
     app.setWindowIcon(QIcon("assets/images/logo.ico"));
    // Connect database
    DatabaseManager::connect();

    // Initialize database
    DatabaseInitializer::initialize();

    // Show welcome window
    WelcomeWindow window;

    //Show Setupwindwo
    SetupWindow setupWindow;

    // Show login window


qDebug() << QCoreApplication::applicationDirPath();
qDebug() << QFile::exists("assets/images/logo.ico");

// app.setWindowIcon(QIcon(":/assets/images/logo.ico"));

    window.show();
   

    return app.exec();
}