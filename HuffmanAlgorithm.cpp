// ------------------------------------------------------------------------//
// Name: Tomas H Woldemichael
// Date: Jan 21, 2021
// File Name: HuffmanAlgorithm.cpp
// Title: PROGRAM 2
// Description:
//
//
// ------------------------------------------------------------------------//

#include "HuffmanAlgorithm.h"
#include "HuffmanTree.cpp"

#include <iostream>

HuffmanAlgorithm::HuffmanAlgorithm(int (&counts)[NUM_LETTERS])
{

    for (int i = 0; i < NUM_LETTERS; i++)
    {
        HuffmanTree *newTree = new HuffmanTree(char('a' + i), counts[i]);
        mHeap.insert(newTree);
    }

    while (mHeap.size() > 1)
    {
        // grabs 2 mins from heap
        HuffmanTree *leftTree = mHeap.deleteMin();
        HuffmanTree *rightTree = mHeap.deleteMin();

        // get Frequency and char
        int pFreq = leftTree->getFreq() + rightTree->getFreq();
        char pC = leftTree->getChar();

        // create parent tree with left and right children      MEMORY LEAK HERE!!!!
        HuffmanTree *pTree = new HuffmanTree(pC, pFreq, leftTree, rightTree);

        // inserts parent back into the heap
        mHeap.insert(pTree);
    }

    HuffmanTree *pTree = mHeap.deleteMin();
    cout << "DEBUG: Check pTree " << endl;

    // delete pTree;
    // pTree = nullptr;
    pTree->traverseHuffmanTree();

    cout << endl;
}
