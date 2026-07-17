#include "DashboardWindow.h"

#include <QVBoxLayout>
#include <QHBoxLayout>

#include "widgets/dashboard/HeaderWidget.h"
#include "widgets/dashboard/SidebarWidget.h"
#include "widgets/dashboard/MainSectionWidget.h"

#include "windows/LoginWindow.h"

DashboardWindow::DashboardWindow(QWidget *parent)
    : QWidget(parent)
{
    setupUI();
}

void DashboardWindow::setupUI()
{
    resize(1200, 700);
    setWindowTitle("School Admin Dashboard");

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    // ================= HEADER =================
    headerWidget = new HeaderWidget(this);

    // ================= BODY =================
    QHBoxLayout *bodyLayout = new QHBoxLayout();
    bodyLayout->setContentsMargins(0, 0, 0, 0);

    sidebarWidget = new SidebarWidget(this);
    mainSectionWidget = new MainSectionWidget(this);

    bodyLayout->addWidget(sidebarWidget);
    bodyLayout->addWidget(mainSectionWidget);

    mainLayout->addWidget(headerWidget);
    mainLayout->addLayout(bodyLayout);

    // ================= CONNECTIONS =================

    // Sidebar → Main Section navigation
    connect(sidebarWidget, &SidebarWidget::dashboardClicked,
            mainSectionWidget, &MainSectionWidget::showDashboard);

    connect(sidebarWidget, &SidebarWidget::studentsClicked,
            mainSectionWidget, &MainSectionWidget::showStudents);

    connect(sidebarWidget, &SidebarWidget::teachersClicked,
            mainSectionWidget, &MainSectionWidget::showTeachers);

    connect(sidebarWidget, &SidebarWidget::resultsClicked,
            mainSectionWidget, &MainSectionWidget::showResults);

    connect(sidebarWidget, &SidebarWidget::classClicked,
            mainSectionWidget, &MainSectionWidget::showClassManagement);

    connect(sidebarWidget, &SidebarWidget::feesClicked,
            mainSectionWidget, &MainSectionWidget::showFees);

     connect(sidebarWidget, &SidebarWidget::academicClicked, 
                   mainSectionWidget, &MainSectionWidget::showAcademicManagement);      

    connect(sidebarWidget, &SidebarWidget::attendanceClicked,
            mainSectionWidget, &MainSectionWidget::showAttendance);
    
    connect(sidebarWidget, &SidebarWidget::financeClicked,
            mainSectionWidget, &MainSectionWidget::showFinance);

    // Header → Logout
    connect(headerWidget, &HeaderWidget::logoutClicked,
            this, [=]()
    {
        this->close();

        LoginWindow *login = new LoginWindow();
        login->setAttribute(Qt::WA_DeleteOnClose);
        login->show();
    });

    // Default page
    mainSectionWidget->showDashboard();
}