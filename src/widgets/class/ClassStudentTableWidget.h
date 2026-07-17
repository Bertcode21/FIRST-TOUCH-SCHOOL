#ifndef CLASSSTUDENTTABLEWIDGET_H
#define CLASSSTUDENTTABLEWIDGET_H


#include <QWidget>


class QTableWidget;



class ClassStudentTableWidget : public QWidget
{

    Q_OBJECT


public:


    explicit ClassStudentTableWidget(
        QString className,
        QWidget *parent = nullptr
    );



private:


    void setupUI();


    void loadStudents();



private:


    QString className;


    QTableWidget *table;



};


#endif // CLASSSTUDENTTABLEWIDGET_H