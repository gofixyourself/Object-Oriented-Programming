#include "for loading.h"

int loading(model &ourModel, loadingAFile &inputFile)
{
    model newModel = initialiazationModel();
    int checkError = loadFromFile(newModel, inputFile);

    if (!checkError)
    {
      deleteModel(ourModel);
      ourModel = newModel; 
    }
    else
        deleteModel(newModel);

    return checkError;
}

int loadFromFile(model &ourModel, loadingAFile inputFile)
{
    FILE *forInputFile = fopen(inputFile.name, "r");

    if (!forInputFile)
        return FILE_NOT_FOUND;

    int checkError = forLoadingAModel(ourModel, forInputFile);

    if (checkError)
        deleteModel(ourModel);

    fclose(forInputFile);

    return checkError;
}

