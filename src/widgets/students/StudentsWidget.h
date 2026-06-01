#ifndef STUDENTSWIDGET_H
#define STUDENTSWIDGET_H

#include <QWidget>
#include <QString>
#include <QTableWidget>
#include <QLineEdit>
#include <QPushButton>

class StudentsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StudentsWidget(QWidget *parent = nullptr);

private:
    void setupUI();
    void loadStudents();
    void clearForm();
    void fillForm(int row);   // optional but MUST be implemented if kept

    QString generateStudentId();

private:
    // ================= FORM INPUTS =================
    QLineEdit *firstNameInput;
    QLineEdit *lastNameInput;
    QLineEdit *genderInput;
    QLineEdit *dobInput;
    QLineEdit *classInput;
    QLineEdit *phoneInput;
    QLineEdit *parentNameInput;
    QLineEdit *parentPhoneInput;
    QLineEdit *addressInput;

    // ================= BUTTONS =================
    QPushButton *registerBtn;
    QPushButton *updateBtn;
    QPushButton *suspendBtn;
    QPushButton *graduateBtn;
    QPushButton *activateBtn;
    QPushButton *inactiveBtn;
    QPushButton *clearBtn;

    // ================= TABLE =================
    QTableWidget *studentTable;

    // selected DB ID
    int selectedStudentId = -1;
};

#endif // STUDENTSWIDGET_H