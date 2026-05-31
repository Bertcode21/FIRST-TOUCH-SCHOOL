#include "SetupWindow.h"

#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>

#include "models/User.h"
#include "repositories/UserRepository.h"
#include "utils/PasswordUtils.h"

#include "LoginWindow.h"


/// MAIN UI DESIGN
SetupWindow::SetupWindow(QWidget *parent)
    : QWidget(parent)
{
    setupUI();
}


/// BUILD UI
void SetupWindow::setupUI()
{
    setWindowTitle("School Setup - Create System Admin");
    resize(400, 300);

    auto *layout = new QVBoxLayout(this);

    fullNameInput = new QLineEdit(this);
    fullNameInput->setPlaceholderText("Full Name");

    usernameInput = new QLineEdit(this);
    usernameInput->setPlaceholderText("Username");

    passwordInput = new QLineEdit(this);
    passwordInput->setPlaceholderText("Password");
    passwordInput->setEchoMode(QLineEdit::Password);

    confirmPasswordInput = new QLineEdit(this);
    confirmPasswordInput->setPlaceholderText("Confirm Password");
    confirmPasswordInput->setEchoMode(QLineEdit::Password);

    createButton = new QPushButton("Create System Admin", this);

    layout->addWidget(new QLabel("School Setup"));
    layout->addWidget(fullNameInput);
    layout->addWidget(usernameInput);
    layout->addWidget(passwordInput);
    layout->addWidget(confirmPasswordInput);
    layout->addWidget(createButton);

    connect(createButton, &QPushButton::clicked,
            this, &SetupWindow::onCreateClicked);
}

/// CREATE SYSTEM ADMIN
void SetupWindow::onCreateClicked()
{
    QString fullName = fullNameInput->text();
    QString username = usernameInput->text();
    QString password = passwordInput->text();
    QString confirmPassword = confirmPasswordInput->text();

    if (fullName.isEmpty() || username.isEmpty()
        || password.isEmpty())
    {
        QMessageBox::warning(this, "Error", "All fields are required.");
        return;
    }

    if (password != confirmPassword)
    {
        QMessageBox::warning(this, "Error", "Passwords do not match.");
        return;
    }

    // Create User object
    User user;
    user.fullName = fullName;
    user.username = username;
    user.role = "system_admin";

    // Hash password
    user.password = PasswordUtils::hashPassword(password);

    // Save to database
    if (UserRepository::createUser(user))
    {
        QMessageBox::information(this, "Success",
                                 "System Admin Created!");

        // Go to login window
        this->close();

        LoginWindow *login = new LoginWindow();
        login->show();
    }
    else
    {
        QMessageBox::critical(this, "Error",
                              "Failed to create admin.");
    }
}