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

//HuffmanTree::HuffmanTree() : root(nullptr) {}

HuffmanTree::HuffmanTree(char ch, int f)
{
    // create new dynamically allocated node
    Node *tempNode = new Node(ch, f);
    
    root = tempNode;    // set temp node = to root 

    // delete tempNode
    tempNode = nullptr;
    delete tempNode;
 
}

// HuffmanTree::HuffmanTree(const HuffmanTree &org)
// {
//     this = *copyPrivate(org);
// }

HuffmanTree::~HuffmanTree()
{
}

bool HuffmanTree::operator<(const HuffmanTree &rhs) const
{

    if (root->freq < rhs.root->freq)
    {
        return true;
    }
    else if (root->freq == rhs.root->freq)
    {
        if (root->c < rhs.root->c)
        {
            return true;
        }
    }

    return false;
}

char HuffmanTree::getChar() const
{
    return root->c;
}
int HuffmanTree::getFreq() const
{
    return root->freq;
}

void HuffmanTree::setChar(char ch)
{
    root->c = ch;
}
void HuffmanTree::setFreq(int f)
{
    root->freq = f;
}

// HuffmanTree &HuffmanTree::operator=(const HuffmanTree &rhs)
// {
// }

//----------------------------------------------------------------------------//
// ---------------------- PRIVATE HELPER FUNCTIONS ---------------------------//
//----------------------------------------------------------------------------//

// HuffmanTree *HuffmanTree::copyPrivate(const HuffmanTree copyNode)
// {
//     // node is empty return
//     if (copyNode == nullptr)
//     {
//         return nullptr;
//     }

//     if (copyNode.left == nullptr && copyNode.right == nullptr)
//     {
//     }

//     // Comparable *newItem = new Comparable(*copyNode->item);
//     // Node *newNode = new Node(newItem);

//     // newNode->count = copyNode->count; // copy primative data types

//     // newNode->left = copyPrivate(copyNode->left);
//     // newNode->right = copyPrivate(copyNode->right);

//     return newNode;
// }