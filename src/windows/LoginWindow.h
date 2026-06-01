#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>

class QLineEdit;
class QPushButton;
class QLabel;

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);

private slots:
    void onLoginClicked();

private:
    void setupUI();

    QLineEdit *usernameInput;
    QLineEdit *passwordInput;

    QPushButton *loginButton;

    QLabel *titleLabel;
};

#endif // LOGINWINDOW_H