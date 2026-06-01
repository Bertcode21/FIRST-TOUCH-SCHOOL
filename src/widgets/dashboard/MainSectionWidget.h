#ifndef MAINSECTIONWIDGET_H
#define MAINSECTIONWIDGET_H

#include <QWidget>

class QStackedWidget;

class MainSectionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainSectionWidget(QWidget *parent = nullptr);

public slots:
    void showDashboard();
    void showStudents();
    void showTeachers();
    void showResults();
    void showAcademicManagement();
    void showAttendance();
    void showFinance();
    void showSettings();

private:
    void setupUI();

    QStackedWidget *stack;
};

#endif // MAINSECTIONWIDGET_H