//------------------------------------------------------------------------
// HW2.CPP
// Driver code for testing Huffman class for creating Huffman codes
// Author:  Clark Olson
//------------------------------------------------------------------------
// This code tests all of the basic functionality of the Huffman class
// for CSS 502 HW 2.  It is not meant to exhaustively test the class.
//
// Assumptions:
//  - none
//------------------------------------------------------------------------

#include <iostream>
#include "HuffmanAlgorithm.cpp" // Must have "const int NUM_LETTERS = 26;"
using namespace std;

//------------------------------------------------------------------------
// main
// Preconditions: none
// Postconditions: tests methods of the Huffman class using randomly
//					generated character counts
int main()
{
	// Create random counts
	int counts[NUM_LETTERS];
	for (int i = 0; i < NUM_LETTERS; i++)
	{
		counts[i] = rand() % 1000;
	}

	// Construct Huffman codes and display table
	HuffmanAlgorithm code(counts); //passed in array to huffman alogorithm
	cout << code << endl;
	cout << endl;

	// // // Simple test of encoding words
	cout << "test:  " << code.getWord("test") << endl; // get a word
	cout << "least: " << code.getWord("tomas") << endl;
	cout << endl;

	return 0;
}


// 01 on or off 
// a 00
// b 01
// c 10

// 0000000