#ifndef STUDENTREPOSITORY_H
#define STUDENTREPOSITORY_H

#include "models/Student.h"
#include <QList>

class StudentRepository
{
public:
    static bool createStudent(const Student& student);
    static bool updateStudent(const Student& student);

    static bool suspendStudent(int id);
    static bool graduateStudent(int id);
    static bool activateStudent(int id);
    static bool setInactive(int id);

    static QList<Student> getAllStudents();
    static QList<Student> getStudentsByStatus(const QString& status);

    static QString generateStudentId();
    static int getStudentCount();
};

#endif // STUDENTREPOSITORY_H