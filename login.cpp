#include <iostream>
#include "login.h"
#include "ui_login.h"

using namespace std;

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);  // disable exit button
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);  // disable window frame
    dbManager = new DatabaseManager;
}

Login::~Login()
{
    delete dbManager;
    delete ui;
}


void Login::on_btn_login_clicked()
{
    //QString username = "admin";
    //QString password = "password";
    QString input_uname = ui->txt_username->text();
    QString input_password = ui->txt_password->text();


    if(authenticate(input_uname, input_password)){
        newadmin.show();
        Login::close();
    }
    else{
        ui->lbl_status->setText("Incorrect Username or Password");
    }
}


void Login::on_btn_cancel_clicked()
{
    ui->txt_username->setText("");
    ui->txt_password->setText("");
    ui->lbl_status->setText("");
    Login::close();
}



bool Login::authenticate(const QString &username, const QString &password)
{
    //QString uname = username;
    //QString pw = password;
    qDebug() << "Attempting login with username:" << username << "and password:" << password;

    if(!dbManager->openDatabase()){
        qDebug() << "Database connection failed [1/1]";
        return false;
    }

    else{
        bool authResult = dbManager->authenticateUser(username, password);
        return authResult;
    }

}


