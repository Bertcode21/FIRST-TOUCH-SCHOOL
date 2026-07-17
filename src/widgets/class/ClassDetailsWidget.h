#ifndef CLASSDETAILSWIDGET_H
#define CLASSDETAILSWIDGET_H


#include <QWidget>

#include "models/Class.h"


class QLabel;
class QPushButton;
class QVBoxLayout;
class QHBoxLayout;
class ClassStudentTableWidget;
class ClassActionBarWidget;



class ClassDetailsWidget : public QWidget
{

    Q_OBJECT


public:


    explicit ClassDetailsWidget(
        Class schoolClass,
        QWidget *parent = nullptr
    );



private:


    void setupUI();


    void loadClassInformation();



private:


    Class classData;



    QLabel *classNameLabel;

    QLabel *levelLabel;

    QLabel *studentCountLabel;

    QLabel *teacherLabel;



    ClassStudentTableWidget *studentTable;


    ClassActionBarWidget *actionBar;



};


#endif // CLASSDETAILSWIDGET_H