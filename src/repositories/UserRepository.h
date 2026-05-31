#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include "models/User.h"
#include <QString>

class UserRepository
{
public:
    static bool createUser(const User& user);

    // ✅ FIXED: now returns user data
    static bool authenticate(const QString& username,
                             const QString& password,
                             User& user);

    static bool adminExists();
};

#endif // USERREPOSITORY_H