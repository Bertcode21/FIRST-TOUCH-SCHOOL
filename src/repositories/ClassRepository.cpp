#include "ClassRepository.h"

#include "database/DatabaseManager.h"
#include "StudentRepository.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>


Class ClassRepository::getClassById(int id)
{

    Class c;


    QSqlQuery query(DatabaseManager::getDatabase());


    query.prepare(
        "SELECT "
        "id, "
        "class_name, "
        "level, "
        "class_teacher_id, "
        "capacity, "
        "academic_year, "
        "status, "
        "created_at "
        "FROM classes "
        "WHERE id = ?"
    );


    query.addBindValue(id);


    if(!query.exec())
    {

        qDebug()
        << "Failed getting class:"
        << query.lastError().text();

        return c;

    }


    if(query.next())
    {

        c.id =
        query.value("id").toInt();


        c.className =
        query.value("class_name").toString();


        c.level =
        query.value("level").toString();


        c.classTeacherId =
        query.value("class_teacher_id").toInt();


        c.capacity =
        query.value("capacity").toInt();


        c.academicYear =
        query.value("academic_year").toString();


        c.status =
        query.value("status").toString();

    }


    return c;

}



bool ClassRepository::createClass(Class schoolClass)
{

    QSqlQuery query(DatabaseManager::getDatabase());


    query.prepare(
        "INSERT INTO classes "
        "("
        "class_name, "
        "level, "
        "class_teacher_id, "
        "capacity, "
        "academic_year, "
        "status"
        ") "
        "VALUES "
        "(?,?,?,?,?,?)"
    );


    query.addBindValue(
        schoolClass.className
    );


    query.addBindValue(
        schoolClass.level
    );


    query.addBindValue(
        schoolClass.classTeacherId
    );


    query.addBindValue(
        schoolClass.capacity
    );


    query.addBindValue(
        schoolClass.academicYear
    );


    query.addBindValue(
        schoolClass.status
    );



    if(!query.exec())
    {

        qDebug()
        << "Failed creating class:"
        << query.lastError().text();

        return false;

    }


    return true;

}

QList<Class> ClassRepository::getAllClasses()
{
    QList<Class> classes;

    QSqlQuery query(DatabaseManager::getDatabase());

    query.prepare(
        "SELECT * FROM classes "
        "ORDER BY class_name"
    );

    if (!query.exec())
    {
        qDebug()
            << "Failed loading classes:"
            << query.lastError().text();

        return classes;
    }

    while (query.next())
    {
        Class c;

        c.id = query.value("id").toInt();
        c.className = query.value("class_name").toString();
        c.level = query.value("level").toString();
        c.classTeacherId = query.value("class_teacher_id").toInt();
        c.capacity = query.value("capacity").toInt();
        c.academicYear = query.value("academic_year").toString();
        c.status = query.value("status").toString();

        classes.append(c);
    }

    return classes;
}

bool ClassRepository::updateClass(Class schoolClass)
{

    QSqlQuery query(DatabaseManager::getDatabase());


    query.prepare(
        "UPDATE classes SET "
        "class_name=?, "
        "level=?, "
        "class_teacher_id=?, "
        "capacity=?, "
        "academic_year=?, "
        "status=? "
        "WHERE id=?"
    );


    query.addBindValue(
        schoolClass.className
    );


    query.addBindValue(
        schoolClass.level
    );


    query.addBindValue(
        schoolClass.classTeacherId
    );


    query.addBindValue(
        schoolClass.capacity
    );


    query.addBindValue(
        schoolClass.academicYear
    );


    query.addBindValue(
        schoolClass.status
    );


    query.addBindValue(
        schoolClass.id
    );



    if(!query.exec())
    {

        qDebug()
        << "Failed updating class:"
        << query.lastError().text();

        return false;

    }


    return true;

}



bool ClassRepository::deleteClass(int id)
{

    QSqlQuery query(DatabaseManager::getDatabase());


    query.prepare(
        "DELETE FROM classes "
        "WHERE id=?"
    );


    query.addBindValue(id);



    if(!query.exec())
    {

        qDebug()
        << "Failed deleting class:"
        << query.lastError().text();

        return false;

    }


    return true;

}
int ClassRepository::getStudentCount(QString className)
{
    return StudentRepository::countStudentsInClass(className);
}