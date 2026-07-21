#ifndef CLASSSTUDENTTABLEWIDGET_H
#define CLASSSTUDENTTABLEWIDGET_H


#include <QWidget>
#include <QList>


#include "models/Student.h"



class QTableWidget;



class ClassStudentTableWidget : public QWidget
{

    Q_OBJECT



public:


    explicit ClassStudentTableWidget(
        QString className,
        QWidget *parent = nullptr
    );



signals:


    // Send selected student to profile widget
    void studentSelected(
        Student student
    );



private slots:


    void onStudentClicked(
        int row,
        int column
    );



private:


    void setupUI();

    void loadStudents();



private:


    QString className;


    QTableWidget *table;



    QList<Student> studentsList;



};



#endif // CLASSSTUDENTTABLEWIDGET_H