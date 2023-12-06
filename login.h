#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "admin.h"

#include "databasemanager.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_btn_login_clicked();

    void on_btn_cancel_clicked();

private:
    Ui::Login *ui;
    Admin newadmin;
    DatabaseManager *dbManager;
    bool authenticate(const QString &username, const QString &password);
};

#endif // LOGIN_H
