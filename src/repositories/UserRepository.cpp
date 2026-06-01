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
                                  const QString& password,
                                  User& user)
{
    QString hashed = PasswordUtils::hashPassword(password);

    QSqlQuery query(DatabaseManager::getDatabase());

    query.prepare(
        "SELECT id, full_name, username, role "
        "FROM users "
        "WHERE username = ? AND password = ?"
    );

    query.addBindValue(username);
    query.addBindValue(hashed);

    if (query.exec() && query.next())
    {
        user.id = query.value("id").toInt();
        user.fullName = query.value("full_name").toString();
        user.username = query.value("username").toString();
        user.role = query.value("role").toString();

        qDebug() << "Logged User:";
        qDebug() << "ID:" << user.id;
        qDebug() << "Name:" << user.fullName;
        qDebug() << "Username:" << user.username;
        qDebug() << "Role:" << user.role;

        return true;
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

QList<User> UserRepository::getSchoolAdmins()
{
    QList<User> admins;

    QSqlQuery query(DatabaseManager::getDatabase());

    query.prepare(
        "SELECT id, full_name, username, role "
        "FROM users "
        "WHERE role = 'school_admin'"
    );

    if(query.exec())
    {
        while(query.next())
        {
            User user;

            user.id = query.value("id").toInt();
            user.fullName = query.value("full_name").toString();
            user.username = query.value("username").toString();
            user.role = query.value("role").toString();

            admins.append(user);
        }
    }

    return admins;
}

/// DELETES USER BY ID
bool UserRepository::deleteUser(int userId)
{
    QSqlQuery query(DatabaseManager::getDatabase());

    query.prepare(
        "DELETE FROM users WHERE id = ?"
    );

    query.addBindValue(userId);

    return query.exec();
}

// UPDATE USER
bool UserRepository::updateUser(const User& user)
{
    QSqlQuery query(DatabaseManager::getDatabase());

    query.prepare(
        "UPDATE users "
        "SET full_name=?, username=? "
        "WHERE id=?"
    );

    query.addBindValue(user.fullName);
    query.addBindValue(user.username);
    query.addBindValue(user.id);

    return query.exec();
}

QList<User> UserRepository::getUsersByRole(const QString& role)
{
    QList<User> users;

    QSqlQuery query;
    query.prepare(
        "SELECT id, full_name, username, role "
        "FROM users WHERE role = ?"
    );

    query.addBindValue(role);

    if(query.exec())
    {
        while(query.next())
        {
            User user;

            user.id =
                query.value("id").toInt();

            user.fullName =
                query.value("full_name").toString();

            user.username =
                query.value("username").toString();

            user.role =
                query.value("role").toString();

            users.append(user);
        }
    }
    else
    {
        qDebug() << "Query error:"
                 << query.lastError().text();
    }

    return users;
}