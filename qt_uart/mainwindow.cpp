#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "threadtextsolve.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui2 = new DialogUart;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnOpenUart_clicked()
{
    ui2->show();
}

void MainWindow::on_textSolve_clicked()
{
    t1 = new threadTextSolve;
    t1->start();
}
