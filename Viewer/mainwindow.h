#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "QGraphicsScene"

#include "service structures.h"
#include "errors.h"

namespace Ui {
    class MainWindow;
}

class MainWindow :
        public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    drawingAModel drawing ( QGraphicsView *pen, int height, int width, int scale);

private slots:
    void on_open_clicked();
    void errorMessenger(enum errors ourError);
    void on_scale_sliderMoved(int position);
    void on_turn_left_clicked();
    void on_turn_right_clicked();
    void on_turn_up_clicked();
    void on_turn_down_clicked();
};

#endif // MAINWINDOW_H
