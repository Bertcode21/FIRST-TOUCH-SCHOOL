#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDate>

#include "TeacherRepository.h"
#include "database/DatabaseManager.h"

// ================= CREATE TEACHER =================
bool TeacherRepository::createTeacher(const Teacher& t)
{
    QSqlQuery query(DatabaseManager::getDatabase());

   bool ok =  query.prepare(
        "INSERT INTO teachers "
        "(teacher_id, first_name, last_name, gender, "
        "date_of_birth, subject, qualification, "
        "phone, email, address, status) "
        "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)"
    );
    qDebug() <<"Preparing: " << ok;
    query.addBindValue(t.teacherId);
    query.addBindValue(t.firstName);
    query.addBindValue(t.lastName);
    query.addBindValue(t.gender);
    query.addBindValue(t.dateOfBirth);
    query.addBindValue(t.subject);
    query.addBindValue(t.qualification);
    query.addBindValue(t.phone);
    query.addBindValue(t.email);
    query.addBindValue(t.address);
    query.addBindValue("ACTIVE");

    qDebug() << "Bound Count: "
             << query.boundValues().size();

    if (!query.exec())
    {
        qDebug() << "Create teacher failed:"
                 << query.lastError().text();
        return false;
    }

    return true;
}

// ================= UPDATE TEACHER =================
bool TeacherRepository::updateTeacher(const Teacher& t)
{
    QSqlQuery query(DatabaseManager::getDatabase());

    query.prepare(
        "UPDATE teachers SET "
        "first_name=?, "
        "last_name=?, "
        "gender=?, "
        "date_of_birth=?, "
        "subject=?, "
        "qualification=?, "
        "phone=?, "
        "email=?, "
        "address=? "
        "WHERE id=?"
    );

    query.addBindValue(t.firstName);
    query.addBindValue(t.lastName);
    query.addBindValue(t.gender);
    query.addBindValue(t.dateOfBirth);
    query.addBindValue(t.subject);
    query.addBindValue(t.qualification);
    query.addBindValue(t.phone);
    query.addBindValue(t.email);
    query.addBindValue(t.address);
    query.addBindValue(t.id);

    return query.exec();
}

// ================= SUSPEND =================
bool TeacherRepository::suspendTeacher(int id)
{
    QSqlQuery q(DatabaseManager::getDatabase());

    q.prepare(
        "UPDATE teachers "
        "SET status='SUSPENDED' "
        "WHERE id=?"
    );

    q.addBindValue(id);

    return q.exec();
}

// ================= ACTIVATE =================
bool TeacherRepository::activateTeacher(int id)
{
    QSqlQuery q(DatabaseManager::getDatabase());

    q.prepare(
        "UPDATE teachers "
        "SET status='ACTIVE' "
        "WHERE id=?"
    );

    q.addBindValue(id);

    return q.exec();
}

// ================= INACTIVE =================
bool TeacherRepository::setInactive(int id)
{
    QSqlQuery q(DatabaseManager::getDatabase());

    q.prepare(
        "UPDATE teachers "
        "SET status='INACTIVE' "
        "WHERE id=?"
    );

    q.addBindValue(id);

    return q.exec();
}

// ================= GET ALL TEACHERS =================
QList<Teacher> TeacherRepository::getAllTeachers()
{
    QList<Teacher> list;

    QSqlQuery q(DatabaseManager::getDatabase());

    q.prepare("SELECT * FROM teachers");

    if (q.exec())
    {
        while (q.next())
        {
            Teacher t;

            t.id = q.value("id").toInt();
            t.teacherId = q.value("teacher_id").toString();
            t.firstName = q.value("first_name").toString();
            t.lastName = q.value("last_name").toString();
            t.gender = q.value("gender").toString();
            t.dateOfBirth = q.value("date_of_birth").toString();
            t.subject = q.value("subject").toString();
            t.qualification = q.value("qualification").toString();
            t.phone = q.value("phone").toString();
            t.email = q.value("email").toString();
            t.address = q.value("address").toString();
            t.status = q.value("status").toString();

            list.append(t);
        }
    }

    return list;
}

// ================= GET BY STATUS =================
QList<Teacher> TeacherRepository::getTeachersByStatus(
    const QString& status)
{
    QList<Teacher> list;

    QSqlQuery q(DatabaseManager::getDatabase());

    q.prepare(
        "SELECT * FROM teachers "
        "WHERE status=?"
    );

    q.addBindValue(status);

    if (q.exec())
    {
        while (q.next())
        {
            Teacher t;

            t.id = q.value("id").toInt();
            t.teacherId = q.value("teacher_id").toString();
            t.firstName = q.value("first_name").toString();
            t.lastName = q.value("last_name").toString();
            t.gender = q.value("gender").toString();
            t.dateOfBirth = q.value("date_of_birth").toString();
            t.subject = q.value("subject").toString();
            t.qualification = q.value("qualification").toString();
            t.phone = q.value("phone").toString();
            t.email = q.value("email").toString();
            t.address = q.value("address").toString();
            t.status = q.value("status").toString();

            list.append(t);
        }
    }

    return list;
}

// ================= TEACHER ID =================
QString TeacherRepository::generateTeacherId()
{
    int count = getTeacherCount() + 1;

    return QString("FTS-TCH-%1-%2")
            .arg(QDate::currentDate().year())
            .arg(count, 4, 10, QChar('0'));
}

// ================= COUNT =================
int TeacherRepository::getTeacherCount()
{
    QSqlQuery q(DatabaseManager::getDatabase());

    q.prepare(
        "SELECT COUNT(*) FROM teachers"
    );

    if (q.exec() && q.next())
        return q.value(0).toInt();

    return 0;
}