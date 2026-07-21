//// FEES WIDGET HEADER
#ifndef FEESWIDGET_H
#define FEESWIDGET_H

#include <QWidget>

class QTableWidget;
class QPushButton;
class QLineEdit;

class FeesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FeesWidget(QWidget *parent = nullptr);

private slots:
    void loadFees();
    void searchFees();

    void addFee();
    void editFee();
    void recordPayment();

private:
    void setupUI();

    QLineEdit *searchEdit;

    QPushButton *searchBtn;
    QPushButton *refreshBtn;

    QPushButton *addBtn;
    QPushButton *editBtn;
    QPushButton *paymentBtn;

    QTableWidget *table;
};

#endif