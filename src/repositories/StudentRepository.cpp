
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDate>
#include "StudentRepository.h"
#include "database/DatabaseManager.h"

bool StudentRepository::createStudent(const Student& s)
{
    QSqlQuery query(DatabaseManager::getDatabase());

    query.prepare(
        "INSERT INTO students "
        "(student_id, first_name, last_name, gender, date_of_birth, class_name,"
        " phone, parent_name, parent_phone, address, status) "
        "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)"
    );

    query.addBindValue(s.studentId);
    query.addBindValue(s.firstName);
    query.addBindValue(s.lastName);
    query.addBindValue(s.gender);
    query.addBindValue(s.dateOfBirth);
    query.addBindValue(s.className);
    query.addBindValue(s.phone);
    query.addBindValue(s.parentName);
    query.addBindValue(s.parentPhone);
    query.addBindValue(s.address);
    query.addBindValue("ACTIVE");

    if (!query.exec())
    {
        qDebug() << "Create student failed:" << query.lastError().text();
        return false;
    }

    return true;
}

bool StudentRepository::updateStudent(const Student& s)
{
    QSqlQuery query(DatabaseManager::getDatabase());

    query.prepare(
        "UPDATE students SET "
        "first_name=?, last_name=?, gender=?, date_of_birth=?, class_name=?, "
        "phone=?, parent_name=?, parent_phone=?, address=? "
        "WHERE id=?"
    );

    query.addBindValue(s.firstName);
    query.addBindValue(s.lastName);
    query.addBindValue(s.gender);
    query.addBindValue(s.dateOfBirth);
    query.addBindValue(s.className);
    query.addBindValue(s.phone);
    query.addBindValue(s.parentName);
    query.addBindValue(s.parentPhone);
    query.addBindValue(s.address);
    query.addBindValue(s.id);

    return query.exec();
}


/// CLEAN CODE: This method is too long and has too many responsibilities. It should be broken down into smaller methods.
bool StudentRepository::suspendStudent(int id)
{
    QSqlQuery q(DatabaseManager::getDatabase());
    q.prepare("UPDATE students SET status='SUSPENDED' WHERE id=?");
    q.addBindValue(id);
    return q.exec();
}

bool StudentRepository::graduateStudent(int id)
{
    QSqlQuery q(DatabaseManager::getDatabase());
    q.prepare("UPDATE students SET status='GRADUATED' WHERE id=?");
    q.addBindValue(id);
    return q.exec();
}

bool StudentRepository::activateStudent(int id)
{
    QSqlQuery q(DatabaseManager::getDatabase());
    q.prepare("UPDATE students SET status='ACTIVE' WHERE id=?");
    q.addBindValue(id);
    return q.exec();
}

bool StudentRepository::setInactive(int id)
{
    QSqlQuery q(DatabaseManager::getDatabase());
    q.prepare("UPDATE students SET status='INACTIVE' WHERE id=?");
    q.addBindValue(id);
    return q.exec();
}


//// FETCH EACH LISTS OF STUDENT BASED ON THEIR STATUS
QList<Student> StudentRepository::getAllStudents()
{
    QList<Student> list;

    QSqlQuery q(DatabaseManager::getDatabase());

    q.prepare("SELECT * FROM students");

    if (q.exec())
    {
        while (q.next())
        {
            Student s;

            s.id = q.value("id").toInt();
            s.studentId = q.value("student_id").toString();
            s.firstName = q.value("first_name").toString();
            s.lastName = q.value("last_name").toString();
            s.gender = q.value("gender").toString();
            s.dateOfBirth = q.value("date_of_birth").toString();
            s.className = q.value("class_name").toString();
            s.phone = q.value("phone").toString();
            s.parentName = q.value("parent_name").toString();
            s.parentPhone = q.value("parent_phone").toString();
            s.address = q.value("address").toString();
            s.status = q.value("status").toString();

            list.append(s);
        }
    }

    return list;
}


//// STUDENT ID GENERATOR
QString StudentRepository::generateStudentId()
{
    int count = getStudentCount() + 1;

    return QString("FTS-%1-%2")
            .arg(QDate::currentDate().year())
            .arg(count, 4, 10, QChar('0'));
}

//// STDENT COUNT
int StudentRepository::getStudentCount()
{
    QSqlQuery q(DatabaseManager::getDatabase());

    q.prepare("SELECT COUNT(*) FROM students");

    if (q.exec() && q.next())
        return q.value(0).toInt();

    return 0;
}
int StudentRepository::countStudentsInClass(const QString& className)
{
    QSqlQuery q(DatabaseManager::getDatabase());

    q.prepare("SELECT COUNT(*) FROM students WHERE class_name = ?");
    q.addBindValue(className);

    if (q.exec() && q.next())
        return q.value(0).toInt();

    qDebug() << "Failed to count students:" << q.lastError().text();
    return 0;
}
QList<Student> StudentRepository::getStudentsByClass(
        const QString& className
)
{
    QList<Student> list;

    QSqlQuery q(DatabaseManager::getDatabase());

    q.prepare(
        "SELECT * FROM students "
        "WHERE class_name = ? "
        "AND status='ACTIVE'"
    );

    q.addBindValue(className);

    if(q.exec())
    {
        while(q.next())
        {
            Student s;

            s.id = q.value("id").toInt();
            s.studentId = q.value("student_id").toString();
            s.firstName = q.value("first_name").toString();
            s.lastName = q.value("last_name").toString();
            s.gender = q.value("gender").toString();
            s.dateOfBirth = q.value("date_of_birth").toString();
            s.className = q.value("class_name").toString();
            s.phone = q.value("phone").toString();
            s.parentName = q.value("parent_name").toString();
            s.parentPhone = q.value("parent_phone").toString();
            s.address = q.value("address").toString();
            s.status = q.value("status").toString();

            list.append(s);
        }
    }

    return list;
}