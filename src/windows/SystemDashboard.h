#ifndef SYSTEMDASHBOARD_H
#define SYSTEMDASHBOARD_H

#include <QWidget>

class QStackedWidget;
class QPushButton;
class QTableWidget;
class QLineEdit;

class SystemDashboard : public QWidget
{
    Q_OBJECT

public:
    explicit SystemDashboard(QWidget *parent = nullptr);

private:
    void setupUI();
    void loadAdmins();
    void clearForm();

private:
    QStackedWidget *stack;

    QPushButton *overviewBtn;
    QPushButton *schoolsBtn;
    QPushButton *adminsBtn;
    QPushButton *logsBtn;

    // Admin management UI
    QTableWidget *adminTable;

    QLineEdit *fullNameInput;
    QLineEdit *usernameInput;
    QLineEdit *passwordInput;

    QPushButton *createBtn;
    QPushButton *updateBtn;
    QPushButton *deleteBtn;
};

#endif // SYSTEMDASHBOARD_H