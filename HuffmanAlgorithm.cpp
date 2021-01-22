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
    cout << "C" << "-" << "F" << endl;
    for (int i = 0; i < NUM_LETTERS; i++)
    {
        HuffmanTree *newTree = new HuffmanTree(char('a' + i), counts[i]);
        mHeap.insert(newTree);
        cout << 'a' + i << "=" <<newTree->getChar() << "|" << counts[i] << "=" << newTree->getFreq() << endl;

        // newTree = nullptr;
        // delete newTree;
    }

    cout << endl;
    cout << "MIN IN ORDER " << endl;


    while (!mHeap.isEmpty())
    {
        const HuffmanTree *min1 = mHeap.findMin();
        HuffmanTree copyMin1(*min1);

        HuffmanTree *delMin1 = mHeap.deleteMin();
        delete delMin1;
        delMin1 = nullptr;
    
        const HuffmanTree *min2 = mHeap.findMin();
        HuffmanTree copyMin2(*min2);

        HuffmanTree *delMin2 = mHeap.deleteMin();
        delete delMin2;
        delMin2 = nullptr;

        cout << copyMin1.getChar() << " " << copyMin1.getFreq() << endl;
        cout << copyMin2.getChar() << " " << copyMin2.getFreq()<< endl;

    }
}

