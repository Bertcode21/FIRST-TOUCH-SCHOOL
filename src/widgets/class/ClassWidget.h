#ifndef CLASSWIDGET_H
#define CLASSWIDGET_H


#include <QWidget>
#include <QGridLayout>
#include <QScrollArea>


#include "models/Class.h"



class ClassWidget : public QWidget
{

    Q_OBJECT



public:

    explicit ClassWidget(
        QWidget *parent = nullptr
    );



signals:


    // Send selected class to dashboard
    void openClassRequested(
        Class schoolClass
    );



public slots:


    // Reload cards after new student registration
    void refreshClasses();



private:


    void setupUI();

    void loadClasses();



private:


    QWidget *container;


    QGridLayout *classLayout;


    QScrollArea *scrollArea;



};



#endif // CLASSWIDGET_H