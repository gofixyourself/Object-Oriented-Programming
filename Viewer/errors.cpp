#include <QObject>

#include "errors.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::errorMessage(enum errors ourError)
{
    switch(ourError) {
        case FILE_ERROR:
               QMessageBox::critical(NULL,QObject::tr("Error!"),tr("Error while working with file!"));
               break;
        case MEMORY_ALLOCATION_ERROR:
               QMessageBox::critical(NULL,QObject::tr("Error!"),tr("Memory allocation error!"));
               break;
        case FILE_NOT_FOUND:
               QMessageBox::critical(NULL,QObject::tr("Error!"),tr("Memory allocation error!"));
               break;
        case INCORRECT_COMMAND:
              QMessageBox::critical(NULL,QObject::tr("Error!"),tr("Invalid command!"));
              break;
        default:
               QMessageBox::critical(NULL,QObject::tr("Error!"),tr("Unknown error!"));
    }
}
