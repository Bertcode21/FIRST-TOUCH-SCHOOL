#include "SystemDashboard.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStackedWidget>
#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>

#include "models/User.h"
#include "repositories/UserRepository.h"
#include "utils/PasswordUtils.h"

SystemDashboard::SystemDashboard(QWidget *parent)
    : QWidget(parent)
{
    setupUI();
}

void SystemDashboard::setupUI()
{
    resize(1100, 650);
    setWindowTitle("System Admin Dashboard");

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    // ================= HEADER =================
    QFrame *header = new QFrame();
    header->setFixedHeight(60);
    header->setStyleSheet(
        "background-color:#0F172A;"
        "color:white;"
    );

    QHBoxLayout *headerLayout = new QHBoxLayout(header);

    QLabel *title = new QLabel("SYSTEM ADMIN PANEL");
    title->setStyleSheet("font-size:18px;font-weight:bold;");

    QLabel *user = new QLabel("Admin: Super User");

    headerLayout->addWidget(title);
    headerLayout->addStretch();
    headerLayout->addWidget(user);

    // ================= BODY =================
    QHBoxLayout *body = new QHBoxLayout();

    // ================= SIDEBAR =================
    QFrame *sidebar = new QFrame();
    sidebar->setFixedWidth(220);
    sidebar->setStyleSheet("background-color:#1E293B;");

    QVBoxLayout *sideLayout = new QVBoxLayout(sidebar);

    QString btnStyle =
        "QPushButton{"
        "color:white;"
        "padding:12px;"
        "text-align:left;"
        "background:transparent;"
        "border:none;"
        "}"
        "QPushButton:hover{background:#334155;}";

    overviewBtn = new QPushButton("Overview");
    schoolsBtn  = new QPushButton("Schools");
    adminsBtn   = new QPushButton("Admins");
    logsBtn     = new QPushButton("Logs");

    overviewBtn->setStyleSheet(btnStyle);
    schoolsBtn->setStyleSheet(btnStyle);
    adminsBtn->setStyleSheet(btnStyle);
    logsBtn->setStyleSheet(btnStyle);

    sideLayout->addWidget(overviewBtn);
    sideLayout->addWidget(schoolsBtn);
    sideLayout->addWidget(adminsBtn);
    sideLayout->addWidget(logsBtn);
    sideLayout->addStretch();

    // ================= STACK =================
    stack = new QStackedWidget();

    // =====================================================
    // 1. OVERVIEW PAGE
    // =====================================================
    QWidget *overview = new QWidget();
    QVBoxLayout *ovLayout = new QVBoxLayout(overview);

    QLabel *welcome = new QLabel("Welcome to System Admin Panel");
    welcome->setStyleSheet("font-size:22px;font-weight:bold;");

    QFrame *card = new QFrame();
    card->setStyleSheet(
        "background:white;padding:20px;border-radius:10px;"
    );

    QVBoxLayout *cardLayout = new QVBoxLayout(card);

    cardLayout->addWidget(new QLabel("Total Users: 12"));
    cardLayout->addWidget(new QLabel("Total Schools: 3"));
    cardLayout->addWidget(new QLabel("System Status: ACTIVE"));

    ovLayout->addWidget(welcome);
    ovLayout->addWidget(card);
    ovLayout->addStretch();

    // =====================================================
    // 2. SCHOOLS PAGE (placeholder for now)
    // =====================================================
    QWidget *schools = new QWidget();
    QVBoxLayout *s1 = new QVBoxLayout(schools);
    s1->addWidget(new QLabel("Schools Management Page"));

    // =====================================================
    // 3. ADMINS PAGE (REAL CREATE SCHOOL ADMIN)
    // =====================================================
    QWidget *admins = new QWidget();
    QVBoxLayout *adminLayout = new QVBoxLayout(admins);

    QLabel *adminTitle = new QLabel("Create School Admin");
    adminTitle->setStyleSheet("font-size:20px;font-weight:bold;");

    QLineEdit *fullName = new QLineEdit();
    fullName->setPlaceholderText("Full Name");

    QLineEdit *username = new QLineEdit();
    username->setPlaceholderText("Username");

    QLineEdit *password = new QLineEdit();
    password->setPlaceholderText("Password");
    password->setEchoMode(QLineEdit::Password);

    QPushButton *createBtn = new QPushButton("Create School Admin");

    createBtn->setStyleSheet(
        "QPushButton{"
        "background:qlineargradient(x1:0,y1:0,x2:1,y2:0,"
        "stop:0 #1E3A8A, stop:1 #7C3AED);"
        "color:white;"
        "padding:12px;"
        "border-radius:10px;"
        "font-weight:bold;"
        "}"
        "QPushButton:hover{background:#1E40AF;}"
    );

    adminLayout->addWidget(adminTitle);
    adminLayout->addSpacing(10);
    adminLayout->addWidget(fullName);
    adminLayout->addWidget(username);
    adminLayout->addWidget(password);
    adminLayout->addSpacing(10);
    adminLayout->addWidget(createBtn);
    adminLayout->addStretch();

    // ================= CREATE SCHOOL ADMIN LOGIC =================
    connect(createBtn, &QPushButton::clicked, this, [=]()
    {
        if (fullName->text().isEmpty() ||
            username->text().isEmpty() ||
            password->text().isEmpty())
        {
            QMessageBox::warning(this, "Error",
                                 "All fields are required");
            return;
        }

        User user;
        user.fullName = fullName->text();
        user.username = username->text();
        user.password = PasswordUtils::hashPassword(password->text());
        user.role = "school_admin";

        if (UserRepository::createUser(user))
        {
            QMessageBox::information(this, "Success",
                                     "School Admin Created!");

            fullName->clear();
            username->clear();
            password->clear();
        }
        else
        {
            QMessageBox::critical(this, "Error",
                                  "Failed to create admin");
        }
    });

    // =====================================================
    // 4. LOGS PAGE
    // =====================================================
    QWidget *logs = new QWidget();
    QVBoxLayout *s3 = new QVBoxLayout(logs);
    s3->addWidget(new QLabel("System Logs Page"));

    // ================= ADD PAGES =================
    stack->addWidget(overview);
    stack->addWidget(schools);
    stack->addWidget(admins);
    stack->addWidget(logs);

    // ================= NAVIGATION =================
    connect(overviewBtn, &QPushButton::clicked, this, [=](){
        stack->setCurrentIndex(0);
    });

    connect(schoolsBtn, &QPushButton::clicked, this, [=](){
        stack->setCurrentIndex(1);
    });

    connect(adminsBtn, &QPushButton::clicked, this, [=](){
        stack->setCurrentIndex(2);
    });

    connect(logsBtn, &QPushButton::clicked, this, [=](){
        stack->setCurrentIndex(3);
    });

    // ================= FINAL ASSEMBLY =================
    body->addWidget(sidebar);
    body->addWidget(stack);

    mainLayout->addWidget(header);
    mainLayout->addLayout(body);
}