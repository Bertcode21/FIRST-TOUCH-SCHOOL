#include "UserRepository.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

#include "utils/PasswordUtils.h"
#include "database/DatabaseManager.h"

bool UserRepository::createUser(const User& user)
{
    QSqlQuery query(DatabaseManager::getDatabase());

    query.prepare(
        "INSERT INTO users "
        "(full_name, username, password, role) "
        "VALUES (?, ?, ?, ?)"
    );

    query.addBindValue(user.fullName);
    query.addBindValue(user.username);
    query.addBindValue(user.password);
    query.addBindValue(user.role);

    if (!query.exec())
    {
        qDebug() << "Create user failed:" << query.lastError().text();
        return false;
    }

    return true;
}


/// SELECT id FROM users WHERE username = ? AND password = ?
// AUTHENTICATE USER
bool UserRepository::authenticate(const QString& username,
                                  const QString& password)
{
    QString hashed = PasswordUtils::hashPassword(password);

    QSqlQuery query(DatabaseManager::getDatabase());

    query.prepare(
        "SELECT id FROM users "
        "WHERE username = ? AND password = ?"
    );

    query.addBindValue(username);
    query.addBindValue(hashed);

    if (query.exec() && query.next())
    {
        return true; // login success
    }

    return false;
}

//// CHECK IF ADMIN USER EXISTS
bool UserRepository::adminExists()
{
    QSqlQuery query(DatabaseManager::getDatabase());

    query.prepare(
        "SELECT id FROM users WHERE role = 'system_admin' LIMIT 1"
    );

    if (query.exec() && query.next())
    {
        return true;
    }

    return false;
}