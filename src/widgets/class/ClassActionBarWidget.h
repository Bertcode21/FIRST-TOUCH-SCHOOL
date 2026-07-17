#ifndef CLASSACTIONBARWIDGET_H
#define CLASSACTIONBARWIDGET_H


#include <QWidget>


class QPushButton;



class ClassActionBarWidget : public QWidget
{

    Q_OBJECT


public:


    explicit ClassActionBarWidget(
        QWidget *parent = nullptr
    );



signals:


    void promoteClicked();

    void repeatClicked();

    void transferClicked();

    void expelClicked();

    void graduateClicked();

    void printClicked();

    void exportClicked();



private:


    void setupUI();



private:


    QPushButton *promoteButton;

    QPushButton *repeatButton;

    QPushButton *transferButton;

    QPushButton *expelButton;

    QPushButton *graduateButton;

    QPushButton *printButton;

    QPushButton *exportButton;



};


#endif // CLASSACTIONBARWIDGET_H