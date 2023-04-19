//
// Algorytm budowy drzewa decyzjyjnego MSI
// Created by Wiktor Bystrek on 16.04.2023.
//
#include "header.h"

int main()
{

    if(checkIfFileExists("output.txt")){
        std::ofstream outfile ("output.txt");
        outfile.clear();
        outfile.close();
    }

    string imageToTest;
    cout << "Podaj sciezke pliku do testowania" << endl;
    do {
        cin >> imageToTest;
        if(!checkIfFileExists(imageToTest)){
            cout << "Brak pliku, sprobuj jeszcze raz" << endl;
        }
    } while (!checkIfFileExists(imageToTest));

    while(!imageToTest.empty()){

        vs imagesToLearn;
        vector<figure> processedImages;

        imagesToLearn = getAllFilesNamesWithinFolder("trainImages");

        for (const auto & i : imagesToLearn)
        {
            processedImages.push_back(processImage(i));
        }

        vvs dataTable;
        dataTable.push_back(getHeaders());

        for (const auto & processedImage : processedImages)
        {
            dataTable.push_back(figureToVS(processedImage));
        }

        printAttributeTable(dataTable);

        vvs tableInfo = generateTableInfo(dataTable);

        node* root = new node;
        root->isLeaf = false;
        root = buildDecisionTree(dataTable, root, tableInfo);

        printDecisionTree(root);
        string defaultClass = returnMostFrequentClass(dataTable);

        vs processedTestImage = figureToVS(processImage(imageToTest));

        string prediction = testDataOnDecisionTree(processedTestImage, root, tableInfo, defaultClass);

        cout << endl << "Przewidziana klasa = " << prediction << endl;

        generateOutputFile(prediction, root, dataTable, imageToTest);
        dataTable.clear();

        cout << "Podaj sciezke pliku do testowania" << endl;
        do {
            cin >> imageToTest;
            if(!checkIfFileExists(imageToTest)){
                cout << "Brak pliku, sprobuj jeszcze raz" << endl;
            }
        } while (!checkIfFileExists(imageToTest));

    }

    return 0;
}