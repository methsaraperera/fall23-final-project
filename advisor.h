#ifndef ADVISOR_H
#define ADVISOR_H

#include <QWidget>
#include "login.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QScrollBar>
#include <QTimer>
#include <set>


#include "databasemanager.h"
#include "translator.h"
#include "degreepath.h"


//#include "steps.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Advisor;
}
QT_END_NAMESPACE

class Advisor : public QWidget
{
    Q_OBJECT

public:
    Advisor(QWidget *parent = nullptr);
    ~Advisor();
    void printDegreePaths();
    void setProgramStatus();
    void printUserInput();
    void stepOne();
    void stepTwo();
    void stepThree();
    void stepFour();
    void backToStart();
    QString getMessage();


private slots:
    void on_btn_login_clicked();

    void on_btn_send_clicked();

    void scrollDown();

    //void on_pushButton_3_clicked();

    void on_btn_start_clicked();



private:
    Ui::Advisor *ui;
    Login login;
    QVBoxLayout *scrollAreaLayout;
    int labelCounter;
    QTimer *scrollTimer;
    //QStringList labelContents;
    DatabaseManager *dbManager;
    bool program_status = false;
    QString message;
    QLabel *newLabel;
    int stepCounter = 0;
    Translator translate;
    //int degreePath;
    int academicStatus = 0; // 0 = Not Started, 1 = Freshman, 2 = Continuing Student
    QVector<QString> takenClasses;
    DegreePath degreePath;
    //Steps step;


};

#endif // ADVISOR_H
