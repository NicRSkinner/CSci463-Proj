#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButton_clicked()
{
    if(ui->loginUsername->text() == "Nick" && ui->loginPassword->text() == "Skinner")
    {
        mainWindow.show();
        this->close();
    }

    if(ui->loginUsername->text() == "David" && ui->loginPassword->text() == "Johnson")
    {
        mainWindow.show();
        this->close();
    }

    if(ui->loginUsername->text() == "Seth" && ui->loginPassword->text() == "Stoltenow")
    {
        mainWindow.show();
        this->close();
    }

    if(ui->loginUsername->text() == "Sai" && ui->loginPassword->text() == "Peri")
    {
        mainWindow.show();
        this->close();
    }
}
