#ifndef FEEREPOSITORY_H
#define FEEREPOSITORY_H


#include "models/Fees.h"

#include <QList>
#include <QString>


class FeeRepository
{

public:


    // Create a new fee record
    static bool createFee(
        const Fee& fee
    );


    // Update fee information
    static bool updateFee(
        const Fee& fee
    );


    // Record payment
    static bool recordPayment(
        int feeId,
        double amountPaid,
        QString paymentMethod
    );


    // Get all fees
    static QList<Fee> getAllFees();



    // Get fees belonging to one student
    static QList<Fee> getStudentFees(
        int studentDbId
    );



    // Get fees by class
    static QList<Fee> getClassFees(
        QString className
    );



    // Filter fees

    static QList<Fee> getFeesByStatus(
        QString status
    );



    // Dashboard statistics

    static double getTotalRevenue();


    static double getOutstandingBalance();



    // Generate receipt number

    static QString generateReceiptNumber();


};


#endif // FEEREPOSITORY_H