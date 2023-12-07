/*
 * Developed by:    Methsara Perera
 * Course:          CSC 211H - Advanced Programming Techniques (Honors)
 * College:         Borough of Manhattan Community College, CUNY
 * Semester:        Fall 2023
 * Submitted on:    12/7/2023
 * Professor:       Dr. Azhar
 * Environment:     QT Framework 6.6.0 for Mac OS
 *                  DBeaver version 23.2.4.202311051706
 * Languages used:  C++, SQLite
 * Subject:         BMCC Accessible Education
 * Topic:           Automated Academic Guidance System: A Personalized Chatbot
*/
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
    void stepFive();
    QString getMessage();

private slots:
    void on_btn_login_clicked();
    void on_btn_send_clicked();
    void scrollDown();
    void on_btn_start_clicked();

private:
    Ui::Advisor *ui;
    Login login;
    QVBoxLayout *scrollAreaLayout;
    QTimer *scrollTimer;
    DatabaseManager *dbManager;
    bool program_status = false;
    QString message;
    QLabel *newLabel;
    int stepCounter = 0;
    Translator translate;
    int academicStatus = 0; // 0 = Not Started, 1 = Freshman, 2 = Continuing Student
    QVector<QString> takenClasses;
    DegreePath degreePath;
};

#endif // ADVISOR_H
