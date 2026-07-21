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

    explicit ClassWidget(QWidget *parent = nullptr);



signals:

    // Sends selected class to the main dashboard
    void openClassRequested(Class schoolClass);



private:

    void setupUI();

    void loadClasses();



private:

    QWidget *container;

    QGridLayout *classLayout;

    QScrollArea *scrollArea;


};

#endif // CLASSWIDGET_H