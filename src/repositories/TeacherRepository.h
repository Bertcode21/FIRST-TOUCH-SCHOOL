#ifndef TEACHERREPOSITORY_H
#define TEACHERREPOSITORY_H

#include "models/Teacher.h"
#include <QList>
#include <QString>

class TeacherRepository
{
public:
    // CRUD Operations
    static bool createTeacher(const Teacher& teacher);
    static bool updateTeacher(const Teacher& teacher);

    // Status Management
    static bool suspendTeacher(int id);
    static bool activateTeacher(int id);
    static bool setInactive(int id);

    // Data Retrieval
    static QList<Teacher> getAllTeachers();
    static QList<Teacher> getTeachersByStatus(const QString& status);

    // Utilities
    static QString generateTeacherId();
    static int getTeacherCount();
};

#endif // TEACHERREPOSITORY_H