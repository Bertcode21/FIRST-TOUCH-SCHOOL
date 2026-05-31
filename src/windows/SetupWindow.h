#ifndef SETUPWINDOW_H
#define SETUPWINDOW_H

#include <QWidget>

class QLineEdit;
class QPushButton;

class SetupWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SetupWindow(QWidget *parent = nullptr);

private slots:
    void onCreateClicked();

private:
    QLineEdit *fullNameInput;
    QLineEdit *usernameInput;
    QLineEdit *passwordInput;
    QLineEdit *confirmPasswordInput;

    QPushButton *createButton;

    void setupUI();
};

#endif // SETUPWINDOW_H