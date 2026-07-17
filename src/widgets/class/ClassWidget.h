#ifndef CLASSWIDGET_H
#define CLASSWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QScrollArea>

class ClassWidget : public QWidget
{
    Q_OBJECT

public:

    explicit ClassWidget(QWidget *parent = nullptr);


private:

    void setupUI();

    void loadClasses();


private:

    QWidget *container;

    QGridLayout *classLayout;

    QScrollArea *scrollArea;


};

#endif // CLASSWIDGET_H