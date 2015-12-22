#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void addData(double v);
    void showGraph();
private:
    Ui::MainWindow *ui;
    QVector<double> value;
};

#endif // MAINWINDOW_H
