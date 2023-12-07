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
#include <iostream>
#include "advisor.h"
#include "./ui_advisor.h"

#include <sstream>


using namespace std;

Advisor::Advisor(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Advisor)
{
    ui->setupUi(this);
    scrollAreaLayout = new QVBoxLayout(ui->scrollAreaWidgetContents);
    ui->scrollAreaWidgetContents->setLayout(scrollAreaLayout);
    // Set the scroll area to automatically scroll to the bottom
    ui->scrollArea->setWidgetResizable(true);
    // Initialize the timer for scrolling
    scrollTimer = new QTimer(this);
    connect(scrollTimer, SIGNAL(timeout()), this, SLOT(scrollDown()));
    setProgramStatus();
}

Advisor::~Advisor()
{
    delete ui;
}

void Advisor::on_btn_login_clicked()
{
    login.show();
}


void Advisor::on_btn_send_clicked()
{
    printUserInput();
    ui->txt_message->clear();
    switch(stepCounter){
    case 1:
        stepOne();
        break;
    case 2:
        stepTwo();
        break;
    case 3:
        stepThree();
        break;
    case 4:
        stepFour();
        break;
    }
}

void Advisor::scrollDown()
{
    // Scroll to the bottom of the scroll area
    ui->scrollArea->verticalScrollBar()->setValue(ui->scrollArea->verticalScrollBar()->maximum());
    // Stop the timer
    scrollTimer->stop();
}

void Advisor::on_btn_start_clicked()
{
    program_status = true;
    setProgramStatus();

    ui->group_start_screen->hide();

    QLabel *newLabel = new QLabel;
    newLabel->setText("ADVISOR\n\n"
                      "Are you a Freshman or a Continuing Student?"
                      "\nEnter:"
                      "\n\tFreshman"
                      "\n\tContinuing Student");

    newLabel->setWordWrap(true);
    newLabel->setStyleSheet("border: 1px solid; border-color: rgb(175, 193, 220); padding: 5px;");
    scrollAreaLayout->addWidget(newLabel);

    scrollTimer->start(10);
    stepCounter = 1;
}

void Advisor::setProgramStatus(){
    if(program_status == false){
        ui->btn_send->setEnabled(false);
    }
    else{
        ui->btn_send->setEnabled(true);
    }
}

void Advisor::printUserInput(){
    message = ui->txt_message->toPlainText();

    QLabel *userLabel = new QLabel;
    userLabel->setText("USER\n\n" + message);
    userLabel->setWordWrap(true);
    userLabel->setStyleSheet("border: 1px solid; border-color: rgb(175, 193, 220); padding: 5px;");
    scrollAreaLayout->addWidget(userLabel);
}


QString Advisor::getMessage(){
    return message;
}

void Advisor::stepOne(){
    try {
        qDebug() << "Step";
        qDebug() << stepCounter;
        if(message.toLower() == "freshman"){
            academicStatus = 1;
            qDebug() << "AS: ";
            qDebug() << academicStatus;
        }
        else if(message.toLower() == "continuing student"){
            academicStatus = 2;
            qDebug() << "AS: ";
            qDebug() << academicStatus;
        }

        DatabaseManager dbManager;
        if (dbManager.openDatabase()) {
            dbManager.loadDegreePaths();

            QLabel *newLabel = new QLabel;
            newLabel->setText("ADVISOR\n\n"
                              +dbManager.getDegreePathsAsString()
                              +"\nEnter the Degree Path ID");

            newLabel->setWordWrap(true);
            newLabel->setStyleSheet("border: 1px solid; border-color: rgb(175, 193, 220); padding: 5px;");
            scrollAreaLayout->addWidget(newLabel);

            scrollTimer->start(10);
            dbManager.closeDatabase();
            stepCounter = 2;
        }
    }
    catch (const std::exception &e) {
        QLabel *newLabel = new QLabel;
        qDebug() << "Exception in stepOne: " << e.what();
        newLabel->setText(QString("SYSTEM\n\n"
                                  "Exception in stepOne: %1").arg(e.what()));

        newLabel->setWordWrap(true);
        newLabel->setStyleSheet("border: 1px solid; border-color: rgb(175, 193, 220); padding: 5px;");
        scrollAreaLayout->addWidget(newLabel);

        scrollTimer->start(10);
    }
}




