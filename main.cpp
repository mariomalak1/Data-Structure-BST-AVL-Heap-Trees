#include <iostream>
#include <vector>
#include "BST.h"
#include "Student.h"
#include "ReadFilePutData.cpp"
using namespace std;
int main()
{
    vector<Student> StudentList;
    InputFile::LoadInVector(StudentList);
    BST bst;
    for (int i = 0; i < StudentList.size(); i++)
    {
        bst.insert(StudentList[i]);
    }
    bst.inOrder(bst.getRoot());
    return 0;
}
