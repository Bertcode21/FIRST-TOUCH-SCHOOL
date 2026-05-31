#include "LoginWindow.h"

#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>

#include "repositories/UserRepository.h"
#include "windows/DashboardWindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent)
{
    setupUI();
}


/// UI SETUP
void LoginWindow::setupUI()
{
    setWindowTitle("School Management - Login");
    resize(400, 250);

    auto *layout = new QVBoxLayout(this);

    QLabel *title = new QLabel("System Login", this);
    title->setAlignment(Qt::AlignCenter);

    usernameInput = new QLineEdit(this);
    usernameInput->setPlaceholderText("Username");

    passwordInput = new QLineEdit(this);
    passwordInput->setPlaceholderText("Password");
    passwordInput->setEchoMode(QLineEdit::Password);

    loginButton = new QPushButton("Login", this);

    layout->addWidget(title);
    layout->addWidget(usernameInput);
    layout->addWidget(passwordInput);
    layout->addWidget(loginButton);

    connect(loginButton, &QPushButton::clicked,
            this, &LoginWindow::onLoginClicked);
}

//// LOGIN LOGIC
void LoginWindow::onLoginClicked()
{
    QString username = usernameInput->text().trimmed();
    QString password = passwordInput->text();

    // 1. Validate input
    if (username.isEmpty() || password.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Please fill all fields");
        return;
    }

    // 2. Prepare user container
    User user;

    // 3. Authenticate (DB + password check happens inside repository)
    bool success = UserRepository::authenticate(username, password, user);

    if (!success)
    {
        QMessageBox::critical(this, "Error", "Invalid username or password");
        return;
    }

    // 4. Success login
    QMessageBox::information(this, "Success", "Login successful");

    this->close();

    // 5. Open dashboard (later we will pass user role here)
    DashboardWindow *dashboard = new DashboardWindow();
    dashboard->setAttribute(Qt::WA_DeleteOnClose);
    dashboard->show();
}