void Advisor::stepTwo(){
    try {
        qDebug() << "Step";
        qDebug() << stepCounter;
        degreePath.setSelectedPath(translate.translateStringToInt(message));
        QLabel *newLabel = new QLabel;
        DatabaseManager dbManager;

        if(academicStatus == 1){
            if (degreePath.getSelectedPath() == 1) {
                newLabel->setText("ADVISOR\n\nYou have selected the degree path Computer Information Systems\n"
                                  "\nFor your first semester at BMCC as a CIS student you should plan to take:\n"
                                  "\n\tBUS 104  Introduction to Business"
                                  "\n\tACC 122  Accounting Principles I"
                                  "\n\tCSC 101  Principles in Information Technology and Computation"
                                  "\n\tENG 101  English Composition"
                                  "\n\tSPE 100  Fundamentals of Public Speaking"
                                  "\n\n**During your program you MUST take at least ONE Writing Intensive (WI) course"
                                  "\nSPE 102 is an option for non-native speakers of English. "
                                  "\nCSC 101 and MAT 206.5 are prerequisite courses to CSC 111. Students are strongly encouraged to take both courses in their first semester."
                                  );
            }

            else if (degreePath.getSelectedPath() == 2) {
                newLabel->setText("ADVISOR\n\nYou have selected the degree path Computer Network Technology\n"
                                  "\nFor your first semester at BMCC as a CNT student you should plan to take:\n"
                                  "\n\tENG 101  English Composition"
                                  "\n\tMAT 150  Introduction to Statistics"
                                  "\n\tCSC 101  Principles in Information Technology and Computation"
                                  "\n\tACC 122  Accounting Principles I"
                                  "\n\tBUS 104  Introduction to Business"
                                  "\n\n**During your program you MUST take at least ONE Writing Intensive (WI) course"
                                  "\nCSC 101 should be taken in the first semester as it is a prerequisite course for CSC 110 and CIS 165"
                                  );
            }

            else if (degreePath.getSelectedPath() == 3) {
                newLabel->setText("ADVISOR\n\nYou have selected the degree path Computer Science\n"
                                  "\nFor your first semester at BMCC as a CSC student you should plan to take:\n"
                                  "\n\tMAT 206.5  Intermediate Algebra and Precalculus"
                                  "\n\tENG 101      English Composition"
                                  "\n\tCSC 101      Principles in Information Technology and Computation"
                                  "\n\tXXX xxx      Individual and Society"
                                  "\n\tXXX xxx      U.S. Experience in Its Diversity"
                                  "\n\n**During your program you MUST take at least ONE Writing Intensive (WI) course"
                                  "\nCSC 101 should be taken in the first semester as it is a prerequisite course for CSC 110"
                                  );
            }
            else if (degreePath.getSelectedPath() == 4) {
                newLabel->setText("ADVISOR\n\nYou have selected the degree path Computer Science\n"
                                  "\nFor your first semester at BMCC as a CSC student you should plan to take:\n"
                                  "\n\tENG 101      English Composition"
                                  "\n\tCSC 101      Principles in Information Technology and Computation"
                                  "\n\tMAT 206.5  Intermediate Algebra and Precalculus"
                                  "\n\tGLY210       Geology I"
                                  "\n\tGEO 100      Introduction to Human Geography"
                                  "\n\n**During your program you MUST take at least ONE Writing Intensive (WI) course"
                                  "\nCSC 101 should be taken in the first semester as it is a prerequisite course for CSC 110"
                                  );
            }
            else {
                newLabel->setText("ADVISOR\n\nPlease enter a valid message to continue.");
            }
        }

        else if(academicStatus == 2){
            newLabel->setText("ADVISOR\n\n"
                              "\n\nWhich term you want to know the classes?"
                              "\n\t1 - Semester 1"
                              "\n\t2 - Semester 2"
                              "\n\t3 - Semester 3"
                              "\n\t4 - Semester 4"
                              );
        }

        else {
            newLabel->setText("ADVISOR\n\nPlease enter a valid message to continue.");

        }

        newLabel->setWordWrap(true);
        newLabel->setStyleSheet("border: 1px solid; border-color: rgb(175, 193, 220); padding: 5px;");
        scrollAreaLayout->addWidget(newLabel);

        scrollTimer->start(10);

        int id = translate.translateStringToInt(message);
        qDebug() << id;
        stepCounter = 3;
    }
    catch (const std::exception &e) {
        QLabel *newLabel = new QLabel;
        qDebug() << "Exception in stepTwo: " << e.what();
        newLabel->setText(QString("SYSTEM\n\n"
                                  "Exception in stepTwo: %1").arg(e.what()));

        newLabel->setWordWrap(true);
        newLabel->setStyleSheet("border: 1px solid; border-color: rgb(175, 193, 220); padding: 5px;");
        scrollAreaLayout->addWidget(newLabel);

        scrollTimer->start(10);
    }
}

