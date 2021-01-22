// ------------------------------------------------------------------------//
// Name: Tomas H Woldemichael
// Date: Jan 21, 2021
// File Name: HuffmanTree.cpp
// Title: PROGRAM 2
// Description:
//
//
// ------------------------------------------------------------------------//

#include "HuffmanTree.h"
#include <iostream>

HuffmanTree::HuffmanTree()
{
}

HuffmanTree::HuffmanTree(char ch, int f)
{
    c = ch;
    freq = f;
    left = nullptr;
    right = nullptr;
}

HuffmanTree::~HuffmanTree()
{
}

bool HuffmanTree::operator<(const HuffmanTree &rhs) const
{
    if (this->freq < rhs.freq)
    {
        return true;
    }
    else if (this->freq == rhs.freq)
    {
        if(this->c < rhs.c){
            return true;
        }
    }

    return false;
}

const char HuffmanTree::getChar() const{
    return c;
}
const int HuffmanTree::getFreq()const{
    return freq;
}

// HuffmanTree &HuffmanTree::operator=(const HuffmanTree &rhs)
// {
// }

//----------------------------------------------------------------------------//
// ---------------------- PRIVATE HELPER FUNCTIONS ---------------------------//
//----------------------------------------------------------------------------//
