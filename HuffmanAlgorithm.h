// -------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: Jan 27, 2021
// File Name: HuffmanAlgorithm.h
// Title: PROGRAM 2
// -------------------------------------------------------------------
// HuffmanAlgorithm class:
//	Implements the Huffman algorithm utilizing a minHeap and HuffmanTree
//	with the following methods:
//		getWord, getCode, operator<< (for display)
//  The HuffmanAlogrithmn gets passed in an array of ints and utilizes
//  the huffmanTree and minHeap to encode characters "a-z"
//  Assumptions:
//	 Values are only for ASCII characters a-z and have a frequency
//	 of at least 1
//--------------------------------------------------------------------
#pragma once

#include <iostream>
#include "HuffmanTree.h"
#include "Heap.h"

using namespace std;

class HuffmanAlgorithm
{

private:
    Heap<HuffmanTree> mHeap;   // min heap to hold various trees
    HuffmanTree *mainTree;     // main huffman tree pointer
    string cBook[NUM_LETTERS]; // List to hold codes for chars

public:
    //---------------------------------------------------------------------------------
    // HuffmanAlgorithm - Constructor
    // Preconditions: Passed in an array of frequency's index 0 = a through END
    // Postconditions: Creates huffman tree object based off frequency passed in array
    HuffmanAlgorithm(int (&counts)[NUM_LETTERS]);

    //---------------------------------------------------------------------------------
    // ~HuffmanAlgorithm - Destructor
    // Preconditions: None
    // Postconditions: Clears dynamically allocated memory stored by HuffmanAlgorithm
    ~HuffmanAlgorithm();

    //---------------------------------------------------------------------------------
    // getWord(string in) - returns the code of a string
    // Preconditions: Takes in a string of words to endcode
    // Postconditions: Returns a that encodes the the string that was passed in
    string getWord(string in);

    //---------------------------------------------------------------------------------
    // operator<< - Prints the HuffmanTree to the console
    // Preconditions: Takes in a HuffmanTree
    // Postconditions: Prints the HuffmanTree characters and binary code transformation
    friend ostream &operator<<(ostream &output, HuffmanAlgorithm &I);

    //---------------------------------------------------------------------------------
    // getCode - Gets the code for a single letter
    // Preconditions: Takes in a single character
    // Postconditions: Returns the code for the single character passed in
    string getCode(char c);
};