void Advisor::stepThree(){
    try {
        QLabel *newLabel = new QLabel;
        degreePath.setSemester(translate.translateStringToInt(message));
        if (academicStatus==2){
            if(degreePath.getSemester()==1){
                if(degreePath.getSelectedPath()==3){
                    newLabel->setText("ADVISOR\n\nYou have selected the degree path Computer Science\n"
                                      "\nFor your first semester at BMCC as a CSC student you should plan to take:\n"
                                      "\n\tMAT 206.5  Intermediate Algebra and Precalculus"
                                      "\n\tENG 101      English Composition"
                                      "\n\tCSC 101      Principles in Information Technology and Computation"
                                      "\n\tXXX xxx      Individual and Society"
                                      "\n\tXXX xxx      U.S. Experience in Its Diversity"
                                      "\n\n**During your program you MUST take at least ONE Writing Intensive (WI) course"
                                      "\nCSC 101 should be taken in the first semester as it is a prerequisite course for CSC 110"
                                      );
                }
            }

            if(degreePath.getSemester()==2){
                if(degreePath.getSelectedPath()==3){
                    newLabel->setText("ADVISOR\n\nYou have selected the degree path Computer Science\n"
                                      "\nFor your second semester at BMCC as a CSC student you should plan to take:\n"
                                      "\n\tENG 201      Introduction to Literature"
                                      "\n\tCSC 111      Introduction to Programming"
                                      "\n\tMAT 301      Analytic Geometry and Calculus I"
                                      "\n\tSPE 100      Fundamentals of Public Speaking"
                                      "\n\tXXX xxx      U.S. Experience in Its Diversity"
                                      "\n\n**During your program you MUST take at least ONE Writing Intensive (WI) course"
                                      "\nCSC 101 should be taken in the first semester as it is a prerequisite course for CSC 110"
                                      "\nStudents are required to take MAT 206.5. MAT 206.5 is a combination course of Intermediate Algebra and Trigonometry and Precalculus and will help to fulfill"
                                      " the General Elective requirement of which 6 credits are required. The remaining 2 credits can be satisfied by taking STEM variants in the Common Core."
                                      "\nCSC 101 and MAT 206.5 are prerequisite courses to CSC 111."
                                      "\nMAT 206.5 must be passed in order to take MAT 301."
                                      "\nSPE 102 is an option for non-native speakers of English."
                                      "\nPHY 215 has a co-requisite course of MAT 302."
                                      "\nMAT 301 must be passed in order to take MAT 302."
                                      "\nCSC 111 must be passed in order to take CSC 211 and CSC 215."
                                      "\nCSC 111 and MAT 301 must be passed in order to take CSC 231."
                                      );
                }
            }

            if(degreePath.getSemester()==3){
                if(degreePath.getSelectedPath()==3){
                    newLabel->setText("ADVISOR\n\nYou have selected the degree path Computer Science\n"
                                      "\nFor your third semester at BMCC as a CSC student you should plan to take:\n"
                                      "\n\tPHY 215      University Physics I"
                                      "\n\tMAT 302      Analytic Geometry and Calculus II"
                                      "\n\tCSC 211      Advanced Programming Techniques"
                                      "\n\tCSC 231      Discrete Structures and Applications to Computer Science"
                                      "\n\tXXX xxx      Program Elective"
                                      "\n\n**During your program you MUST take at least ONE Writing Intensive (WI) course"
                                      "\nCSC 101 should be taken in the first semester as it is a prerequisite course for CSC 110"
                                      "\nStudents are required to take MAT 206.5. MAT 206.5 is a combination course of Intermediate Algebra and Trigonometry and Precalculus and will help to fulfill"
                                      " the General Elective requirement of which 6 credits are required. The remaining 2 credits can be satisfied by taking STEM variants in the Common Core."
                                      "\nCSC 101 and MAT 206.5 are prerequisite courses to CSC 111."
                                      "\nMAT 206.5 must be passed in order to take MAT 301."
                                      "\nSPE 102 is an option for non-native speakers of English."
                                      "\nPHY 215 has a co-requisite course of MAT 302."
                                      "\nMAT 301 must be passed in order to take MAT 302."
                                      "\nCSC 111 must be passed in order to take CSC 211 and CSC 215."
                                      "\nCSC 111 and MAT 301 must be passed in order to take CSC 231."
                                      "\nA total of 6 credits are needed. Choose 2 from CIS 317, CIS 345, CIS 359, CIS 362, CIS 364, CIS 385, CIS 395, CSC 103, GIS 201, or CIS 316."
                                      "\nCSC 211 and CSC 231 must be passed in order to take CSC 331."
                                      "\nCSC 211 must be passed in order to take CSC 350."
                                      );
                }
            }

            if(degreePath.getSemester()==4){
                if(degreePath.getSelectedPath()==3){
                    newLabel->setText("ADVISOR\n\nYou have selected the degree path Computer Science\n"
                                      "\nFor your fourth semester at BMCC as a CSC student you should plan to take:\n"
                                      "\n\tCSC 215      Fundamentals of Computer Systems"
                                      "\n\tCSC 331      Data Structures"
                                      "\n\tCSC 350      Software Development"
                                      "\n\tXXX xxx      Program Elective1"
                                      "\n\tXXX xxx      World Cultures and Global Issues"
                                      "\n\n**During your program you MUST take at least ONE Writing Intensive (WI) course"
                                      "\nCSC 101 should be taken in the first semester as it is a prerequisite course for CSC 110"
                                      "\nStudents are required to take MAT 206.5. MAT 206.5 is a combination course of Intermediate Algebra and Trigonometry and Precalculus and will help to fulfill"
                                      " the General Elective requirement of which 6 credits are required. The remaining 2 credits can be satisfied by taking STEM variants in the Common Core."
                                      "\nCSC 101 and MAT 206.5 are prerequisite courses to CSC 111."
                                      "\nMAT 206.5 must be passed in order to take MAT 301."
                                      "\nSPE 102 is an option for non-native speakers of English."
                                      "\nPHY 215 has a co-requisite course of MAT 302."
                                      "\nMAT 301 must be passed in order to take MAT 302."
                                      "\nCSC 111 must be passed in order to take CSC 211 and CSC 215."
                                      "\nCSC 111 and MAT 301 must be passed in order to take CSC 231."
                                      "\nA total of 6 credits are needed. Choose 2 from CIS 317, CIS 345, CIS 359, CIS 362, CIS 364, CIS 385, CIS 395, CSC 103, GIS 201, or CIS 316."
                                      "\nCSC 211 and CSC 231 must be passed in order to take CSC 331."
                                      "\nCSC 211 must be passed in order to take CSC 350."
                                      );
                }
            }
        }

        newLabel->setWordWrap(true);
        newLabel->setStyleSheet("border: 1px solid; border-color: rgb(175, 193, 220); padding: 5px;");
        scrollAreaLayout->addWidget(newLabel);

        scrollTimer->start(10);

        stepCounter = 4;
    }
    catch (const std::exception &e) {
        QLabel *newLabel = new QLabel;
        qDebug() << "Exception in stepThree: " << e.what();
        newLabel->setText(QString("SYSTEM\n\n"
                                  "Exception in stepThree: %1").arg(e.what()));

        newLabel->setWordWrap(true);
        newLabel->setStyleSheet("border: 1px solid; border-color: rgb(175, 193, 220); padding: 5px;");
        scrollAreaLayout->addWidget(newLabel);

        scrollTimer->start(10);
    }
}


