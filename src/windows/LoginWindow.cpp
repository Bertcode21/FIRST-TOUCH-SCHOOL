#include "LoginWindow.h"

#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>

#include "repositories/UserRepository.h"

#include "windows/DashboardWindow.h"
#include "windows/SystemDashboard.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent)
{
    setupUI();
}

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

void LoginWindow::onLoginClicked()
{
    QString username = usernameInput->text().trimmed();
    QString password = passwordInput->text();

    if (username.isEmpty() || password.isEmpty())
    {
        QMessageBox::warning(this, "Error",
                             "Please fill all fields");
        return;
    }

    User user;

    bool success =
        UserRepository::authenticate(
            username,
            password,
            user
        );

    if (!success)
    {
        QMessageBox::critical(this, "Error",
                              "Invalid username or password");
        return;
    }

    QMessageBox::information(this, "Success",
                             "Login successful");

    this->close();

    QWidget *dashboard = nullptr;

    // ================= ROLE DECISION =================
    if (user.role == "system_admin")
    {
        dashboard = new SystemDashboard();
    }
    else if (user.role == "school_admin")
    {
        dashboard = new DashboardWindow();
    }
    else
    {
        QMessageBox::critical(this, "Error",
                             "Unknown user role");
        return;
    }

    dashboard->setAttribute(Qt::WA_DeleteOnClose);
    dashboard->show();
}