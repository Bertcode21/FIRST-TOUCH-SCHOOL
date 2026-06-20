#ifndef TEACHER_H
#define TEACHER_H

#include <QString>

class Teacher
{
public:
    int id =-1;

    QString teacherId;      // FTS-TCH-2026-0001

    QString firstName;
    QString lastName;

    QString gender;
    QString dateOfBirth;

    QString subject;        // Main subject taught
    QString qualification;  // HND, B.Tech, MSc, etc.
    QString phone;
    QString email;
    QString address;

    QString status;         // ACTIVE | INACTIVE | SUSPENDED
};

#endif // TEACHER_H