#include <iostream>
#include "BST.h"
#include "Student.h"
using namespace std;
int main()
{
    Student s1(1, "joe", 3.41, "IT");
    Student s2(2, "mario", 3, "IT");
    Student s3(3, "ehab", 3, "IT");
    Student s4(4, "martina", 2.7, "IT");
    BST bst;
    bst.insert(s1);

    bst.insert(s3);
    bst.insert(s2);
    bst.insert(s4);
    bst.inOrder(bst.getRoot());
    return 0;
}
