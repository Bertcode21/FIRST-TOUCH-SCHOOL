#ifndef STUDENT_H
#define STUDENT_H

#include <QString>

class Student
{
public:
    int id;

    QString studentId;   // generated ID (FTS-2026-0001)
    QString firstName;
    QString lastName;

    QString gender;
    QString dateOfBirth;
    QString className;

    QString phone;
    QString parentName;
    QString parentPhone;
    QString address;

    QString status; // ACTIVE | INACTIVE | SUSPENDED | GRADUATED
};

#endif // STUDENT_H