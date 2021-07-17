#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>

QT_CHARTS_USE_NAMESPACE
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
    void on_refreshData_clicked();

private:
    Ui::MainWindow *ui;
    QLineSeries* m_series;
    QChart* m_chart;
    QValueAxis* m_axisX;
    QValueAxis* m_axisY;
    QTimer m_timer;
    int m_x;
    int m_max;
};

#endif // MAINWINDOW_H
