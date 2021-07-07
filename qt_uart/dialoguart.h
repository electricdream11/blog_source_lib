#ifndef DIALOGUART_H
#define DIALOGUART_H

#include <QDialog>
#include <QSerialPort>
#include <QSerialPortInfo>
namespace Ui {
class DialogUart;
}

class DialogUart : public QDialog
{
    Q_OBJECT

public:
    explicit DialogUart(QWidget *parent = nullptr);
    ~DialogUart();

private slots:


    void on_btnUartOpen_clicked();


    void on_btnUartClose_clicked();

    void on_btnConnect_clicked();

    void on_btnDisConnect_clicked();

    void on_readAll_clicked();

    void on_writeAll_clicked();

private:
    Ui::DialogUart *ui;
    QSerialPort * serial;
};

#endif // DIALOGUART_H
