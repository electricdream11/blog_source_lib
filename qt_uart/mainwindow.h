#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialoguart.h"
#include "threadtextsolve.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnOpenUart_clicked();

    void on_textSolve_clicked();

private:
    Ui::MainWindow *ui;
    DialogUart *ui2;
    threadTextSolve *t1;
};

#endif // MAINWINDOW_H
