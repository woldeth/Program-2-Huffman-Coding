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

HuffmanTree::HuffmanTree() : root(nullptr)
{
}

HuffmanTree::~HuffmanTree()
{
    makeEmpty();
}

void HuffmanTree::makeEmpty()
{
    makeEmptyPrivate(root);
}

HuffmanTree &HuffmanTree::operator=(const HuffmanTree &rhs)
{
    // checks to see if lhs and rhs is the same
    if (this != &rhs)
    {
        this->makeEmpty();                  // clear lhs
        this->root = copyPrivate(rhs.root); // make a deep copy of the search tree
    }

    return *this;
}

//----------------------------------------------------------------------------//
// ---------------------- PRIVATE HELPER FUNCTIONS ---------------------------//
//----------------------------------------------------------------------------//

void HuffmanTree::makeEmptyPrivate(HuffmanTree::Node *&node)
{
    if (node == nullptr)
    {
        return;
    }

    makeEmptyPrivate(node->left);
    makeEmptyPrivate(node->right);

    delete node;
    node = nullptr;
}

HuffmanTree::Node *HuffmanTree::copyPrivate(const HuffmanTree::Node *copyNode)
{
    // node is empty return
    if (copyNode == nullptr)
    {
        return nullptr;
    }

    Node *newNode = new Node(copyNode->c, copyNode->freq);
    //  MAY NEED TO DO ADDITON WORK HERE TO MAKE A DEEP COPY COME BACK! 
     
    newNode->left = copyPrivate(copyNode->left);
    newNode->right = copyPrivate(copyNode->right);

    return newNode;
}