#include "MainSectionWidget.h"
#include "widgets/students/StudentsWidget.h"
#include "widgets/teachers/TeachersWidget.h"
#include "widgets/class/ClassWidget.h"
#include "models/Class.h"
#include "widgets/fees/FeesWidget.h"
#include "widgets/class/ClassDetailsWidget.h"

#include <QStackedWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

#include <QFrame>
#include <QLabel>
#include <QPushButton>

MainSectionWidget::MainSectionWidget(QWidget *parent)
    : QWidget(parent)
{
    setupUI();
}

void MainSectionWidget::setupUI()
{
    setStyleSheet(
        "background-color:#F8FAFC;"
    );

    QVBoxLayout *mainLayout =
        new QVBoxLayout(this);

    stack = new QStackedWidget(this);

    // ====================================
    // DASHBOARD PAGE
    // ====================================

    QWidget *dashboardPage =
        new QWidget();

    QVBoxLayout *dashboardLayout =
        new QVBoxLayout(dashboardPage);

    // Welcome Section

    QLabel *welcomeLabel =
        new QLabel("Welcome Back, School Admin");

    welcomeLabel->setStyleSheet(
        "font-size:24px;"
        "font-weight:bold;"
        "color:#1E3A8A;"
    );

    QLabel *subTitle =
        new QLabel(
            "Manage your school efficiently today"
        );

    subTitle->setStyleSheet(
        "font-size:14px;"
        "color:#64748B;"
    );

    dashboardLayout->addWidget(welcomeLabel);
    dashboardLayout->addWidget(subTitle);

    dashboardLayout->addSpacing(20);

    // ====================================
    // STATISTICS CARDS
    // ====================================

    QGridLayout *cardsLayout =
        new QGridLayout();

    QString cardStyle =
        "QFrame{"
        "background:white;"
        "border-radius:15px;"
        "padding:15px;"
        "border:1px solid #E2E8F0;"
        "}";

    auto createCard =
        [&](QString title,
            QString value,
            QString color)
    {
        QFrame *card = new QFrame();

        card->setStyleSheet(cardStyle);

        QVBoxLayout *layout =
            new QVBoxLayout(card);

        QLabel *titleLabel =
            new QLabel(title);

        titleLabel->setStyleSheet(
            "font-size:14px;"
            "color:#64748B;"
        );

        QLabel *valueLabel =
            new QLabel(value);

        valueLabel->setStyleSheet(
            QString(
                "font-size:30px;"
                "font-weight:bold;"
                "color:%1;"
            ).arg(color)
        );

        layout->addWidget(titleLabel);
        layout->addWidget(valueLabel);

        return card;
    };

    cardsLayout->addWidget(
        createCard("Students", "1245", "#3B82F6"),
        0, 0
    );

    cardsLayout->addWidget(
        createCard("Teachers", "56", "#10B981"),
        0, 1
    );

    cardsLayout->addWidget(
        createCard("Classes", "24", "#7C3AED"),
        0, 2
    );

    cardsLayout->addWidget(
        createCard("Results", "5432", "#EF4444"),
        0, 3
    );

    dashboardLayout->addLayout(cardsLayout);

    dashboardLayout->addSpacing(20);

    // ====================================
    // BOTTOM SECTION
    // ====================================

    QHBoxLayout *bottomLayout =
        new QHBoxLayout();

    // Recent Activities

    QFrame *activityCard =
        new QFrame();

    activityCard->setStyleSheet(cardStyle);

    QVBoxLayout *activityLayout =
        new QVBoxLayout(activityCard);

    QLabel *activityTitle =
        new QLabel("Recent Activities");

    activityTitle->setStyleSheet(
        "font-size:18px;"
        "font-weight:bold;"
    );

    activityLayout->addWidget(activityTitle);

    activityLayout->addWidget(
        new QLabel("• New Student Registered")
    );

    activityLayout->addWidget(
        new QLabel("• Results Uploaded")
    );

    activityLayout->addWidget(
        new QLabel("• Teacher Added")
    );

    activityLayout->addStretch();

    // Quick Actions

    QFrame *actionCard =
        new QFrame();

    actionCard->setStyleSheet(cardStyle);

    QVBoxLayout *actionLayout =
        new QVBoxLayout(actionCard);

    QLabel *actionTitle =
        new QLabel("Quick Actions");

    actionTitle->setStyleSheet(
        "font-size:18px;"
        "font-weight:bold;"
    );

    QPushButton *addStudentBtn =
        new QPushButton("Add Student");

    QPushButton *addTeacherBtn =
        new QPushButton("Add Teacher");

    QPushButton *uploadResultsBtn =
        new QPushButton("Upload Results");

    QString btnStyle =
        "QPushButton{"
        "background:qlineargradient("
        "x1:0,y1:0,x2:1,y2:0,"
        "stop:0 #3B82F6,"
        "stop:1 #7C3AED);"
        "color:white;"
        "padding:10px;"
        "border:none;"
        "border-radius:8px;"
        "font-weight:bold;"
        "}";

    addStudentBtn->setStyleSheet(btnStyle);
    addTeacherBtn->setStyleSheet(btnStyle);
    uploadResultsBtn->setStyleSheet(btnStyle);

    actionLayout->addWidget(actionTitle);
    actionLayout->addWidget(addStudentBtn);
    actionLayout->addWidget(addTeacherBtn);
    actionLayout->addWidget(uploadResultsBtn);
    actionLayout->addStretch();

    bottomLayout->addWidget(activityCard);
    bottomLayout->addWidget(actionCard);

    dashboardLayout->addLayout(bottomLayout);

    // ====================================
    // OTHER PAGES
    // ====================================

    // QWidget *studentsPage = new QWidget();
    // QWidget *teachersPage = new QWidget();
    QWidget *resultsPage = new QWidget();
    QWidget *academicManagementPage = new QWidget();
    QWidget *attendancePage = new QWidget();

    ////sample fees widget
   /// QWidget *feesPage = new QWidget(); //// to be commented later or removed
    QWidget *financePage = new QWidget();
    QWidget *settingsPage = new QWidget();

    // QVBoxLayout *stuLayout =
    //     new QVBoxLayout(studentsPage);

    // stuLayout->addWidget(
    //     new QLabel("Students Module")
    // );

    /// Students Page
    StudentsWidget *studentsPage =
    new StudentsWidget();

    /// Teachers Page
    TeachersWidget *teachersPage =
        new TeachersWidget();

    /// Class Management Page
    ClassWidget *classManagementPage =
        new ClassWidget();
        connect(
    classManagementPage,
    &ClassWidget::openClassRequested,
    this,
    [=](Class selectedClass)
    {

        qDebug()
        << "Opening class details:"
        << selectedClass.className;


        ClassDetailsWidget *details =
            new ClassDetailsWidget(
                selectedClass
            );


        stack->addWidget(details);


        stack->setCurrentWidget(
            details
        );

    }
);

    /// Fees Page
    FeesWidget *feesPage =
        new FeesWidget();

    // QVBoxLayout *teaLayout =
    //     new QVBoxLayout(teachersPage);

    // teaLayout->addWidget(
    //     new QLabel("Teachers Module")
    // ); to be checked

    QVBoxLayout *resLayout =
        new QVBoxLayout(resultsPage);

    resLayout->addWidget(
        new QLabel("Results Module")
    );
   
    QVBoxLayout *acadLayout =
        new QVBoxLayout(academicManagementPage);

        acadLayout->addWidget(
            new QLabel("Academic Management Module")
        );

    QVBoxLayout *attLayout =
        new QVBoxLayout(attendancePage);
        attLayout->addWidget(
            new QLabel("Attendance Module")
        );
     QVBoxLayout *finLayout =
        new QVBoxLayout(financePage);
        finLayout->addWidget(
            new QLabel("Finance Module")
        );

    QVBoxLayout *settLayout =
        new QVBoxLayout(settingsPage);
        settLayout->addWidget(
            new QLabel("Settings Module")
        );

    stack->addWidget(dashboardPage);
    stack->addWidget(studentsPage);
    stack->addWidget(teachersPage);
    stack->addWidget(resultsPage);
    stack->addWidget(classManagementPage);
    stack->addWidget(academicManagementPage);
    stack->addWidget(feesPage);
    stack->addWidget(attendancePage);
    stack->addWidget(financePage);
    stack->addWidget(settingsPage);

    mainLayout->addWidget(stack);
}

void MainSectionWidget::showDashboard()
{
    stack->setCurrentIndex(0);
}

void MainSectionWidget::showStudents()
{
    stack->setCurrentIndex(1);
}

void MainSectionWidget::showTeachers()
{
    stack->setCurrentIndex(2);
}

void MainSectionWidget::showResults()
{
    stack->setCurrentIndex(3);
}

void MainSectionWidget::showClassManagement()
{
    stack->setCurrentIndex(4);
}
void MainSectionWidget::showAcademicManagement()
{
    stack->setCurrentIndex(5);
}

void MainSectionWidget::showFees()
{
    stack->setCurrentIndex(6);
}
void MainSectionWidget::showAttendance()
{
    stack->setCurrentIndex(7);
    
}
void MainSectionWidget::showFinance()
{
    stack->setCurrentIndex(8);
}

void MainSectionWidget::showSettings()
{
    stack->setCurrentIndex(9);
}