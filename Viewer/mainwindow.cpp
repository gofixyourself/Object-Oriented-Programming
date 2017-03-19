#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "strcutures of types.h"
#include "errors.h"

// Opening the program window:
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    action openWindow;
    openWindow.toDo = OPENING;

    checkProcess(openWindow);
}

// To draw a model:
struct drawingAModel MainWindow::drawing(QGraphicsView *pen, int height, int width, int scale)
{
    drawingAModel draw;

    draw.pen = pen;
    draw.height = height;
    draw.width = width;
    draw.scale = scale;

    return draw;
}

// Opening a file:
void MainWindow::openingAFile()
{
    action opening;

    // Indicate current state of the event:
    opening.toDo = LOADING;

    loadingAFile inputFile;

    // Read the name of file:
    inputFile.name = ui->name->text().toStdString().c_str();

    // Loafing a file with the specified name:
    opening.load = inputFile;

    // Checking action for possible errors:
    errors error = (errors)checkProcess(opening);

    if (error)
        errorMessenger(error);
}

// Closing the program:
MainWindow::~MainWindow()
{
    action closing;

    closing.toDo = QUIT;

    checkProcess(closing);

    delete ui;
}

// Function for scaling a model:
void MainWindow::scaling(int coefficient)
{
    action scale;
    drawingAModel draw;

    draw = drawing(ui->view, coefficient, ui->view->height(), ui->view->width());

    scale.draw = draw;
    scale.toDo = DRAWING;

    errors error = (errors)checkProcess(scale);

    if (error)
        errorMessenger(error);
}

// Function for turning left:
void MainWindow::turningLeft()
{
    turningAModel forTurn;
    action toTheLeft;
    drawingAModel draw;

    forTurn.coefficient = 3;

    toTheLeft.turn = forTurn;
    toTheLeft.toDo = TURN_LEFT;

    errors error = (errors)checkProcess(toTheLeft);

    if (error)
        errorMessenger(error);

    draw = drawing(ui->view, ui->scale->value(), ui->view->height(), ui->view->width());

    toTheLeft.toDo = DRAWING;
    toTheLeft.draw = draw;

    error = (errors)checkProcess(toTheLeft);

    if (error)
        errorMessenger(error);
}

// Function for turning right:
void MainWindow::turningRight()
{
    turningAModel forTurn;
    action toTheRight;
    drawingAModel draw;

    forTurn.coefficient = -3;

    toTheRight.turn = forTurn;
    toTheRight.toDo = TURN_RIGHT;

    errors error = (errors)checkProcess(toTheRight);

    if (error)
        errorMessenger(error);

    draw = drawing(ui->view, ui->scale->value(), ui->view->height(), ui->view->width());

    toTheRight.toDo = DRAWING;
    toTheRight.draw = draw;

    error = (errors)checkProcess(toTheRight);

    if (error)
        errorMessenger(error);
}

// Function for turning up:
void MainWindow::turningUp()
{
    turningAModel forTurn;
    action toTheUp;
    drawingAModel draw;

    forTurn.coefficient = -3;

    toTheUp.toDo = TURN_UP;
    toTheUp.turn= forTurn;

    errors error = (errors)checkProcess(toTheUp);

    if (error)
        errorMessenger(error);

    draw = drawing(ui->view, ui->scale->value(), ui->view->height(), ui->view->width());

    toTheUp.toDo = DRAWING;
    toTheUp.draw = draw;

    error = (errors)checkProcess(toTheUp);

    if (error)
        errorMessenger(error);
}
