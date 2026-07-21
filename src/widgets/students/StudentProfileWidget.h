#ifndef STUDENTPROFILEWIDGET_H
#define STUDENTPROFILEWIDGET_H


#include <QWidget>

#include "models/Student.h"


class QLabel;
class QPushButton;



class StudentProfileWidget : public QWidget
{

    Q_OBJECT


public:


    explicit StudentProfileWidget(
        Student student,
        QWidget *parent = nullptr
    );



private:


    void setupUI();


    void loadStudentInformation();



private:


    Student studentData;



    QLabel *nameLabel;

    QLabel *studentIdLabel;

    QLabel *genderLabel;

    QLabel *dobLabel;

    QLabel *classLabel;

    QLabel *phoneLabel;

    QLabel *parentNameLabel;

    QLabel *parentPhoneLabel;

    QLabel *addressLabel;

    QLabel *statusLabel;



};



#endif // STUDENTPROFILEWIDGET_H