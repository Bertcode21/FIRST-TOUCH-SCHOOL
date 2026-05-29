#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QWidget>

class QLabel;
class QPushButton;

class WelcomeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit WelcomeWindow(QWidget *parent = nullptr);

private:
    QLabel *titleLabel;
    QLabel *subtitleLabel;

    QPushButton *startButton;
    QPushButton *exitButton;
};

#endif // WELCOMEWINDOW_H