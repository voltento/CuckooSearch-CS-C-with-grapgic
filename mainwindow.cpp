#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget->addGraph();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addData(double v)
{
    value.push_back(v);
}

void MainWindow::showGraph()
{
    ui->widget->xAxis->setRange(0,value.length());
    ui->widget->yAxis->setRange(-1000,1000);

    QVector<double> x;
    for(int i = 0; i < value.size(); i++)
    {
        x.push_back(i);
    }

    ui->widget->graph(0)->setData(x,value);
    ui->widget->replot();
    ui->widget->update();

}
