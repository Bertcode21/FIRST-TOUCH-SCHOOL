#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include "models/User.h"

class UserRepository
{
public:
    static bool createUser(const User& user);

    static bool authenticate(const QString& username,
                             const QString& password);

    static bool adminExists();
};

#endif // USERREPOSITORY_H