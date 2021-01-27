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

//---------------------------------------------------------------------------------
// HuffmanAlgorithm - Constructor
// Preconditions: Passed in an array of frequency's index 0 = a through END
// Postconditions: Creates huffman tree object based off frequency passed in array
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

//---------------------------------------------------------------------------------
// ~HuffmanAlgorithm() - Destructor
// Preconditions: None
// Postconditions: Clears dynamically allocated memory stored by HuffmanAlgorithm
HuffmanAlgorithm::~HuffmanAlgorithm()
{
    delete mainTree;
    mainTree = nullptr;
}

//---------------------------------------------------------------------------------
// getWord(string in) - returns the code of a string
// Preconditions: Takes in a string of words to endcode
// Postconditions: Returns a that encodes the the string that was passed in
string HuffmanAlgorithm::getWord(string in)
{
    string code = "";
    for (int i = 0; i < in.length(); i++)
    {
        code = code + getCode(in[i]);
    }
    return code;
}

//---------------------------------------------------------------------------------
// getCode - Gets the code for a single letter
// Preconditions: Takes in a single character
// Postconditions: Returns the code for the single character passed in
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

//---------------------------------------------------------------------------------
// operator<< - Prints the HuffmanTree to the console
// Preconditions: Takes in a HuffmanTree
// Postconditions: Prints the HuffmanTree characters and binary code transformation
ostream &operator<<(ostream &output, HuffmanAlgorithm &I)
{
    char start = 'a';
    for (int i = 0; i < NUM_LETTERS; i++)
    {
        output << char(start + i) << " " << I.getCode(char('a' + i)) << endl;
    }

    return output;
}