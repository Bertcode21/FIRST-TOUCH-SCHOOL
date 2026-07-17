#include "FeesRepository.h"

#include "database/DatabaseManager.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDate>


bool FeeRepository::createFee(const Fee& fee)
{
    QSqlQuery query(DatabaseManager::getDatabase());


    query.prepare(
        "INSERT INTO fees "
        "("
        "student_db_id, "
        "student_id, "
        "student_name, "
        "class_name, "
        "term, "
        "academic_year, "
        "amount_due, "
        "amount_paid, "
        "balance, "
        "payment_method, "
        "payment_date, "
        "receipt_number, "
        "status"
        ") "
        "VALUES "
        "(?,?,?,?,?,?,?,?,?,?,?,?,?)"
    );


    query.addBindValue(fee.studentDbId);

    query.addBindValue(fee.studentId);

    query.addBindValue(fee.studentName);

    query.addBindValue(fee.className);

    query.addBindValue(fee.term);

    query.addBindValue(fee.academicYear);

    query.addBindValue(fee.amountDue);

    query.addBindValue(fee.amountPaid);

    query.addBindValue(fee.balance);

    query.addBindValue(fee.paymentMethod);

    query.addBindValue(fee.paymentDate);

    query.addBindValue(fee.receiptNumber);

    query.addBindValue(fee.status);



    if(!query.exec())
    {
        qDebug()
        << "Create fee failed:"
        << query.lastError().text();

        return false;
    }


    return true;
}



bool FeeRepository::updateFee(const Fee& fee)
{

    QSqlQuery query(DatabaseManager::getDatabase());


    query.prepare(
        "UPDATE fees SET "
        "term=?, "
        "academic_year=?, "
        "amount_due=?, "
        "amount_paid=?, "
        "balance=?, "
        "payment_method=?, "
        "payment_date=?, "
        "status=? "
        "WHERE id=?"
    );


    query.addBindValue(fee.term);

    query.addBindValue(fee.academicYear);

    query.addBindValue(fee.amountDue);

    query.addBindValue(fee.amountPaid);

    query.addBindValue(fee.balance);

    query.addBindValue(fee.paymentMethod);

    query.addBindValue(fee.paymentDate);

    query.addBindValue(fee.status);

    query.addBindValue(fee.id);



    if(!query.exec())
    {
        qDebug()
        << "Update fee failed:"
        << query.lastError().text();

        return false;
    }


    return true;
}

/// for the recordPayment method, we will update the amountPaid and balance fields of the fee record, and also set the paymentMethod and paymentDate fields.

bool FeeRepository::recordPayment(
  
    int feeId,
    double amountPaid,
    QString paymentMethod

){

    QSqlQuery query(DatabaseManager::getDatabase());

    /// first we get the current fee information

    query.prepare(
        "SELECT amount_due, amount_paid"
        "FROM fees "
        "Where id=?"

    );

      query.addBindValue(feeId);


      /// we check
        if(!query.exec())
    {
        qDebug()
        << "Fetching fee failed:"
        << query.lastError().text();

        return false;
    }


    /// to see if the fee record exists
     if(!query.next())
    {
        qDebug()
        << "Fee record not found";

        return false;
    }


        double amountDue =
        query.value("amount_due").toDouble();


    double currentPaid =
        query.value("amount_paid").toDouble();


          // Add new payment

    double newPaid =
        currentPaid + amountPaid;



    double balance =
        amountDue - newPaid;



    QString status;



    if(balance <= 0)
    {
        balance = 0;

        status = "PAID";
    }

    else if(newPaid > 0)
    {
        status = "PARTIAL";
    }

    else
    {
        status = "UNPAID";
    }



    // Update database

    query.prepare(
        "UPDATE fees SET "
        "amount_paid=?, "
        "balance=?, "
        "payment_method=?, "
        "payment_date=?, "
        "status=? "
        "WHERE id=?"
    );


    query.addBindValue(newPaid);

    query.addBindValue(balance);

    query.addBindValue(paymentMethod);

    query.addBindValue(
        QDate::currentDate()
        .toString("yyyy-MM-dd")
    );

    query.addBindValue(status);

    query.addBindValue(feeId);



    if(!query.exec())
    {

        qDebug()
        << "Payment update failed:"
        << query.lastError().text();

        return false;
    }



    return true;
}