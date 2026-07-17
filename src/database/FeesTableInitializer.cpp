#include "FeesTableInitializer.h"
#include "DatabaseManager.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

bool FeesTableInitializer::createTable()
{
    QSqlDatabase db = DatabaseManager::getDatabase();
    QSqlQuery query(db);


    QString sql =
    "CREATE TABLE IF NOT EXISTS fees ("
    "id INTEGER PRIMARY KEY AUTOINCREMENT,"
    "student_db_id INTEGER NOT NULL,"
    "student_id TEXT NOT NULL,"
    "student_name TEXT NOT NULL,"
    "class_name TEXT NOT NULL,"
    "term TEXT NOT NULL,"
    "academic_year TEXT NOT NULL,"
    "amount_due REAL NOT NULL,"
    "amount_paid REAL DEFAULT 0,"
    "balance REAL NOT NULL,"
    "payment_method TEXT,"
    "payment_date TEXT,"
    "receipt_number TEXT UNIQUE,"
    "status TEXT DEFAULT 'Unpaid',"
    "FOREIGN KEY(student_db_id) REFERENCES students(id) ON DELETE CASCADE"
    ")";

    qDebug() << "Fees table initialized successfully.";

    if (!query.exec(sql))
    {
        qDebug() << "School Fees table error:"
                 << query.lastError().text();
    }
    else
    {
        qDebug() << "School Fees table ready";
    }
    return true;
}