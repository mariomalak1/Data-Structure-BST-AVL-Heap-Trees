//
// Created by lap top eur on ١٠/٠٥/٢٠٢٣.
//

#ifndef MAIN_CPP_STUDENT_H
#define MAIN_CPP_STUDENT_H
#include <iostream>
using namespace std;

class Student
{
private:
    int Id;
    float GPA;
    string department;

public:
    string Name;

    Student(int id, string name, float gpa, string dep)
    {
        Id = id;
        Name = name;
        GPA = gpa;
        department = dep;
    }
    Student()
    {
        Id = 0;
        Name = "";
        GPA = 0;
        department = "";
    }

    bool setId(int id)
    {
        if (id > 100)
        {
            cout << "you cant put id greater than 100" << endl;
            return false;
        }
        else
        {
            Id = id;
            return true;
        }
    }
    int getId()
    {
        return Id;
    }

    float getGPA()
    {
        return GPA;
    }
    bool setGPA(float gpa)
    {
        if (gpa > 4)
        {
            cout << "There's no GPA greater than 4" << endl;
            return false;
        }
        else
        {
            GPA = gpa;
            return true;
        }
    }

    string getDepartment()
    {
        return department;
    }
    bool setDepartment(string dep)
    {
        if (dep == "IT" || dep == "DS" || dep == "CS" || dep == "IS" || dep == "AI")
        {
            department = dep;
            return true;
        }
        else
        {
            cout << "No Department Called " << dep << endl;
            return false;
        }
    }
    void printStudent()
    {
        cout << "[Student : " << Name << " ID : " << Id << " GPA : " << GPA << " In Department : " << department << "]" << endl;
    }

    Student operator=(const Student &std)
    {
        this->Id = std.Id;
        this->Name = std.Name;
        this->department = std.department;
        this->GPA = std.GPA;
        return *this;
    }
};

#endif // MAIN_CPP_STUDENT_H
