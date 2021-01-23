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

//#include <vector>
#include <iostream>

HuffmanAlgorithm::HuffmanAlgorithm(int (&counts)[NUM_LETTERS])
{
    

    for (int i = 0; i < NUM_LETTERS; i++)
    {
        HuffmanTree *newTree = new HuffmanTree(char('a' + i), counts[i]);
        mHeap.insert(newTree);
        //cout << 'a' + i << "=" << newTree->getChar() << "|" << counts[i] << "=" << newTree->getFreq() << endl;
    }

    //HuffmanTree *leftTreeDelete;
   // HuffmanTree *rightTreeDelete;
    while (mHeap.size() > 1)
    {
        // grabs 2 mins from heap
        //const HuffmanTree *leftTree = mHeap.findMin();
        HuffmanTree *leftTree = mHeap.deleteMin();
        //const HuffmanTree *rightTree = mHeap.findMin();
        HuffmanTree *rightTree = mHeap.deleteMin();

        // cout << leftTree->getChar() << " " << leftTree->getFreq() << endl;
        // cout << rightTree->getChar() << " " << rightTree->getFreq() << endl;

        // get Frequency and char
        int pFreq = leftTree->getFreq() + rightTree->getFreq();
        char pC = leftTree->getChar();

        // create parent tree with left and right children 
        HuffmanTree *pTree = new HuffmanTree(pC, pFreq, leftTree, rightTree);

        // inserts parent back into the heap 
        mHeap.insert(pTree);
       
    }

    // pulls the main tree out of heps
    HuffmanTree *pTree = mHeap.deleteMin();
    //cout << pTree->getChar() << " " << pTree->getFreq() << endl;
    cout << "Check pTree " << endl;

    pTree->clear();
    pTree = nullptr;

   
}
