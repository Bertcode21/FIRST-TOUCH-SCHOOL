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
    void academicClicked();
    void resultsClicked();
    void attendanceClicked();

private:
    QPushButton *dashboardBtn;
    QPushButton *studentsBtn;
    QPushButton *teachersBtn;
    QPushButton *academicBtn;
    QPushButton *resultsBtn;
    QPushButton *attendanceBtn;
};

#endif