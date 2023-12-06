#include <iostream>
#include "advisor.h"
#include "./ui_advisor.h"

#include <sstream>


using namespace std;

Advisor::Advisor(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Advisor)
    , labelCounter(1)



{
    ui->setupUi(this);

    //connect(ui->btn_send, SIGNAL(clicked()), this, SLOT(on_btn_send_clicked()));
    scrollAreaLayout = new QVBoxLayout(ui->scrollAreaWidgetContents);
    ui->scrollAreaWidgetContents->setLayout(scrollAreaLayout);

    //ui->scrollAreaWidgetContents->setLayout(scrollAreaLayout);

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

    labelCounter++;


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
                      "Are you a Freshman or a Continuing Student?");

    newLabel->setWordWrap(true);
    newLabel->setStyleSheet("border: 1px solid; border-color: rgb(175, 193, 220); padding: 5px;");
    scrollAreaLayout->addWidget(newLabel);
    //labelCounter++;

    // Start the timer to scroll down after a short delay
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
        //qDebug().noquote() << dbManager.getDegreePathsAsString();

        QLabel *newLabel = new QLabel;
        newLabel->setText("ADVISOR\n\n"
                          +dbManager.getDegreePathsAsString()
                          +"\nEnter the Degree Path ID");

        newLabel->setWordWrap(true);
        newLabel->setStyleSheet("border: 1px solid; border-color: rgb(175, 193, 220); padding: 5px;");
        scrollAreaLayout->addWidget(newLabel);
        //labelCounter++;

        // Start the timer to scroll down after a short delay
        scrollTimer->start(10);
        dbManager.closeDatabase();
        stepCounter = 2;
    }
}




