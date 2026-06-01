#include "SystemDashboard.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStackedWidget>
#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <QTableWidget>
#include <QHeaderView>

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
    header->setStyleSheet("background-color:#0F172A;color:white;");

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
        "QPushButton{color:white;padding:12px;text-align:left;border:none;background:transparent;}"
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
    // OVERVIEW PAGE
    // =====================================================
    QWidget *overview = new QWidget();
    QVBoxLayout *ovLayout = new QVBoxLayout(overview);

    QLabel *welcome = new QLabel("Welcome to System Admin Panel");
    welcome->setStyleSheet("font-size:22px;font-weight:bold;");

    ovLayout->addWidget(welcome);
    ovLayout->addStretch();

    // =====================================================
    // SCHOOLS PAGE
    // =====================================================
    QWidget *schools = new QWidget();
    QVBoxLayout *s1 = new QVBoxLayout(schools);
    s1->addWidget(new QLabel("Schools Management Page"));

    // =====================================================
    // ADMINS PAGE (CRUD)
    // =====================================================
    QWidget *admins = new QWidget();
    QVBoxLayout *adminLayout = new QVBoxLayout(admins);

    QLabel *adminTitle = new QLabel("Manage School Admins");
    adminTitle->setStyleSheet("font-size:20px;font-weight:bold;");

    fullNameInput = new QLineEdit();
    fullNameInput->setPlaceholderText("Full Name");

    usernameInput = new QLineEdit();
    usernameInput->setPlaceholderText("Username");

    passwordInput = new QLineEdit();
    passwordInput->setPlaceholderText("Password");
    passwordInput->setEchoMode(QLineEdit::Password);

    createBtn = new QPushButton("Create");
    updateBtn = new QPushButton("Update");
    deleteBtn = new QPushButton("Delete");

    adminTable = new QTableWidget();
    adminTable->setColumnCount(3);
    adminTable->setHorizontalHeaderLabels({"ID","Full Name","Username"});
    adminTable->horizontalHeader()->setStretchLastSection(true);

    adminLayout->addWidget(adminTitle);
    adminLayout->addWidget(fullNameInput);
    adminLayout->addWidget(usernameInput);
    adminLayout->addWidget(passwordInput);

    QHBoxLayout *btnLayout = new QHBoxLayout();
    btnLayout->addWidget(createBtn);
    btnLayout->addWidget(updateBtn);
    btnLayout->addWidget(deleteBtn);

    adminLayout->addLayout(btnLayout);
    adminLayout->addWidget(adminTable);

    // ================= CREATE =================
    connect(createBtn, &QPushButton::clicked, this, [=]()
    {
        User user;
        user.fullName = fullNameInput->text();
        user.username = usernameInput->text();
        user.password = PasswordUtils::hashPassword(passwordInput->text());
        user.role = "school_admin";

        if (UserRepository::createUser(user))
        {
            QMessageBox::information(this,"Success","Admin created");
            loadAdmins();
        }
    });

    // ================= SELECT =================
    connect(adminTable, &QTableWidget::cellClicked, this, [=](int row, int)
    {
        fullNameInput->setText(adminTable->item(row,1)->text());
        usernameInput->setText(adminTable->item(row,2)->text());
    });

    // ================= UPDATE =================
    connect(updateBtn, &QPushButton::clicked, this, [=]()
    {
        int row = adminTable->currentRow();
        if (row < 0) return;

        User user;
        user.id = adminTable->item(row,0)->text().toInt();
        user.fullName = fullNameInput->text();
        user.username = usernameInput->text();

        UserRepository::updateUser(user);

        loadAdmins();
    });

    // ================= DELETE =================
    connect(deleteBtn, &QPushButton::clicked, this, [=]()
    {
        int row = adminTable->currentRow();
        if (row < 0) return;

        int id = adminTable->item(row,0)->text().toInt();

        UserRepository::deleteUser(id);

        loadAdmins();
    });

    // =====================================================
    // LOGS PAGE
    // =====================================================
    QWidget *logs = new QWidget();
    QVBoxLayout *s3 = new QVBoxLayout(logs);
    s3->addWidget(new QLabel("System Logs Page"));

    // ================= STACK =================
    stack->addWidget(overview);
    stack->addWidget(schools);
    stack->addWidget(admins);
    stack->addWidget(logs);

    // ================= NAV =================
    connect(overviewBtn,&QPushButton::clicked,this,[=]{stack->setCurrentIndex(0);});
    connect(schoolsBtn,&QPushButton::clicked,this,[=]{stack->setCurrentIndex(1);});
    connect(adminsBtn,&QPushButton::clicked,this,[=]{stack->setCurrentIndex(2);});
    connect(logsBtn,&QPushButton::clicked,this,[=]{stack->setCurrentIndex(3);});

    // ================= FINAL =================
    body->addWidget(sidebar);
    body->addWidget(stack);

    mainLayout->addWidget(header);
    mainLayout->addLayout(body);

    loadAdmins();
}

void SystemDashboard::loadAdmins()
{
    adminTable->setRowCount(0);

    QList<User> list = UserRepository::getUsersByRole("school_admin");

    for (int i=0;i<list.size();i++)
    {
        adminTable->insertRow(i);

        adminTable->setItem(i,0,new QTableWidgetItem(QString::number(list[i].id)));
        adminTable->setItem(i,1,new QTableWidgetItem(list[i].fullName));
        adminTable->setItem(i,2,new QTableWidgetItem(list[i].username));
    }
}