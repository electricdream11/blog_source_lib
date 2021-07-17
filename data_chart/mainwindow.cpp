#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include "math.h"
#include <QFile>
#include <QDir>

QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
       ui->setupUi(this);

       m_series=new QLineSeries;
       m_chart=new QChart;

       m_series=new QLineSeries;
       m_series->setName("ss");
       m_chart->addSeries(m_series);
       m_chart->createDefaultAxes();


       m_axisX=new QValueAxis;
       m_axisX->setRange(0,60);
       m_axisX->setGridLineVisible(true);
       m_axisX->setTickCount(11);     //标记的个数
       m_axisX->setMinorTickCount(5); //次标记的个数

       m_axisY=new QValueAxis;
       m_axisY->setRange(-5,10);
       m_axisY->setGridLineVisible(true);
       m_axisY->setTickCount(6);
       m_axisY->setMinorTickCount(2);



       m_chart->setAxisX(m_axisX,m_series);
       m_chart->setAxisY(m_axisY,m_series);
       m_chart->legend()->hide();

       ui->graphicsView->setChart(m_chart);
       ui->graphicsView->setRenderHint(QPainter::Antialiasing);

       m_timer.setInterval(1000);
       m_timer.start();
       connect(&m_timer,SIGNAL(timeout()),this,SLOT(handleTimeout()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_refreshData_clicked()
{
    QFile fil(QDir::currentPath()+".txt");
    fil.open(QIODevice::ReadOnly);
    char buf[1];
    qint64  addr;
    qint64  length;
    QString buf_exp(buf);
    QRegExp exp("[0-9a-fA-F]");
    addr=0;
    int i;
    bool toStop;
    toStop = false;
    i=0;
        while(!toStop)
        {
            fil.seek(addr);
            length = fil.read(buf,sizeof (buf));
            buf_exp = buf;
            if(!exp.indexIn(buf_exp))
            {
                qDebug()<<buf_exp<<":"<<sizeof(buf_exp);
                int x= atoi(buf);
                m_series->append(i,x);
                i++;
                addr=addr+length;
            }
            else
            {
                qDebug()<<"error";
                addr=addr+1;
            }
            if(addr>=fil.size())
            {
                fil.close();
                toStop = true;
            }
        }

}
