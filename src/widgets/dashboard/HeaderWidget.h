#ifndef HEADERWIDGET_H
#define HEADERWIDGET_H

#include <QFrame>

class QLabel;
class QPushButton;

class HeaderWidget : public QFrame
{
    Q_OBJECT

public:
    explicit HeaderWidget(QWidget *parent = nullptr);

signals:
    void logoutClicked();

private:
    QLabel *schoolNameLabel;
    QLabel *userLabel;

    QPushButton *notificationBtn;
    QPushButton *logoutBtn;
};

#endif 