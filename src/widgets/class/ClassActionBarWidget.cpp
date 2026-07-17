#include "ClassActionBarWidget.h"


#include <QPushButton>
#include <QHBoxLayout>



ClassActionBarWidget::ClassActionBarWidget(
        QWidget *parent
    )
    : QWidget(parent)
{

    setupUI();

}



// Create buttons
void ClassActionBarWidget::setupUI()
{

    QHBoxLayout *layout =
            new QHBoxLayout(this);



    promoteButton =
            new QPushButton(
                "Promote",
                this
            );


    repeatButton =
            new QPushButton(
                "Repeat",
                this
            );


    transferButton =
            new QPushButton(
                "Transfer",
                this
            );


    expelButton =
            new QPushButton(
                "Expel",
                this
            );


    graduateButton =
            new QPushButton(
                "Graduate",
                this
            );


    printButton =
            new QPushButton(
                "Print List",
                this
            );


    exportButton =
            new QPushButton(
                "Export",
                this
            );



    layout->addWidget(promoteButton);

    layout->addWidget(repeatButton);

    layout->addWidget(transferButton);

    layout->addWidget(expelButton);

    layout->addWidget(graduateButton);

    layout->addWidget(printButton);

    layout->addWidget(exportButton);



    setLayout(layout);



    /*
        Button connections
    */


    connect(
        promoteButton,
        &QPushButton::clicked,
        this,
        &ClassActionBarWidget::promoteClicked
    );


    connect(
        repeatButton,
        &QPushButton::clicked,
        this,
        &ClassActionBarWidget::repeatClicked
    );


    connect(
        transferButton,
        &QPushButton::clicked,
        this,
        &ClassActionBarWidget::transferClicked
    );


    connect(
        expelButton,
        &QPushButton::clicked,
        this,
        &ClassActionBarWidget::expelClicked
    );


    connect(
        graduateButton,
        &QPushButton::clicked,
        this,
        &ClassActionBarWidget::graduateClicked
    );


    connect(
        printButton,
        &QPushButton::clicked,
        this,
        &ClassActionBarWidget::printClicked
    );


    connect(
        exportButton,
        &QPushButton::clicked,
        this,
        &ClassActionBarWidget::exportClicked
    );

}