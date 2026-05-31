#include "DashboardWindow.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>

#include "LoginWindow.h"
DashboardWindow::DashboardWindow(QWidget *parent)
    : QWidget(parent)
{
    setupUI();
}

/// Manage side 