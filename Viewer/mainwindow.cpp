#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "strcutures of types.h"
#include "errors.h"

// Opening the program window:
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    struct action openWindow;
    openWindow.toDo = OPEN;

    checkProcess(openWindow);
}

// To draw a model:
struct drawingAModel MainWindow::drawing(QGraphicsView *pen, int height, int width, int scale)
{
    struct drawingAModel draw;

    draw.pen = pen;
    draw.height = height;
    draw.width = width;
    draw.scale = scale;

    return draw;
}

// Opening a file:
void MainWindow::openingAFile()
{
    struct action opening;

    // Indicate current state of the event:
    opening.toDo = LOAD;

    struct loadingAFile inputFile;

    // Read the name of file:
    inputFile.name = ui->name->text().toStdString().c_str();

    // Loafing a file with the specified name:
    opening.load = inputFile;

    // Checking action for possible errors:
    enum errors error = (enum errors)checkProcess(opening);

    if (error)
        error_messenger(error);

    on_scale_sliderMoved(50);
}

// Closing the program:
MainWindow::~MainWindow()
{
    struct action closing;

    closing.toDo = QUIT;

    checkProcess(com);

    delete ui;
}

