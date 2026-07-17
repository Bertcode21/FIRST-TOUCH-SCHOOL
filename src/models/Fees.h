#ifndef FEE_H
#define FEE_H

#include <QString>

class Fee
{
public:

    int id = 0;

    // Student Information
    int studentDbId = 0;
    QString studentId;
    QString studentName;
    QString className;

    // Academic Information
    QString term;
    QString academicYear;

    // Financial Information
    double amountDue = 0.0;
    double amountPaid = 0.0;
    double balance = 0.0;

    QString paymentMethod;
    QString paymentDate;

    QString receiptNumber;

    QString status = "UNPAID";
};

#endif // FEE_H