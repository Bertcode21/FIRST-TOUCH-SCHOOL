#ifndef USER_H
#define USER_H

#include <QString>

class User
{
public:
    int id;

    QString fullName;
    QString username;
    QString password; // stored as HASH
    QString role;
};

#endif // USER_H