#include "dialoguart.h"
#include "ui_dialoguart.h"
#include <QString>
#include <QDebug>

#include <QSerialPort>
#include <QSerialPortInfo>

#include <QFile>
#include <QDir>

DialogUart::DialogUart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogUart)
{
    ui->setupUi(this);
}

DialogUart::~DialogUart()
{
    delete ui;
}

void DialogUart::on_btnUartOpen_clicked()
{
    serial = new QSerialPort;
    qDebug()<<"uart is open";
}

void DialogUart::on_btnUartClose_clicked()
{
    delete serial;
    qDebug()<<"uart is close";
}

void DialogUart::on_btnConnect_clicked()
{
    //设置串口名
    serial->setPortName("COM1");
    //设置波特率
    serial->setBaudRate(QSerialPort::Baud9600);
    //设置数据位数
    serial->setDataBits(QSerialPort::Data8);
    //设置奇偶校验
    serial->setParity(QSerialPort::NoParity);
    //设置停止位
    serial->setStopBits(QSerialPort::OneStop);
    //设置流控制
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadWrite);
}


void DialogUart::on_btnDisConnect_clicked()
{
    serial->close();
}


void DialogUart::on_readAll_clicked()
{
    QByteArray buf_read;
    buf_read = serial->readAll();
    //write to file
    QFile fil(QDir::currentPath()+".txt");
    fil.open(QIODevice::WriteOnly | QIODevice::Text);
    fil.seek(fil.size());
    fil.write(buf_read.toStdString().data());
    fil.close();
    //write to display
    QString recv = ui->readText->toPlainText();
    recv += QString(buf_read);
    ui->readText->clear();
    ui->readText->append(recv);
}

void DialogUart::on_writeAll_clicked()
{
    QByteArray buf_write;
    buf_write = ui->writeText->text().toUtf8();
    serial->write(buf_write);
}
