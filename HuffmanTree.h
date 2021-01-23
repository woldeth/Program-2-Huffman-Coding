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

// struct Node
// {
//     char c;
//     int freq;
//     Node *left;  // Pointer to left child
//     Node *right; // Pointer to right child
//     Node() : left(nullptr), right(nullptr) {}
//     Node(char ch, int f) : c(ch), freq(f), left(nullptr), right(nullptr) {}       // Constructor to initialize node
//     Node(char ch, int f, Node *l, Node *r) : c(ch), freq(f), left(l), right(r) {} // Constructor to initialize node
// };

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

    Node *root;

public:
    HuffmanTree(); // constructor
    HuffmanTree(char ch, int f);
    HuffmanTree(char ch, int f, HuffmanTree *leftTree, HuffmanTree *rightTree);
    HuffmanTree(const HuffmanTree &org); // copy constructor
    ~HuffmanTree();                      // destructor

    //HuffmanTree &operator=(const HuffmanTree &rhs); // assignment operator

    bool operator<(const HuffmanTree &rhs) const; //less than operator to store huffmantree in heap
    char getChar() const;
    int getFreq() const;
    void setChar(char ch);
    void setFreq(int f);
    //void TraverseHuffmanTree();
};