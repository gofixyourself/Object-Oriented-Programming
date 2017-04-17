#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "entry.h"

// Opening the program window:
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    action openWindow;
    openWindow.toDo = OPENING;

    process(openWindow);
}

// To draw a model:
drawingAModel MainWindow::drawing(QGraphicsView *pen, int height, int width, int scale)
{
    drawingAModel draw;

    draw.pen = pen;
    draw.height = height;
    draw.width = width;
    draw.scale = scale;

    return draw;
}

// Opening a file:
void MainWindow::on_open_clicked()
{
    action opening;

    // Indicate current state of the event:
    opening.toDo = LOADING;

    loadingAFile inputFile;

    // Read the name of file:
    inputFile.name = ui->filename->text().toStdString().c_str();

    // Loafing a file with the specified name:
    opening.load = inputFile;

    // Checking action for possible errors:
    errors error = (errors)process(opening);

    if (error)
        errorMessenger(error);

     on_scale_sliderMoved(35);
}

// Closing the program:
MainWindow::~MainWindow()
{
    action closing;

    closing.toDo = QUIT;

    process(closing);

    delete ui;
}

// Function for scaling a model:
void MainWindow::on_scale_sliderMoved(int position)
{
    action scale;
    drawingAModel draw = drawing(ui->view, position, ui->view->height(), ui->view->width());

    scale.draw = draw;
    scale.toDo = DRAWING;

    errors error = (errors)process(scale);

    if (error)
        errorMessenger(error);
}

// Function for turning left:
void MainWindow::on_turn_left_clicked()
{
    turningAModel forTurn;
    action toTheLeft;
    drawingAModel draw;

    forTurn.coefficient = 3;

    toTheLeft.turn = forTurn;
    toTheLeft.toDo = HORIZONTAL_ROTATION;

    errors error = (errors)process(toTheLeft);

    if (error)
        errorMessenger(error);

    draw = drawing(ui->view, ui->scale->value(), ui->view->height(), ui->view->width());

    toTheLeft.toDo = DRAWING;
    toTheLeft.draw = draw;

    error = (errors)process(toTheLeft);

    if (error)
        errorMessenger(error);
}

// Function for turning right:
void MainWindow::on_turn_right_clicked()
{
    turningAModel forTurn;
    action toTheRight;
    drawingAModel draw;

    forTurn.coefficient = -3;

    toTheRight.turn = forTurn;
    toTheRight.toDo = VERTICAL_ROTATION;

    errors error = (errors)process(toTheRight);

    if (error)
        errorMessenger(error);

    draw = drawing(ui->view, ui->scale->value(), ui->view->height(), ui->view->width());

    toTheRight.toDo = DRAWING;
    toTheRight.draw = draw;

    error = (errors)process(toTheRight);

    if (error)
        errorMessenger(error);
}

// Function for turning up:
void MainWindow::on_turn_up_clicked()
{
    turningAModel forTurn;
    action toTheUp;
    drawingAModel draw;

    forTurn.coefficient = -3;

    toTheUp.toDo = TURN_UP;
    toTheUp.turn= forTurn;

    errors error = (errors)process(toTheUp);

    if (error)
        errorMessenger(error);

    draw = drawing(ui->view, ui->scale->value(), ui->view->height(), ui->view->width());

    toTheUp.toDo = DRAWING;
    toTheUp.draw = draw;

    error = (errors)process(toTheUp);

    if (error)
        errorMessenger(error);
}

// Function for turning down:
void MainWindow::on_turn_down_clicked()
{
    turningAModel forTurn;
    action toTheDown;
    drawingAModel draw;

    forTurn.coefficient = 3;

    toTheDown.toDo = TURN_DOWN;
    toTheDown.turn = forTurn;

    errors error = (errors)process(toTheDown);

    if (error)
           errorMessenger(error);

    draw = drawing(ui->view,ui->scale->value(),ui->view->height(),ui->view->width());
    toTheDown.toDo = DRAWING;
    toTheDown.draw = draw;

    error = (errors)process(toTheDown);

    if (error)
           errorMessenger(error);
}
