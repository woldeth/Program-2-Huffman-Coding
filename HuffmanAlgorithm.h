// ------------------------------------------------------------------------//
// Name: Tomas H Woldemichael
// Date: January 20, 2021
// File Name: HuffmanAlgorithm.h
// Title: PROGRAM 2
// Description:
//
//
// ------------------------------------------------------------------------//
#pragma once

#include <iostream>
#include "HuffmanTree.h"
#include "Heap.h"

using namespace std;

class HuffmanAlgorithm
{

private:
    Heap<HuffmanTree> mHeap;
    HuffmanTree *mainTree;

public:
    HuffmanAlgorithm(int (&counts)[NUM_LETTERS]);
    ~HuffmanAlgorithm();
    string getWord(string in);                                        //takes in a word to encode assume all lower case ignore non letter
    friend ostream &operator<<(ostream &output, HuffmanAlgorithm &I); // Output the letter-to-code translation table
};