#include "SidebarWidget.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

SidebarWidget::SidebarWidget(QWidget *parent)
    : QFrame(parent)
{
    setFixedWidth(260);

    setStyleSheet(
        "QFrame {"
        "background:qlineargradient("
        "x1:0,y1:0,x2:0,y2:1,"
        "stop:0 #0F172A,"
        "stop:1 #1E3A8A);"
        "border:none;"
        "}"
    );

    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->setContentsMargins(10, 9, 9, 10);
    layout->setSpacing(7);

    // =========================
    // LOGO SECTION
    // =========================

    QLabel *logoLabel =
        new QLabel("FIRST TOUCH");

    logoLabel->setAlignment(Qt::AlignCenter);

    logoLabel->setStyleSheet(
        "color:white;"
        "font-size:22px;"
        "font-weight:bold;"
        "padding:15px;"
    );

    QLabel *subTitle =
        new QLabel("School Management");

    subTitle->setAlignment(Qt::AlignCenter);

    subTitle->setStyleSheet(
        "color:#CBD5E1;"
        "font-size:12px;"
        "margin-bottom:20px;"
    );

    layout->addWidget(logoLabel);
    layout->addWidget(subTitle);

    // =========================
    // BUTTON STYLE
    // =========================

    QString menuStyle =
        "QPushButton {"
        "background-color:transparent;"
        "color:white;"
        "text-align:left;"
        "padding:14px;"
        "font-size:14px;"
        "font-weight:600;"
        "border-radius:10px;"
        "}"
        "QPushButton:hover {"
        "background:qlineargradient("
        "x1:0,y1:0,x2:1,y2:0,"
        "stop:0 #3B82F6,"
        "stop:1 #7C3AED);"
        "}";

    // =========================
    // MENU BUTTONS
    // =========================

    dashboardBtn = new QPushButton("🏠 Dashboard");
    studentsBtn  = new QPushButton("🎓 Students");
    teachersBtn  = new QPushButton("👨‍🏫 Teachers");
    classBtn     = new QPushButton("🏫 Classes");
    academicBtn = new QPushButton("🎓 Academic Management");
    resultsBtn   = new QPushButton("📊 Results");
    feesBtn = new QPushButton("💵 Fees");

    QPushButton *attendanceBtn =
        new QPushButton("📅 Attendance");

    QPushButton *financeBtn =
        new QPushButton("💰 Finance");

    QPushButton *settingsBtn =
        new QPushButton("⚙ Settings");

    dashboardBtn->setStyleSheet(menuStyle);
    studentsBtn->setStyleSheet(menuStyle);
    teachersBtn->setStyleSheet(menuStyle);
    classBtn->setStyleSheet(menuStyle);
    feesBtn->setStyleSheet(menuStyle);
    resultsBtn->setStyleSheet(menuStyle);
    academicBtn->setStyleSheet(menuStyle);
    attendanceBtn->setStyleSheet(menuStyle);
    financeBtn->setStyleSheet(menuStyle);
    settingsBtn->setStyleSheet(menuStyle);

    layout->addWidget(dashboardBtn);
    layout->addWidget(studentsBtn);
    layout->addWidget(teachersBtn);
    layout->addWidget(resultsBtn);
    layout->addWidget(academicBtn);
    layout->addWidget(attendanceBtn);
    layout->addWidget(classBtn);
    layout->addWidget(feesBtn);
    layout->addWidget(financeBtn);
    layout->addWidget(settingsBtn);

    layout->addStretch();

    // =========================
    // FOOTER
    // =========================

    QLabel *footer =
        new QLabel("Version 1.0.0");

    footer->setAlignment(Qt::AlignCenter);

    footer->setStyleSheet(
        "color:#94A3B8;"
        "font-size:11px;"
        "padding-top:15px;"
    );

    layout->addWidget(footer);

    // =========================
    // SIGNALS
    // =========================

    connect(
        dashboardBtn,
        &QPushButton::clicked,
        this,
        &SidebarWidget::dashboardClicked
    );

    connect(
        studentsBtn,
        &QPushButton::clicked,
        this,
        &SidebarWidget::studentsClicked
    );

    connect(
        teachersBtn,
        &QPushButton::clicked,
        this,
        &SidebarWidget::teachersClicked
    );

    connect(
        classBtn,
        &QPushButton::clicked,
        this,
        &SidebarWidget::classClicked
    );
    connect(
        resultsBtn,
        &QPushButton::clicked,
        this,
        &SidebarWidget::resultsClicked
    );
    connect(
        academicBtn,
        &QPushButton::clicked,
        this,
        &SidebarWidget::academicClicked
    );
    connect(
        attendanceBtn,
        &QPushButton::clicked,
        this,
        &SidebarWidget::attendanceClicked
    );
    connect(
        feesBtn,
        &QPushButton::clicked,
        this,
        &SidebarWidget::feesClicked
    );

    connect(
    settingsBtn,
    &QPushButton::clicked,
    this,
    &SidebarWidget::settingsClicked
);
}