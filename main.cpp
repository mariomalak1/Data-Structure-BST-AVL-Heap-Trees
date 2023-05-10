#include <iostream>
#include "BST.h"
using namespace std;
int main()
{
    BST<int> bst;
    bst.insert(31);
    bst.insert(30);
    bst.insert(45);
    bst.insert(2);
    bst.insert(10);
    bst.inOrder(bst.getRoot());

    return 0;
}
