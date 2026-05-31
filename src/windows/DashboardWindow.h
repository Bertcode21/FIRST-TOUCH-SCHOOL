#ifndef DASHBOARDWINDOW_H
#define DASHBOARDWINDOW_H

#include <QWidget>

class QPushButton;

class DashboardWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DashboardWindow(QWidget *parent = nullptr);

private slots:
    void openStudents();
    void openTeachers();
    void openResults();
    void logout();

private:
    void setupUI();

    QPushButton *studentsBtn;
    QPushButton *teachersBtn;
    QPushButton *resultsBtn;
    QPushButton *logoutBtn;
};

#endif // DASHBOARDWINDOW_H