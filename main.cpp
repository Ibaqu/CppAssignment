#include "BST.h"
#include "RBTree.h"
#include "SplayTree.h"
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

using namespace std::chrono;
using namespace std;

void insertIntoBST(BST &binarySearchTree, string filePath)
{
    string textLine;
    ifstream fileStream(filePath);

    auto start = high_resolution_clock::now();
    while (getline(fileStream, textLine))
    {
        binarySearchTree.put(stoi(textLine), stoi(textLine));
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\n File : " << filePath;
    cout << "\n[BST INSERT TIME   ] :" << duration.count() << " microseconds";
    cout << "\n[BST HEIGHT ] : " << binarySearchTree.height();

    fileStream.close();
}

void searchBST(BST &binarySearchTree)
{
    string textLine;
    ifstream fileStream("./data/search_data.txt");

    auto start = high_resolution_clock::now();
    while (getline(fileStream, textLine))
    {
        binarySearchTree.contains(stoi(textLine));
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\n[BST SEARCH TIME] :" << duration.count() << " microseconds";

    fileStream.close();
}

void insertIntoSplay(SplayTree &splayTree, string filePath)
{
    string textLine;
    ifstream fileStream(filePath);

    auto start = high_resolution_clock::now();
    while (getline(fileStream, textLine))
    {
        splayTree.put(stoi(textLine), stoi(textLine));
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\n File : " << filePath;
    cout << "\n[Splay INSERT TIME   ] : " << duration.count() << " microseconds";
    cout << "\n[Splay HEIGHT ] : " << splayTree.height();
    fileStream.close();
}

void searchSplay(SplayTree &splayTree)
{
    string textLine;
    ifstream fileStream("./data/search_data.txt");

    auto start = high_resolution_clock::now();
    while (getline(fileStream, textLine))
    {
        splayTree.contains(stoi(textLine));
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\n[Splay SEARCH TIME] :" << duration.count() << " microseconds";
    fileStream.close();
}

void insertIntoRBT(RBTree &redBlackTree, string filePath)
{
    string textLine;
    ifstream fileStream(filePath);

    auto start = high_resolution_clock::now();
    while (getline(fileStream, textLine))
    {
        redBlackTree.put(stoi(textLine), stoi(textLine));
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\n File : " << filePath;
    cout << "\n[RBT INSERT TIME   ] : " << duration.count() << " microseconds";
    cout << "\n[RBT HEIGHT ] : " << redBlackTree.height();
    fileStream.close();
}

void searchRBT(RBTree &redBlackTree)
{
    string textLine;
    ifstream fileStream("./data/search_data.txt");

    auto start = high_resolution_clock::now();
    while (getline(fileStream, textLine))
    {
        redBlackTree.contains(stoi(textLine));
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\n[RBT SEARCH TIME] :" << duration.count() << " microseconds";
    fileStream.close();
}

int main()
{
    BST bstData1;
    BST bstData2;
    insertIntoBST(bstData1, "./data/data_1.txt");
    searchBST(bstData1);
    insertIntoBST(bstData2, "./data/data_2.txt");
    searchBST(bstData2);

    cout << "\n";

    SplayTree stData1;
    SplayTree stData2;
    insertIntoSplay(stData1, "./data/data_1.txt");
    searchSplay(stData1);
    insertIntoSplay(stData2, "./data/data_2.txt");
    searchSplay(stData2);

    cout << "\n";

    RBTree rbtData1;
    RBTree rbtData2;
    insertIntoRBT(rbtData1, "./data/data_1.txt");
    searchRBT(rbtData1);
    insertIntoRBT(rbtData2, "./data/data_2.txt");
    searchRBT(rbtData2);
}
