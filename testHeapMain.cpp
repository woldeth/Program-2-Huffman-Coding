

#include <iostream>
#include "Heap.h"
#include "HuffmanTree.cpp"

using namespace std;

int main()
{

    HuffmanTree *array[3];

    for (int i = 0; i < 3; i++)
    {
        HuffmanTree *ptr = new HuffmanTree(char('a' + i), 100 + i);
        array[i] = ptr;
    }

    Heap<HuffmanTree> mHeap(array, 3);

   


  //  n = mHeap; 

    cout << "look at data" << endl;

   // cout << n.deleteMin()->getChar() << " " << mHeap.deleteMin()->getChar() << endl;

    return 0;
}