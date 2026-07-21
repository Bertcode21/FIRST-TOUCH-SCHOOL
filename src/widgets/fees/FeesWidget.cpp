/// FEES WIDGET PAGE
#include "FeesWidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QTableWidget>
#include <QHeaderView>

#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

FeesWidget::FeesWidget(QWidget *parent)
    : QWidget(parent)
{
    setupUI();
    loadFees();
}

void FeesWidget::setupUI()
{
    auto *mainLayout = new QVBoxLayout(this);

    auto *topLayout = new QHBoxLayout;

    searchEdit = new QLineEdit;
    searchEdit->setPlaceholderText("Student ID or Name");

    searchBtn = new QPushButton("Search");
    refreshBtn = new QPushButton("Refresh");

    topLayout->addWidget(new QLabel("Search"));
    topLayout->addWidget(searchEdit);
    topLayout->addWidget(searchBtn);
    topLayout->addWidget(refreshBtn);

    table = new QTableWidget;

    table->setColumnCount(10);

    table->setHorizontalHeaderLabels({
        "Student ID",
        "Student",
        "Class",
        "Term",
        "Year",
        "Due",
        "Paid",
        "Balance",
        "Status",
        "Payment Date"
    });

    table->horizontalHeader()->setStretchLastSection(true);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    auto *buttonLayout = new QHBoxLayout;

    addBtn = new QPushButton("Add Fee");
    editBtn = new QPushButton("Edit");
    paymentBtn = new QPushButton("Record Payment");

    buttonLayout->addWidget(addBtn);
    buttonLayout->addWidget(editBtn);
    buttonLayout->addWidget(paymentBtn);
    buttonLayout->addStretch();

    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(table);
    mainLayout->addLayout(buttonLayout);

    connect(searchBtn,
            &QPushButton::clicked,
            this,
            &FeesWidget::searchFees);

    connect(refreshBtn,
            &QPushButton::clicked,
            this,
            &FeesWidget::loadFees);

    connect(addBtn,
            &QPushButton::clicked,
            this,
            &FeesWidget::addFee);

    connect(editBtn,
            &QPushButton::clicked,
            this,
            &FeesWidget::editFee);

    connect(paymentBtn,
            &QPushButton::clicked,
            this,
            &FeesWidget::recordPayment);
}

void FeesWidget::loadFees()
{
    // Will call FeeRepository::getAllFees()
}

void FeesWidget::searchFees()
{
    // Will call FeeRepository::searchFees(...)
}

void FeesWidget::addFee()
{
    // Open Add Fee dialog
}

void FeesWidget::editFee()
{
    // Open Edit Fee dialog
}

void FeesWidget::recordPayment()
{
    // Open Record Payment dialog
}