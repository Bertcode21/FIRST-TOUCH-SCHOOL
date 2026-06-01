#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include "models/User.h"
#include <QString>

class UserRepository
{
public:
    static bool createUser(const User& user);

    static QList<User> getSchoolAdmins();

    static bool deleteUser(int userId);

    static bool updateUser(const User& user);

    static QList<User> getUsersByRole(const QString& role);

    // ✅ FIXED: now returns user data
    static bool authenticate(const QString& username,
                             const QString& password,
                             User& user);

    static bool adminExists();
};

#endif // USERREPOSITORY_H