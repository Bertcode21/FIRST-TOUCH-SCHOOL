#ifndef SIDEBARWIDGET_H
#define SIDEBARWIDGET_H

#include <QFrame>

class QPushButton;

class SidebarWidget : public QFrame
{
    Q_OBJECT

public:
    explicit SidebarWidget(QWidget *parent = nullptr);

signals:
    void dashboardClicked();
    void studentsClicked();
    void teachersClicked();
    void resultsClicked();

private:
    QPushButton *dashboardBtn;
    QPushButton *studentsBtn;
    QPushButton *teachersBtn;
    QPushButton *resultsBtn;
};

#endif