#include "ClassRepository.h"

#include "database/DatabaseManager.h"
#include "StudentRepository.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>


Class ClassRepository::getClassById(int id)
{
    Class c;


    qDebug()
        << "[CLASS REPOSITORY]"
        << "Searching class ID:"
        << id;


    QSqlDatabase db =
            DatabaseManager::getDatabase();


    if(!db.isOpen())
    {
        qCritical()
            << "[CLASS REPOSITORY ERROR]"
            << "Database not open";

        return c;
    }



    QSqlQuery query(db);


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
        qCritical()
            << "[CLASS REPOSITORY ERROR]"
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


        qDebug()
            << "[CLASS REPOSITORY]"
            << "Class found:"
            << c.className;

    }
    else
    {
        qWarning()
            << "[CLASS REPOSITORY]"
            << "No class found";
    }


    return c;
}




bool ClassRepository::createClass(Class schoolClass)
{

    qDebug()
        << "[CLASS REPOSITORY]"
        << "Creating class:"
        << schoolClass.className;



    QSqlQuery query(
        DatabaseManager::getDatabase()
    );



    query.prepare(
        "INSERT INTO classes "
        "("
        "class_name,"
        "level,"
        "class_teacher_id,"
        "capacity,"
        "academic_year,"
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
        qCritical()
            << "[CLASS REPOSITORY ERROR]"
            << "Create failed:"
            << query.lastError().text();

        return false;
    }


    qDebug()
        << "[CLASS REPOSITORY]"
        << "Class created successfully";


    return true;
}






QList<Class> ClassRepository::getAllClasses()
{

    QList<Class> classes;


    qDebug()
        << "[CLASS REPOSITORY]"
        << "Loading all classes...";



    QSqlDatabase db =
            DatabaseManager::getDatabase();



    if(!db.isOpen())
    {
        qCritical()
            << "[CLASS REPOSITORY ERROR]"
            << "Database is not open";

        return classes;
    }



    QSqlQuery query(db);



    query.prepare(
        "SELECT "
        "id,"
        "class_name,"
        "level,"
        "class_teacher_id,"
        "capacity,"
        "academic_year,"
        "status,"
        "created_at "
        "FROM classes "
        "ORDER BY class_name"
    );



    if(!query.exec())
    {

        qCritical()
            << "[CLASS REPOSITORY ERROR]"
            << query.lastError().text();


        return classes;
    }




    while(query.next())
    {

        Class c;


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



        qDebug()
            << "[CLASS REPOSITORY]"
            << "Loaded:"
            << c.className
            << "| Level:"
            << c.level;



        classes.append(c);

    }



    qDebug()
        << "[CLASS REPOSITORY]"
        << "Total classes:"
        << classes.size();



    return classes;
}





bool ClassRepository::updateClass(Class schoolClass)
{

    qDebug()
        << "[CLASS REPOSITORY]"
        << "Updating class:"
        << schoolClass.id;



    QSqlQuery query(
        DatabaseManager::getDatabase()
    );


    query.prepare(
        "UPDATE classes SET "
        "class_name=?,"
        "level=?,"
        "class_teacher_id=?,"
        "capacity=?,"
        "academic_year=?,"
        "status=? "
        "WHERE id=?"
    );



    query.addBindValue(schoolClass.className);
    query.addBindValue(schoolClass.level);
    query.addBindValue(schoolClass.classTeacherId);
    query.addBindValue(schoolClass.capacity);
    query.addBindValue(schoolClass.academicYear);
    query.addBindValue(schoolClass.status);
    query.addBindValue(schoolClass.id);



    if(!query.exec())
    {

        qCritical()
            << "[CLASS REPOSITORY ERROR]"
            << query.lastError().text();

        return false;
    }


    return true;
}





bool ClassRepository::deleteClass(int id)
{

    qDebug()
        << "[CLASS REPOSITORY]"
        << "Deleting class:"
        << id;



    QSqlQuery query(
        DatabaseManager::getDatabase()
    );


    query.prepare(
        "DELETE FROM classes WHERE id=?"
    );


    query.addBindValue(id);



    if(!query.exec())
    {
        qCritical()
            << "[CLASS REPOSITORY ERROR]"
            << query.lastError().text();

        return false;
    }


    return true;
}





int ClassRepository::getStudentCount(QString className)
{

    qDebug()
        << "[CLASS REPOSITORY]"
        << "Counting students in:"
        << className;


    return StudentRepository::countStudentsInClass(className);
}