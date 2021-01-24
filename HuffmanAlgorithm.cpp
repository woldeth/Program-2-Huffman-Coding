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

        // create parent tree with left and right children
        HuffmanTree *pTree = new HuffmanTree(pC, pFreq, leftTree, rightTree);

        // inserts parent back into the heap
        mHeap.insert(pTree);
    }

    mainTree = mHeap.deleteMin();
    mainTree->traverseCode(cBook);
}

HuffmanAlgorithm::~HuffmanAlgorithm()
{
    delete mainTree;
    mainTree = nullptr;
}

string HuffmanAlgorithm::getWord(string in)
{
    string code = "";
    for (int i = 0; i < in.length(); i++)
    {
        code = code + getCode(in[i]);
    }
    return code;
}

string HuffmanAlgorithm::getCode(char c)
{
    for (int i = 0; i < NUM_LETTERS; i++)
    {
        if (c == (cBook[i])[0])
        {
            return cBook[i].substr(1);
        }
    }
    return "";
}

ostream &operator<<(ostream &output, HuffmanAlgorithm &I)
{
    char start = 'a';
    for (int i = 0; i < NUM_LETTERS; i++)
    {
        output << char(start + i) << " " << I.getCode(char('a' + i)) << endl;
    }

    return output;
}