void Advisor::stepTwo(){

    qDebug() << "Step";
    qDebug() << stepCounter;
    degreePath.setSelectedPath(translate.translateStringToInt(message));


    QLabel *newLabel = new QLabel;
    DatabaseManager dbManager;

    if(academicStatus == 1){
        if (degreePath.getSelectedPath() == 1) {
            newLabel->setText("ADVISOR\n\nYou have selected the degree path Computer Information Systems\n"
                              "\nFor your first semester at BMCC as a CIS student you should plan to take:\n"
                              "\nBUS 104  Introduction to Business"
                              "\nACC 122  Accounting Principles I"
                              "\nCSC 101  Principles in Information Technology and Computation"
                              "\nENG 101  English Composition"
                              "\nSPE 100  Fundamentals of Public Speaking"
                              "\n\n**During your program you MUST take at least ONE Writing Intensive (WI) course"
                              "\nCSC 101 and MAT 206.5 are prerequisite courses to CSC 111. Students are strongly encouraged to take both courses in their first semester."
                              );

        }

        else if (degreePath.getSelectedPath() == 2) {
            newLabel->setText("ADVISOR\n\nYou have selected the degree path Computer Network Technology\n"
                              "\nFor your first semester at BMCC as a CNT student you should plan to take:\n"
                              "\nENG 101  English Composition"
                              "\nMAT 150  Introduction to Statistics"
                              "\nCSC 101  Principles in Information Technology and Computation"
                              "\nACC 122  Accounting Principles I"
                              "\nBUS 104  Introduction to Business"
                              "\n\n**During your program you MUST take at least ONE Writing Intensive (WI) course"
                              "\nCSC 101 should be taken in the first semester as it is a prerequisite course for CSC 110 and CIS 165"
                              );

        }

        else if (degreePath.getSelectedPath() == 3) {
            newLabel->setText("ADVISOR\n\nYou have selected the degree path Computer Science\n"
                              "\nFor your first semester at BMCC as a CSC student you should plan to take:\n"
                              "\nMAT 206.5  Intermediate Algebra and Precalculus"
                              "\nENG 101      English Composition"
                              "\nCSC 101      Principles in Information Technology and Computation"
                              "\nXXX xxx      Individual and Society"
                              "\nXXX xxx      U.S. Experience in Its Diversity"
                              "\n\n**During your program you MUST take at least ONE Writing Intensive (WI) course"
                              "\nCSC 101 should be taken in the first semester as it is a prerequisite course for CSC 110"
                              );

        }
        else if (degreePath.getSelectedPath() == 4) {
            newLabel->setText("ADVISOR\n\nYou have selected the degree path Computer Science\n"
                              "\nFor your first semester at BMCC as a CSC student you should plan to take:\n"
                              "\nENG 101      English Composition"
                              "\nCSC 101      Principles in Information Technology and Computation"
                              "\nMAT 206.5  Intermediate Algebra and Precalculus"
                              "\nGLY210       Geology I"
                              "\nGEO 100      Introduction to Human Geography"
                              "\n\n**During your program you MUST take at least ONE Writing Intensive (WI) course"
                              "\nCSC 101 should be taken in the first semester as it is a prerequisite course for CSC 110"
                              );

        }
        else {
            newLabel->setText("ADVISOR\n\nPlease enter a valid message to continue.");

        }

    }


    else if(academicStatus == 2){

        if(dbManager.openDatabase()){
            dbManager.loadRequiredClasses(degreePath.getSelectedPath());
            newLabel->setText("ADVISOR\n\n"
                              +dbManager.getRequiredClassesAsString()
                              +"\n\nWhat are the classes you have taken so far?"
                              "\nEnter every class you have taken pass by a comma \",\""
                              "\n\tex: XXXxxx, XXXxxx");
            //newLabel->setText("ADVISOR\n\nWhat are the classes you have taken so far?"
            //                  "\nEnter every class you have taken pass by a comma \",\""
            //                  "\n\nex: XXXxxx, XXXxxx");
        }

        dbManager.closeDatabase();
    }

    else {
        newLabel->setText("ADVISOR\n\nPlease enter a valid message to continue.");

    }

/*
    else if (degreePath == 2) {
        if(academicStatus == 1){
            //DatabaseManager dbManager;
            if (dbManager.openDatabase()) {


                //dbManager.loadClasses(1,2);
                //qDebug().noquote() << dbManager.getDegreePathsAsString();

                QLabel *newLabel = new QLabel;
                newLabel->setText("ADVISOR\n\n"
                                  +dbManager.getClassesAsString()
                                  +"\nEnter the Degree Path ID");

                newLabel->setWordWrap(true);
                newLabel->setStyleSheet("border: 1px solid; border-color: rgb(175, 193, 220); padding: 5px;");
                scrollAreaLayout->addWidget(newLabel);


                // Start the timer to scroll down after a short delay
                scrollTimer->start(10);
                dbManager.closeDatabase();
                //stepCounter = 2;
            }

        }
        newLabel->setText("ADVISOR\n\nYou have selected the degree path Computer Science\n"
                          "\nFor your first semester at BMCC you should plan to take:\n"
                          "\nMAT 206.5  Precalculus"
                          "\nENG 101      English Composition"
                          "\nCSC 101      Principles in Information Technology and Computation"
                          "\nXXX xxx      Individual and Society"
                          "\nXXX xxx      U.S. Experience in Its Diversity"
                          "\n\n**During your program you MUST take at least ONE Writing Intensive (WI) course"
                          "\n CSC 101 and MAT 206.5 are prerequisite courses to CSC 111. Students are strongly encouraged to take both courses in their first semester."
                          );
    }
    */



    newLabel->setWordWrap(true);
    newLabel->setStyleSheet("border: 1px solid; border-color: rgb(175, 193, 220); padding: 5px;");
    scrollAreaLayout->addWidget(newLabel);

    // Start the timer to scroll down after a short delay
    scrollTimer->start(10);

    // Increment the label counter if necessary
    labelCounter++;

    int id = translate.translateStringToInt(message);
    qDebug() << id;


    stepCounter = 3;
}

void Advisor::stepThree(){
    QLabel *newLabel = new QLabel;


    if(academicStatus == 2){
        QStringList classList = message.split(',');
        takenClasses.clear(); // Clear the QVector before adding new classes

        for (const QString& className : classList) {
            takenClasses.append(className.trimmed());  // Trim to remove leading/trailing whitespaces
        }

        qDebug() << "Classes taken:";
        for (const QString& className : takenClasses) {
            qDebug() << className;
        }

        newLabel->setText("ADVISOR\n\nClasses taken:\n\t"
                          + takenClasses.join("\n\t"));
    }

    newLabel->setWordWrap(true);
    newLabel->setStyleSheet("border: 1px solid; border-color: rgb(175, 193, 220); padding: 5px;");
    scrollAreaLayout->addWidget(newLabel);

    // Start the timer to scroll down after a short delay
    scrollTimer->start(10);

    stepCounter = 4;

}

/*
void Advisor::stepFour() {
    QVector<QString> remainingClasses = dbManager->determineRemainingClasses(takenClasses);

    QLabel* newLabel = new QLabel;

    if (!remainingClasses.isEmpty()) {
        newLabel->setText("ADVISOR\n\nRemaining classes to take:\n\t" + remainingClasses.join("\n\t"));
    } else {
        newLabel->setText("ADVISOR\n\nYou have completed all required classes for the selected degree path.");
    }

}
*/

void Advisor::stepFour() {
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

        // Start the timer to scroll down after a short delay
        scrollTimer->start(10);
    }
}





void Advisor::backToStart(){
    stepCounter = 0;
    on_btn_start_clicked();
}
