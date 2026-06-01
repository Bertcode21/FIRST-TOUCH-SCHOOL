#include "HeaderWidget.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

HeaderWidget::HeaderWidget(QWidget *parent)
    : QFrame(parent)
{
    setFixedHeight(70);

    setStyleSheet(
        "QFrame{"
        "background:white;"
        "border-bottom:1px solid #e5e7eb;"
        "}"
    );

    auto *layout = new QHBoxLayout(this);

    schoolNameLabel =
        new QLabel("FIRST TOUCH SCHOOL");

    schoolNameLabel->setStyleSheet(
        "font-size:20px;"
        "font-weight:bold;"
        "color:#1e3a5f;"
    );

    userLabel =
        new QLabel("School Admin");

    notificationBtn =
        new QPushButton("🔔");

    logoutBtn =
        new QPushButton("Logout");

    layout->addWidget(schoolNameLabel);

    layout->addStretch();

    layout->addWidget(notificationBtn);
    layout->addWidget(userLabel);
    layout->addWidget(logoutBtn);

    connect(
        logoutBtn,
        &QPushButton::clicked,
        this,
        &HeaderWidget::logoutClicked
    );
}