#ifndef CLASSCARDWIDGET_H
#define CLASSCARDWIDGET_H


#include <QWidget>

#include "models/Class.h"


class QLabel;
class QPushButton;


class ClassCardWidget : public QWidget
{

    Q_OBJECT


public:


    explicit ClassCardWidget(
        Class schoolClass,
        QWidget *parent = nullptr
    );



signals:


    void classClicked(Class schoolClass);



private slots:


    void openClass();



private:


    void setupUI();

    void loadStatistics();



private:


    Class classData;


    QLabel *classNameLabel;

    QLabel *levelLabel;

    QLabel *studentsLabel;

    QLabel *teacherLabel;


    QPushButton *openButton;


};


#endif // CLASSCARDWIDGET_H