void Advisor::stepFour() {
    try {
        if (academicStatus == 2) {
            QVector<std::shared_ptr<ClassPrerequisites>> unsatisfiedClasses = dbManager->getClassPrerequisites();

            QLabel *newLabel = new QLabel;
            dbManager->loadDegreePaths();

            if(dbManager->openDatabase()) {
                if (!unsatisfiedClasses.isEmpty()) {
                    newLabel->setText("ADVISOR\n\nUnsatisfied classes to take:\n\t" + dbManager->getRequiredClassesAsString());
                } else {
                    newLabel->setText("ADVISOR\n\nCongratulations! You have completed all required classes for the selected degree path.");
                }
            }
            newLabel->setWordWrap(true);
            newLabel->setStyleSheet("border: 1px solid; border-color: rgb(175, 193, 220); padding: 5px;");
            scrollAreaLayout->addWidget(newLabel);

            scrollTimer->start(10);
        }
    }
    catch (const std::exception &e) {
        QLabel *newLabel = new QLabel;
        qDebug() << "Exception in stepFour: " << e.what();
        newLabel->setText(QString("SYSTEM\n\n"
                                  "Exception in stepFour: %1").arg(e.what()));

        newLabel->setWordWrap(true);
        newLabel->setStyleSheet("border: 1px solid; border-color: rgb(175, 193, 220); padding: 5px;");
        scrollAreaLayout->addWidget(newLabel);

        scrollTimer->start(10);
    }
}
