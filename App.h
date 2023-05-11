#include <iostream>
#include "Student.h"
#include "ReadFilePutData.cpp"
#include "BST.h"
#include "minHeap.h"
#include "maxHeap.h"
#include <conio.h>
#include <string>
using namespace std;
class Application
{
private:
    vector<Student> StudentList;
    void loadStudentList()
    {
        InputFile::LoadInVector(StudentList);
    }
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
    void insertInMinHeap(minHeap &b, vector<Student> &v)
    {
        // make the middle element of the vector the root to avoid insert sorted data in BST

        for (int i = 0; i < v.size(); i++)
        {
            b.insert(v[i].getId(), v[i].getName(), v[i].getGPA(), v[i].getDepartment());
        }
    }
    void insertInMaxHeap(maxHeap &b, vector<Student> &v)
    {
        // make the middle element of the vector the root to avoid insert sorted data in BST

        for (int i = 0; i < v.size(); i++)
        {
            b.insert(v[i].getId(), v[i].getName(), v[i].getGPA(), v[i].getDepartment());
        }
    }
    BST bst;
    minHeap min_Heap;
    maxHeap max_Heap;
    bool insertStudent(Student &newStudent)
    {

        string name, dep;
        int id;
        float GPA;
        cout << "Enter Student ID:" << endl;
        cin >> id;
        cout << "Enter Student Name:" << endl;
        cin.clear();
        cin.ignore();
        getline(cin, name);
        cout << "Enter Student Department:" << endl;
        getline(cin, dep);
        cout << "Enter Student GPA:" << endl;
        cin >> GPA;
        if (newStudent.setId(id))
        {
            if (newStudent.setName(name))
            {
                if (newStudent.setDepartment(dep))
                {
                    if (newStudent.setGPA(GPA))
                    {
                        StudentList.push_back(newStudent);
                        bst.insert(newStudent);
                        return true;
                    }
                }
            }
        }
        return false;
    }

public:
    void MainMenu()
    {
        int choice;
        InputFile::LoadInVector(StudentList);
    startMainMenu:
        cout << "================================" << endl;
        cout << "            Main Menu           " << endl;
        cout << "================================" << endl;
        cout << "1- BST" << endl;
        cout << "2- AVL" << endl;
        cout << "3- Min Heap" << endl;
        cout << "4- Max Heap" << endl;
        cout << "5- Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            system("cls");
            BST_Menu(bst);
            break;
        }
        case 3:
        {
            system("cls");
            minHeap_Menu(min_Heap);
            break;
        }
        case 4:
        {
            system("cls");
            maxHeap_Menu(max_Heap);
            break;
        }
        case 5:
        {
            exit(0);
            break;
        }
        default:
        {
            system("cls");
            cout << "+------------------------------+" << endl;
            cout << "Invalid Choice" << endl;
            cout << "+------------------------------+" << endl;
            cin.clear();
            cin.ignore();
            break;
        }
        }
        goto startMainMenu;
    }
    void BST_Menu(BST &bst)
    {
        int choice;
        insertInBST(bst, StudentList);
    start:
        cout << "================================" << endl;
        cout << "            BST Menu            " << endl;
        cout << "================================" << endl;
        cout << "1- Add Student" << endl;
        cout << "2- Remove Student" << endl;
        cout << "3- Search Student" << endl;
        cout << "4- Print All Students (Sorted By ID)" << endl;
        cout << "5- Return to Main Menu " << endl;
        cout << "What is Your Choice? ----> ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            Student newStudent;
            if (insertStudent(newStudent))
            {
                bst.insert(newStudent);
                break;
            }
            cout << "Invalid Student Information" << endl;
            break;
        }
        case 2:
        {
            int id;
            cout << "Enter Student ID:" << endl;
            cin >> id;
            system("cls");
            cout << "+------------------------------+" << endl;
            bst.remove(id);
            cout << "+------------------------------+" << endl;
            break;
        }
        case 3:
        {
            int id;
            cout << "Enter Student ID:" << endl;
            cin >> id;
            system("cls");
            cout << "+------------------------------+" << endl;
            bst.search(id);
            cout << "+------------------------------+" << endl;
            break;
        }
        case 4:
        {
            system("cls");
            cout << "+------------------------------+" << endl;
            bst.inOrder(bst.getRoot());
            cout << "+------------------------------+" << endl;
            break;
        }
        case 5:
        {
            system("cls");
            MainMenu();
            break;
        }
        default:
        {
            system("cls");
            cout << "+------------------------------+" << endl;
            cout << "Invalid Choice" << endl;
            cout << "+------------------------------+" << endl;
            cin.clear();
            cin.ignore();
            break;
        }
        }
        goto start;
    }
    void minHeap_Menu(minHeap &min_heap)
    {
        int choice;
        insertInMinHeap(min_heap, StudentList);
    start:
        cout << "================================" << endl;
        cout << "         Min Heap Menu        " << endl;
        cout << "================================" << endl;
        cout << "1- Add Student" << endl;
        cout << "2- Print Student (Sorted by GPA)" << endl;
        cout << "3- Return to Main Menu" << endl;
        cout << "What is Your Choice? ----> ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            Student newStudent;
            if (insertStudent(newStudent))
            {
                min_heap.insert(newStudent.getId(), newStudent.getName(), newStudent.getGPA(), newStudent.getDepartment());
                break;
            }
            cout << "Invalid Student Information" << endl;
            break;
        }
        case 2:
        {
            system("cls");
            cout << "+------------------------------+" << endl;
            min_heap.print();
            cout << "+------------------------------+" << endl;
            break;
        }
        case 3:
        {
            system("cls");
            MainMenu();
            break;
        }
        default:
        {
            system("cls");
            cout << "+------------------------------+" << endl;
            cout << "Invalid Choice" << endl;
            cout << "+------------------------------+" << endl;
            cin.clear();
            cin.ignore();
            break;
        }
        }
        goto start;
    }
    void maxHeap_Menu(maxHeap &max_heap)
    {
        int choice;
        insertInMaxHeap(max_heap, StudentList);
    start:
        cout << "================================" << endl;
        cout << "         Min Heap Menu        " << endl;
        cout << "================================" << endl;
        cout << "1- Add Student" << endl;
        cout << "2- Print Student (Sorted by GPA)" << endl;
        cout << "3- Return to Main Menu" << endl;
        cout << "What is Your Choice? ----> ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            Student newStudent;
            if (insertStudent(newStudent))
            {
                max_heap.insert(newStudent.getId(), newStudent.getName(), newStudent.getGPA(), newStudent.getDepartment());
                break;
            }
            cout << "Invalid Student Information" << endl;
            break;
        }
        case 2:
        {
            system("cls");
            cout << "+------------------------------+" << endl;
            max_heap.print();
            cout << "+------------------------------+" << endl;
            break;
        }
        case 3:
        {
            system("cls");
            MainMenu();
            break;
        }
        default:
        {
            system("cls");
            cout << "+------------------------------+" << endl;
            cout << "Invalid Choice" << endl;
            cout << "+------------------------------+" << endl;
            cin.clear();
            cin.ignore();
            break;
        }
        }
        goto start;
    }
};
