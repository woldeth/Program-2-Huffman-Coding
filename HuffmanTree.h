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

const int NUM_LETTERS = 3;

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
    void clearTreePrivate(Node *node);
    Node *copyPrivate(const Node *copyNode);
    void traverseCodePrivate(Node *node, string &c, int &index, string cBook[NUM_LETTERS]);

public:
    //Constructors/ destructor
    HuffmanTree(char ch, int f);
    HuffmanTree(char ch, int f, HuffmanTree *leftTree, HuffmanTree *rightTree);
    HuffmanTree(const HuffmanTree &org);
    ~HuffmanTree();

    //Operators
    //HuffmanTree &operator=(const HuffmanTree &rhs); // assignment operator
    bool operator<(const HuffmanTree &rhs) const; //less than operator to store huffmantree in heap
    friend ostream &operator<<(ostream &output, HuffmanTree &I); 

    //Getters
    char getChar() const;
    int getFreq() const;


    //Setters
    void setChar(char ch);
    void setFreq(int f);

    //Mutators
    void clear();
    void traverseCode(string cBook[NUM_LETTERS]);
    bool isLeaf(Node *node);
};