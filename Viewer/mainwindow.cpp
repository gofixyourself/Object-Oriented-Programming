#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "strcutures of types.h"
#include "errors.h"

void MainWindow::openingAFile()
{
    struct action opening;

    opening.todo = LOAD;

    struct loadingAFile inputFile;

    inputFile.name = ui->name->text().toStdString().c_str();

    opening.load = inputFile;

    enum errors error = (enum errors)checkProcess(opening);

    if (error)
        error_messenger(error);

    on_scale_sliderMoved(50);
}
