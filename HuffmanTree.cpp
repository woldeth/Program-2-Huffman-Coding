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
#include <string>

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
    leftTree->root = nullptr;
    rightTree->root = nullptr;

    delete leftTree;
    delete rightTree;
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

    Node *newNode = new Node(copyNode->c, copyNode->freq);

    newNode->left = copyPrivate(copyNode->left);
    newNode->right = copyPrivate(copyNode->right);

    return newNode;
}

HuffmanTree::~HuffmanTree()
{
    clearTreePrivate(root);
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

HuffmanTree &HuffmanTree::operator=(const HuffmanTree &rhs)
{
    // checks to see if lhs and rhs is the same
    if (this != &rhs)
    {
        clearTreePrivate(root);       // clear lhs
        root = copyPrivate(rhs.root); // make a deep copy of the search tree
    }

    return *this;
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

// void HuffmanTree::clear()
// {
//     clearTreePrivate(root);
// }

void HuffmanTree::clearTreePrivate(Node *node)
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

bool HuffmanTree::isLeaf(Node *node)
{
    if (node->left == nullptr && node->right == nullptr)
    {
        return true;
    }
    return false;
}

void HuffmanTree::traverseCode(string cBook[NUM_LETTERS])
{
    int index = 0;
    string code = "";
    traverseCodePrivate(root, code, index, cBook);
}

void HuffmanTree::traverseCodePrivate(Node *node, string &c, int &index, string cBook[NUM_LETTERS])
{
    if (node->left != nullptr)
    {
        c = c + "0";
        traverseCodePrivate(node->left, c, index, cBook);
        c.pop_back();
    }

    if (node->right != nullptr)
    {
        c = c + "1";
        traverseCodePrivate(node->right, c, index, cBook);
        c.pop_back();
    }

    if (isLeaf(node))
    {
        cBook[index] = node->c + c; // remove letter once complete
        index = index + 1;
    }
}