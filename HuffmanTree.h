// ------------------------------------------------------------------------//
// Name: Tomas H Woldemichael
// Date: January 20, 2021
// File Name: HuffmanTree.h
// Title: PROGRAM 2
// Description:
//
//
// ------------------------------------------------------------------------//
#pragma once

#include <iostream>

using namespace std;

const int NUM_LETTERS = 26; // Amount of charatcters starting for 'a' in ASCII

class HuffmanTree
{

private:
    struct Node
    {
        char c;
        int freq;
        Node *left;  // Pointer to left child
        Node *right; // Pointer to right child
        Node(char ch, int f) : c(ch), freq(f), left(nullptr), right(nullptr) {}
    };

    Node *root; // root node

    //------------------------------------------------------------------------
    // clearTreePrivate - Private helper method to clear the tree
    // Preconditions: Passed in root node for traversal of tree
    // Postconditions: Clears all dynamically allocated nodes
    void clearTreePrivate(Node *node);

    //------------------------------------------------------------------------
    // copyPrivate() - Private helper method for traversal to deep copy
    // Preconditions: Passed in root node of HuffmanTree obj to be copied
    // Postconditions: Deep copy of passed in huffmanTree obj is created
    Node *copyPrivate(const Node *copyNode);

    //---------------------------------------------------------------------------------
    // traverseCodePrivate - Private helper method to traverse the tree
    // Preconditions: None
    // Postconditions: Stores char code within array based off frequency
    void traverseCodePrivate(Node *node, string &c, int &index, string cBook[NUM_LETTERS]);

public:
    //------------------------------------------------------------------------
    // HuffmanTree(char ch, int f) - Constructor 
    // Preconditions: Passed in a character and interger value
    // Postconditions: Huffman tree object created with a Node within obj
    //				   that holds character and frequency
    HuffmanTree(char ch, int f);

    //------------------------------------------------------------------------
    // HuffmanTree - Constructor
    // Preconditions: Passed in a character,integer value, L and R child trees
    // Postconditions: Huffman tree object created with a Node within obj
    //		           that holds character, frequency, and pointers to children
    HuffmanTree(char ch, int f, HuffmanTree *leftTree, HuffmanTree *rightTree);

    //------------------------------------------------------------------------
    // HuffmanTree - Copy constructor
    // Preconditions: Input is a huffmanTree obj
    // Postconditions: Deep copy of passed in huffmanTree obj is created
    HuffmanTree(const HuffmanTree &org);

    //------------------------------------------------------------------------
    // ~HuffmanTree() - Destructor
    // Preconditions: None
    // Postconditions: Clears dynamically allocated memory
    ~HuffmanTree();

    //------------------------------------------------------------------------
    // operator=
    // Preconditions: Rhs object must be HuffmanTree obj
    // Postconditions: Assigns rhs obj to lhs HuffmanTree
    HuffmanTree &operator=(const HuffmanTree &rhs);

    //------------------------------------------------------------------------
    // operator<
    // Preconditions: Rhs object must be HuffmanTree obj
    // Postconditions: returns true if lhs object is smaller than rhs
    bool operator<(const HuffmanTree &rhs) const;

    //------------------------------------------------------------------------
    // getChar() - Gets the character
    // Preconditions: None
    // Postconditions: returns char from huffmanTree
    char getChar() const;

    //------------------------------------------------------------------------
    // getFreq() - Gets the frequency 
    // Preconditions: None
    // Postconditions: returns int frequency from huffmanTree
    int getFreq() const;

    //------------------------------------------------------------------------
    // setChar(char ch) - Sets the character
    // Preconditions: Passed in value must be a single char
    // Postconditions: Sets value of char within huffmantree
    void setChar(char ch);

    //------------------------------------------------------------------------
    // setFreq(char ch) - Sets the frequency 
    // Preconditions: Passed in value must be a int value
    // Postconditions: Sets value of int frequency within huffmantree
    void setFreq(int f);

    //------------------------------------------------------------------------
    // traverseCode - Traverses the HuffmanTree and stroes value in array
    // Preconditions: Pass in an array to store char code
    // Postconditions: Stores char code within array based off frequency
    void traverseCode(string cBook[NUM_LETTERS]);

    //------------------------------------------------------------------------
    // isLeaf - Determines if a node is a leaf node or not 
    // Preconditions: Pass in node
    // Postconditions: return true if node is a leaf node within tree
    bool isLeaf(Node *node);
};