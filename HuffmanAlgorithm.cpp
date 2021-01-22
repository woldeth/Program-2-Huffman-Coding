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
    cout << "C"
         << "-"
         << "F" << endl;
    for (int i = 0; i < NUM_LETTERS; i++)
    {
        HuffmanTree *newTree = new HuffmanTree('a' + i, counts[i]);
        mHeap.insert(newTree);
        cout << newTree->getChar() << "|" << newTree->getFreq() << endl;
    }

    cout << endl;
    cout << "MIN IN ORDER " << endl;
    const HuffmanTree *min1;
    const HuffmanTree *min2;
    HuffmanTree *del ;
    while (!mHeap.isEmpty())
    {
        min1 = mHeap.findMin();
        cout << min1->getChar() << " " << min1->getFreq() << endl;

        del = mHeap.deleteMin();
        delete del;
        del = nullptr;

        min2 = mHeap.findMin();
        cout << min2->getChar() << " " << min2->getFreq() << endl;
        min1 = mHeap.findMin();

        del = mHeap.deleteMin();
        delete del;
        del = nullptr;


    }
 
}
