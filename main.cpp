#include <iostream>
#include <vector>
#include "BST.h"
#include "Student.h"
#include "ReadFilePutData.cpp"
using namespace std;
void insertInBST(BST &b, vector<Student> &v)
{
    // make the middle element of the vector the root to avoid insert sorted data in BST
    for (int i = v.size() / 2; i < v.size(); i++)
    {
        b.insert(v[i]);
    }
    for (int i = 0; i < v.size() / 2; i++)
    {
        b.insert(v[i]);
    }
}
int main()
{
    Student student(1, "Mohamed Ali", 3.4, "CS");
    vector<Student> StudentList;
    InputFile::LoadInVector(StudentList);
    BST bst;
    insertInBST(bst, StudentList);
    // bst.inOrder(bst.getRoot());
    bst.search(1);
    bst.remove(8);
    cout << "---------------------------" << endl;
    bst.inOrder(bst.getRoot());
    return 0;
}
