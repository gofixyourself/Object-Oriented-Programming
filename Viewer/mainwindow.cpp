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
        error_messenger(error);
}

// Closing the program:
MainWindow::~MainWindow()
{
    action closing;

    closing.toDo = QUIT;

    checkProcess(com);

    delete ui;
}

// Function for scaling a model:
void MainWindow::scaling(int coefficient)
{
    action scale;

    drawingAModel draw;

    draw = drawing(ui->view, coefficient, ui->view->height(), ui->view->width());

    scale.draw = draw;
    scale.toDO = DRAWING;

    errors error = (errors)checkingProcess(scale);

    if (error)
        error_messenger(error);
}

// Function for turn left
void MainWindow::turnLeft()
{
    turningAModel forTurn;

    action toTheLeft;

    drawingAModel draw;

    forTurn.coefficient = 3;

    toTheLeft.turn = forTurn;
    toTheLeft.toDO = TURN_LEFT;

    errors error = (errors)checkProcess(toTheLeft);

    if (error)
        errorMessenger(error);

    draw = drawing(ui->view, ui->scale->value(), ui->view->height(), ui->view->width());

    toTheLeft.toDO = DRAWING;
    toTheLeft.draw = draw;

    error = (errors)checkProcess(toTheLeft);

    if(error)
        errorMessenger(error);
}