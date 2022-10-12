#include "BST.h"
#include "RBTree.h"
#include "SplayTree.h"
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

using namespace std::chrono;
using namespace std;

void insertIntoBST(string filePath)
{
    string textLine;
    ifstream fileStream(filePath);
    BST binarySearchTree;

    auto start = high_resolution_clock::now();
    while (getline(fileStream, textLine))
    {
        binarySearchTree.put(stoi(textLine), stoi(textLine));
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\n File : " << filePath;
    cout << "\n[BST TIME   ] :" << duration.count() << " microseconds";
    cout << "\n[BST HEIGHT ] : " << binarySearchTree.height();
    fileStream.close();
}

void insertIntoRBT(string filePath)
{
    string textLine;
    int index = 0;
    ifstream fileStream(filePath);

    RBTree redblackTree;

    auto start = high_resolution_clock::now();
    while (getline(fileStream, textLine))
    {
        redblackTree.put(stoi(textLine), stoi(textLine));
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\n File : " << filePath;
    cout << "\n[RBT TIME   ] : " << duration.count() << " microseconds";
    cout << "\n[RBT HEIGHT ] : " << redblackTree.height();
    fileStream.close();
}

void insertIntoSplay(string filePath)
{
    string textLine;
    int index = 0;
    ifstream fileStream(filePath);

    SplayTree splayTree;

    auto start = high_resolution_clock::now();
    while (getline(fileStream, textLine))
    {
        splayTree.put(stoi(textLine), stoi(textLine));
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\n File : " << filePath;
    cout << "\n[Splay TIME   ] : " << duration.count() << " microseconds";
    cout << "\n[Splay HEIGHT ] : " << splayTree.height();
    fileStream.close();
}

int main()
{
    insertIntoBST("./data/data_1.txt");
    insertIntoBST("./data/data_2.txt");

    cout << "\n";

    insertIntoRBT("./data/data_1.txt");
    insertIntoRBT("./data/data_2.txt");

    cout << "\n";

    insertIntoSplay("./data/data_1.txt");
    insertIntoSplay("./data/data_2.txt");
}
