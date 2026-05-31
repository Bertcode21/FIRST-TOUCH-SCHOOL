#include "WelcomeWindow.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QApplication>

WelcomeWindow::WelcomeWindow(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("First Touch School Management System");

    resize(900, 550);

    setStyleSheet(
        "background-color:#f5f7fa;"
    );

    // Title
    titleLabel = new QLabel(
        "FIRST TOUCH SCHOOL MANAGEMENT SYSTEM"
    );

    titleLabel->setAlignment(Qt::AlignCenter);

    titleLabel->setStyleSheet(
        "font-size:30px;"
        "font-weight:bold;"
        "color:#1e3a5f;"
        "margin-top:40px;"
    );

    // Subtitle
    subtitleLabel = new QLabel(
        "Offline Smart School Management Desktop Application"
    );

    subtitleLabel->setAlignment(Qt::AlignCenter);

    subtitleLabel->setStyleSheet(
        "font-size:16px;"
        "color:#555;"
        "margin-bottom:40px;"
    );

    // Start Button
    startButton = new QPushButton("NEXT");

    startButton->setMinimumHeight(55);

    startButton->setStyleSheet(
        "QPushButton{"
        "background-color:#1e88e5;"
        "color:white;"
        "font-size:18px;"
        "font-weight:bold;"
        "border-radius:10px;"
        "padding:12px;"
        "}"
        "QPushButton:hover{"
        "background-color:#1565c0;"
        "}"
    );

    // Exit Button
    exitButton = new QPushButton("EXIT");

    exitButton->setMinimumHeight(50);

    exitButton->setStyleSheet(
        "QPushButton{"
        "background-color:#e53935;"
        "color:white;"
        "font-size:16px;"
        "font-weight:bold;"
        "border-radius:10px;"
        "padding:10px;"
        "}"
        "QPushButton:hover{"
        "background-color:#c62828;"
        "}"
    );

    connect(
        exitButton,
        &QPushButton::clicked,
        qApp,
        &QApplication::quit
    );

    // Layout
    QVBoxLayout *layout = new QVBoxLayout();

    layout->addStretch();

    layout->addWidget(titleLabel);

    layout->addWidget(subtitleLabel);

    layout->addSpacing(30);

    layout->addWidget(startButton);

    layout->addWidget(exitButton);

    layout->addStretch();

    layout->setContentsMargins(120, 40, 120, 40);

    setLayout(layout);
}