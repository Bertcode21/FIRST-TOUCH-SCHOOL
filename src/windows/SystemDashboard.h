#ifndef SYSTEMDASHBOARD_H
#define SYSTEMDASHBOARD_H

#include <QWidget>

class QStackedWidget;
class QPushButton;

class SystemDashboard : public QWidget
{
    Q_OBJECT

public:
    explicit SystemDashboard(QWidget *parent = nullptr);

private:
    void setupUI();

    QStackedWidget *stack;

    QPushButton *overviewBtn;
    QPushButton *schoolsBtn;
    QPushButton *adminsBtn;
    QPushButton *logsBtn;
};

#endif // SYSTEMDASHBOARD_H