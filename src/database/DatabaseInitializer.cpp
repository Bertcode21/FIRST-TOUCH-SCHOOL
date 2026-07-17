#include "DatabaseInitializer.h"
#include "DatabaseManager.h"


#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

void DatabaseInitializer::initialize()
{
    qDebug() << "Initializing database...";

    // Verify database is open before creating tables
    if (!DatabaseManager::getDatabase().isOpen())
    {
        qDebug() << "Database is not open!";
        return;
    }

    createUsersTable();
    createStudentsTable();
    createTeachersTable();
    createFeesTable();
    createClassesTable();

    qDebug() << "Database initialization completed.";
}


///   Creates the users table if it does't exists/
void DatabaseInitializer::createUsersTable()
{
    QSqlDatabase db = DatabaseManager::getDatabase();

    QSqlQuery query(db);

    QString sql =
        "CREATE TABLE IF NOT EXISTS users ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "full_name TEXT NOT NULL, "
        "username TEXT UNIQUE NOT NULL, "
        "password TEXT NOT NULL, "
        "role TEXT NOT NULL, "
        "created_at DATETIME DEFAULT CURRENT_TIMESTAMP"
        ")";

    if (query.exec(sql))
    {
        qDebug() << "Users table created or already exists.";
    }
    else
    {
        qDebug() << "Failed to create users table:";
        qDebug() << query.lastError().text();
    }
}

void DatabaseInitializer::createStudentsTable()
{
    QSqlDatabase db = DatabaseManager::getDatabase();
    QSqlQuery query(db);

    QString sql =
        "CREATE TABLE IF NOT EXISTS students ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "student_id TEXT UNIQUE, "
        "first_name TEXT NOT NULL, "
        "last_name TEXT NOT NULL, "
        "gender TEXT, "
        "date_of_birth TEXT, "
        "class_name TEXT, "
        "phone TEXT, "
        "parent_name TEXT, "
        "parent_phone TEXT, "
        "address TEXT, "
        "status TEXT DEFAULT 'ACTIVE', "
        "created_at DATETIME DEFAULT CURRENT_TIMESTAMP"
        ")";

    if (!query.exec(sql))
    {
        qDebug() << "Failed to create students table:";
        qDebug() << query.lastError().text();
    }
    else
    {
        qDebug() << "Students table created or already exists.";
    }
}

void DatabaseInitializer::createTeachersTable()
{
     QSqlDatabase db = DatabaseManager::getDatabase();
     QSqlQuery query(db);

     QString sql =
        "CREATE TABLE IF NOT EXISTS teachers ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "teacher_id TEXT UNIQUE, "
        "first_name TEXT NOT NULL, "
        "last_name TEXT NOT NULL, "
        "gender TEXT, "
        "date_of_birth TEXT, "
        "subject TEXT, "
        "qualification TEXT, "
        "phone TEXT, "
        "email TEXT, "
        "address TEXT, "
        "status TEXT DEFAULT 'ACTIVE', "
        "created_at DATETIME DEFAULT CURRENT_TIMESTAMP"
        ")";


        if (!query.exec(sql))
        {
            qDebug()<<"Failed to create teachers table:";
            qDebug()<<query.lastError().text();
        }

        else
        {
            qDebug()<< "Teachers Table Created or Already exits"; /// for quick debugging
        }

        }


/// Create the fees table if it doesn't exist
void DatabaseInitializer::createFeesTable()
{
    QSqlDatabase db = DatabaseManager::getDatabase();

    QSqlQuery query(db);


    QString sql =
        "CREATE TABLE IF NOT EXISTS fees ("

        "id INTEGER PRIMARY KEY AUTOINCREMENT, "

        "student_db_id INTEGER NOT NULL, "

        "student_id TEXT NOT NULL, "

        "student_name TEXT NOT NULL, "

        "class_name TEXT NOT NULL, "


        "term TEXT NOT NULL, "

        "academic_year TEXT NOT NULL, "


        "amount_due REAL NOT NULL, "

        "amount_paid REAL DEFAULT 0, "

        "balance REAL NOT NULL, "


        "payment_method TEXT, "

        "payment_date TEXT, "


        "receipt_number TEXT UNIQUE, "


        "status TEXT DEFAULT 'Unpaid', "


        "created_at DATETIME DEFAULT CURRENT_TIMESTAMP, "


        "FOREIGN KEY(student_db_id) "

        "REFERENCES students(id) "

        "ON DELETE CASCADE"

        ")";


    if (!query.exec(sql))
    {
        qDebug()
        << "Failed to create fees table:"
        << query.lastError().text();
    }
    else
    {
        qDebug()
        << "Fees table created or already exists.";
    }
}

void DatabaseInitializer::createClassesTable()
{
    QSqlDatabase db = DatabaseManager::getDatabase();
    QSqlQuery query(db);

    QString sql =
        "CREATE TABLE IF NOT EXISTS classes ("

        "id INTEGER PRIMARY KEY AUTOINCREMENT, "

        "class_name TEXT UNIQUE NOT NULL, "

        "section TEXT, "

        "class_teacher_id INTEGER, "

        "capacity INTEGER DEFAULT 60, "

        "status TEXT DEFAULT 'ACTIVE', "

        "created_at DATETIME DEFAULT CURRENT_TIMESTAMP, "

        "FOREIGN KEY(class_teacher_id) "
        "REFERENCES teachers(id)"

        ")";

    if (!query.exec(sql))
    {
        qDebug() << "Failed to create classes table:";
        qDebug() << query.lastError().text();
    }
    else
    {
        qDebug() << "Classes table created or already exists.";
    }
}