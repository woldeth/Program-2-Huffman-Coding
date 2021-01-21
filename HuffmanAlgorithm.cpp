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
#include <iostream>




HuffmanAlgorithm::HuffmanAlgorithm(int (&counts)[NUM_LETTERS])
{
    for (int i = 0; i < NUM_LETTERS; i++)
    {
        cout << counts[i] << " ";
    }
}
