#include "DashboardWindow.h"
#include "LoginWindow.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStackedWidget>
#include <QFrame>
#include <QLabel>
#include <QMessageBox>

DashboardWindow::DashboardWindow(QWidget *parent)
    : QWidget(parent)
{
    setupUI();
}

// =========================
// SETUP UI
// =========================
void DashboardWindow::setupUI()
{
    resize(1000, 600);
    setWindowTitle("First Touch School - Dashboard");

    // ================= MAIN LAYOUT =================
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    // ================= HEADER =================
    QFrame *header = new QFrame();
    header->setFixedHeight(60);
    header->setStyleSheet("background-color:#1e3a5f; color:white;");

    QHBoxLayout *headerLayout = new QHBoxLayout(header);

    QLabel *title = new QLabel("FIRST TOUCH SCHOOL DASHBOARD");
    title->setStyleSheet("font-size:18px; font-weight:bold;");

    logoutBtn = new QPushButton("Logout");
    logoutBtn->setStyleSheet(
        "background-color:#e53935;"
        "color:white;"
        "padding:6px 12px;"
        "border-radius:5px;"
    );

    headerLayout->addWidget(title);
    headerLayout->addStretch();
    headerLayout->addWidget(logoutBtn);

    // ================= BODY =================
    QHBoxLayout *bodyLayout = new QHBoxLayout();

    // ================= SIDEBAR =================
    QFrame *sidebar = new QFrame();
    sidebar->setFixedWidth(200);
    sidebar->setStyleSheet("background-color:#263238;");

    QVBoxLayout *sideLayout = new QVBoxLayout(sidebar);

    studentsBtn = new QPushButton("Students");
    teachersBtn = new QPushButton("Teachers");
    resultsBtn = new QPushButton("Results");

    QString style =
        "QPushButton{"
        "color:white;"
        "background-color:#37474f;"
        "padding:10px;"
        "text-align:left;"
        "border:none;"
        "}"
        "QPushButton:hover{background-color:#455a64;}";

    studentsBtn->setStyleSheet(style);
    teachersBtn->setStyleSheet(style);
    resultsBtn->setStyleSheet(style);

    sideLayout->addWidget(studentsBtn);
    sideLayout->addWidget(teachersBtn);
    sideLayout->addWidget(resultsBtn);
    sideLayout->addStretch();

    // ================= STACKED PAGES =================
    QStackedWidget *stack = new QStackedWidget();

    QWidget *homePage = new QWidget();
    QWidget *studentsPage = new QWidget();
    QWidget *teachersPage = new QWidget();
    QWidget *resultsPage = new QWidget();

    QVBoxLayout *homeLayout = new QVBoxLayout(homePage);
    homeLayout->addWidget(new QLabel("HOME PAGE"));

    QVBoxLayout *stuLayout = new QVBoxLayout(studentsPage);
    stuLayout->addWidget(new QLabel("STUDENTS PAGE"));

    QVBoxLayout *teaLayout = new QVBoxLayout(teachersPage);
    teaLayout->addWidget(new QLabel("TEACHERS PAGE"));

    QVBoxLayout *resLayout = new QVBoxLayout(resultsPage);
    resLayout->addWidget(new QLabel("RESULTS PAGE"));

    stack->addWidget(homePage);
    stack->addWidget(studentsPage);
    stack->addWidget(teachersPage);
    stack->addWidget(resultsPage);

    // ================= CONNECTIONS =================

    connect(studentsBtn, &QPushButton::clicked, this, [=]() {
        openStudents();
        stack->setCurrentWidget(studentsPage);
    });

    connect(teachersBtn, &QPushButton::clicked, this, [=]() {
        openTeachers();
        stack->setCurrentWidget(teachersPage);
    });

    connect(resultsBtn, &QPushButton::clicked, this, [=]() {
        openResults();
        stack->setCurrentWidget(resultsPage);
    });

    connect(logoutBtn, &QPushButton::clicked, this, [=]() {
        logout();
    });

    // ================= ASSEMBLE =================
    bodyLayout->addWidget(sidebar);
    bodyLayout->addWidget(stack);

    mainLayout->addWidget(header);
    mainLayout->addLayout(bodyLayout);
}

// =========================
// FUNCTIONS (REQUIRED BY HEADER)
// =========================

void DashboardWindow::openStudents()
{
    // placeholder logic
    qDebug("Students opened");
}

void DashboardWindow::openTeachers()
{
    qDebug("Teachers opened");
}

void DashboardWindow::openResults()
{
    qDebug("Results opened");
}

void DashboardWindow::logout()
{
    QMessageBox::information(this, "Logout", "You have been logged out.");

    this->close();

    LoginWindow *login = new LoginWindow();
    login->show();
}