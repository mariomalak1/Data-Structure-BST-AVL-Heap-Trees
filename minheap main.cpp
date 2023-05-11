#include <iostream>
#include <vector>
#include "minHeap.h"
#include "Student.h"
#include "ReadFilePutData.cpp"
using namespace std;
void insertInminHeap(minHeap &b, vector<Student> &v)
{
    // make the middle element of the vector the root to avoid insert sorted data in BST

    for (int i = 0; i < v.size() / 2; i++)
    {
        b.insert(v[i].getId(),v[i].getName(),v[i].getGPA(),v[i].getDepartment());
    }
}
int main()
{
    Student student(1, "Mohamed Ali", 3.4, "CS");
    vector<Student> StudentList;
    InputFile::LoadInVector(StudentList);
    minHeap minH;
    insertInminHeap(minH, StudentList);

    cout << "---------------------------" << endl;
    return 0;
}