#include "SystemDashboard.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStackedWidget>
#include <QFrame>
#include <QLabel>
#include <QPushButton>

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
    sidebar->setStyleSheet(
        "background-color:#1E293B;"
    );

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

    // ---- Overview Page ----
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

    // ---- Other Pages (placeholders) ----
    QWidget *schools = new QWidget();
    QVBoxLayout *s1 = new QVBoxLayout(schools);
    s1->addWidget(new QLabel("Schools Management Page"));

    QWidget *admins = new QWidget();
    QVBoxLayout *s2 = new QVBoxLayout(admins);
    s2->addWidget(new QLabel("Admins Management Page"));

    QWidget *logs = new QWidget();
    QVBoxLayout *s3 = new QVBoxLayout(logs);
    s3->addWidget(new QLabel("System Logs Page"));

    stack->addWidget(overview);
    stack->addWidget(schools);
    stack->addWidget(admins);
    stack->addWidget(logs);

    // ================= CONNECTIONS =================
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

    // ================= ASSEMBLE =================
    body->addWidget(sidebar);
    body->addWidget(stack);

    mainLayout->addWidget(header);
    mainLayout->addLayout(body);
}