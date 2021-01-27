// -------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: Jan 27, 2021
// File Name: HuffmanTree.cpp
// Title: PROGRAM 2
// -------------------------------------------------------------------
// HuffmanTree class:
//	Implements the HuffmanTree class utilizing a struct node to
//	hold the characters, frequency, left and right child. The Huffman
//	Tree uses the following methods
//	     operator</=, getters/setters, clearTree, TraverseCoder, etc
//  The HuffmanTree is used to hold the tree structure for the
//  HuffmanAlgoirthm class
//--------------------------------------------------------------------

#include "HuffmanTree.h"
#include <iostream>
#include <string>

//------------------------------------------------------------------------
// HuffmanTree(char ch, int f) - Constructor
// Preconditions: Passed in a character and interger value
// Postconditions: Huffman tree object created with a Node within obj
//				   that holds character and frequency

HuffmanTree::HuffmanTree(char ch, int f)
{
    // create new dynamically allocated node
    Node *tempNode = new Node(ch, f);
    root = tempNode; // set temp node = to root
}

//------------------------------------------------------------------------
// HuffmanTree - Constructor
// Preconditions: Passed in a character,integer value, L and R child trees
// Postconditions: Huffman tree object created with a Node within obj
//		           that holds character, frequency, and pointers to children
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

//------------------------------------------------------------------------
// HuffmanTree(const HuffmanTree &org) - Copy constructor
// Preconditions: Input is a huffmanTree obj
// Postconditions: Deep copy of passed in huffmanTree obj is created
HuffmanTree::HuffmanTree(const HuffmanTree &org)
{
    root = copyPrivate(org.root);
}

//------------------------------------------------------------------------
// copyPrivate() - Private helper method for traversal to deep copy
// Preconditions: Passed in root node of HuffmanTree obj to be copied
// Postconditions: Deep copy of passed in huffmanTree obj is created
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

//------------------------------------------------------------------------
// ~HuffmanTree - destuctor
// Preconditions: None
// Postconditions: Clears dynamically allocated memory

HuffmanTree::~HuffmanTree()
{
    clearTreePrivate(root);
}

//------------------------------------------------------------------------
// operator<
// Preconditions: Rhs object must be HuffmanTree obj
// Postconditions: returns true if lhs object is smaller than rhs

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

//------------------------------------------------------------------------
// operator=
// Preconditions: Rhs object must be HuffmanTree obj
// Postconditions: Assigns rhs obj to lhs HuffmanTree
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

//------------------------------------------------------------------------
// getChar - Gets the char
// Preconditions: None
// Postconditions: returns char from huffmanTree
char HuffmanTree::getChar() const
{
    return root->c;
}

//------------------------------------------------------------------------
// getFreq - Gets the frequency
// Preconditions: None
// Postconditions: returns int frequency from huffmanTree
int HuffmanTree::getFreq() const
{
    return root->freq;
}

//------------------------------------------------------------------------
// setChar - Sets the value of the character
// Preconditions: Passed in value must be a single char
// Postconditions: Sets value of char within huffmantree
void HuffmanTree::setChar(char ch)
{
    root->c = ch;
}

//------------------------------------------------------------------------
// setFreq - Sets the value of the frequency
// Preconditions: Passed in value must be a int value
// Postconditions: Sets value of int frequency within huffmantree
void HuffmanTree::setFreq(int f)
{
    root->freq = f;
}

//------------------------------------------------------------------------
// clearTreePrivate - Private helper method to clear the tree
// Preconditions: Passed in root node for traversal of tree
// Postconditions: Clears all dynamically allocated nodes
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

//------------------------------------------------------------------------
// isLeaf - Determines if a node is a leaft or not
// Preconditions: Pass in node
// Postconditions: return true if node is a leaf node within tree
bool HuffmanTree::isLeaf(Node *node)
{
    if (node->left == nullptr && node->right == nullptr)
    {
        return true;
    }
    return false;
}

//------------------------------------------------------------------------
// traverseCode - Traverses the HuffmanTree and stroes value in array
// Preconditions: Pass in an array to store char code
// Postconditions: Stores char code within array based off frequency
void HuffmanTree::traverseCode(string cBook[NUM_LETTERS])
{
    int index = 0;
    string code = "";
    traverseCodePrivate(root, code, index, cBook);
}

//---------------------------------------------------------------------------------
// traverseCodePrivate - Private helper method to traverse the tree
// Preconditions: None
// Postconditions: Stores char code within array based off frequency
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