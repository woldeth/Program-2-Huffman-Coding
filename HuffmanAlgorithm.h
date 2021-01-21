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

using namespace std;

const int NUM_LETTERS = 26;

class HuffmanAlgorithm
{

private:
    
    
public: 
    
    HuffmanAlgorithm(int (&counts)[NUM_LETTERS]);
    string getWord(string in);   //takes in a word to encode assume all lower case ignore non letter
    friend ostream &operator<<(ostream &output, HuffmanAlgorithm &I);   // Output the letter-to-code translation table
}; 