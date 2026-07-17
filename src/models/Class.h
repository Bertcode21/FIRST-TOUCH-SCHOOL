#ifndef CLASS_H
#define CLASS_H

#include <QString>
#include <QDateTime>


struct Class
{

    int id = 0;


    // Card title
    QString className;


    // Nursery, Primary, Secondary, High School
    QString level;


    // Assigned class teacher
    int classTeacherId = 0;


    // Maximum number of students
    int capacity = 60;


    // Example: 2026/2027
    QString academicYear;


    // ACTIVE / INACTIVE
    QString status = "ACTIVE";


    QDateTime createdAt;


};


#endif // CLASS_H