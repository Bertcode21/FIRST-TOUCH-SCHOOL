#ifndef DASHBOARDWINDOW_H
#define DASHBOARDWINDOW_H

#include <QWidget>

class HeaderWidget;
class SidebarWidget;
class MainSectionWidget;

class DashboardWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DashboardWindow(QWidget *parent = nullptr);

private:
    void setupUI();

    HeaderWidget *headerWidget;
    SidebarWidget *sidebarWidget;
    MainSectionWidget *mainSectionWidget;
};

#endif