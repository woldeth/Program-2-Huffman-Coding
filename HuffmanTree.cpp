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

    tempNode = nullptr;
    delete tempNode;
}

// used for parent Trees
HuffmanTree::HuffmanTree(char ch, int f, const HuffmanTree *leftTree, const HuffmanTree *rightTree)
{
    Node *tempNode = new Node(ch, f);
    tempNode->left = leftTree->root;
    tempNode->right = rightTree->root;

    root = tempNode; // set temp node = to root

    tempNode = nullptr;
    delete tempNode;
}

HuffmanTree::HuffmanTree(const HuffmanTree &org)
{
    root = copyPrivate(org.root);
}


HuffmanTree::Node *HuffmanTree::copyPrivate(const Node *copyNode)
{
    // node is empty return
    if (copyNode == nullptr)
    {
        return nullptr;
    }

    HuffmanTree *newTree = new HuffmanTree(copyNode->c, copyNode->freq);

    newTree->root->left = copyPrivate(copyNode->left);
    newTree->root->right = copyPrivate(copyNode->right);

    return newTree->root;
}

HuffmanTree::~HuffmanTree()
{
    clearTreePrivate(root);
}

// void HuffmanTree::makeEmptyPrivate(Node *&node)
// {
//     if (node == nullptr)
//     {
//         return;
//     }

//     makeEmptyPrivate(node->left);
//     makeEmptyPrivate(node->right);

//     delete node;
//     node = nullptr;

// }

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

void HuffmanTree::clear()
{
    clearTreePrivate(root);
}

void HuffmanTree::clearTreePrivate(Node *&node)
{
    if (node == nullptr)
    {
        return;
    }

    clearTreePrivate(node->left);
    clearTreePrivate(node->right);

    delete node;
    node = nullptr;
}