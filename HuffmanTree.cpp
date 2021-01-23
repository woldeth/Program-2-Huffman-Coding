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

// used for leaf Trees
HuffmanTree::HuffmanTree(char ch, int f)
{
    // create new dynamically allocated node
    Node *tempNode = new Node(ch, f);
    root = tempNode; // set temp node = to root
}

// used for parent Trees
HuffmanTree::HuffmanTree(char ch, int f, HuffmanTree *leftTree, HuffmanTree *rightTree)
{
    Node *tempNode = new Node(ch, f);
    tempNode->left = leftTree->root;
    tempNode->right = rightTree->root;

    root = tempNode; // set temp node = to root
}

HuffmanTree::~HuffmanTree()
{
    makeEmptyPrivate(root);
}

void HuffmanTree::makeEmptyPrivate(Node *&node)
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
