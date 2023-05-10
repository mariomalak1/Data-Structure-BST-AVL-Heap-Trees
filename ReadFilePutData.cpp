#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const string FILENAME = "FileInput.txt";

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
    Student() {}

    void setId(int id)
    {
        if (id > 100)
        {
            cout << "you cant put id greater than 100" << endl;
        }
        else
        {
            Id = id;
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
    void setGPA(float gpa)
    {
        if (gpa > 4)
        {
            cout << "There's no GPA greater than 4" << endl;
        }
        else
        {
            GPA = gpa;
        }
    }

    string getDepartment()
    {
        return department;
    }
    void setDepartment(string dep)
    {
        if (dep == "IT" || dep == "DS" || dep == "CS" || dep == "IS" || dep == "AI")
        {
            department = dep;
        }
        else
        {
            cout << "No Department Called " << dep << endl;
        }
    }
    void printStudent()
    {
        cout << "[Student : " << Name << " ID : " << Id << " GPA : " << GPA << " In Department : " << department << "]" << endl;
    }
};

class InputFile
{
public:
    static void putDataInTrees();

private:
    static void readInputFile(int numberOfStudents, fstream &File, Student *arrayStudent);
    static bool checkDataToReturnStudent(string id, string name, string gpa, string dep, Student &std);
};

void InputFile::putDataInTrees()
{
    fstream FileName;
    FileName.open(FILENAME, ios::in);
    if (!FileName)
    {
        cout << "File doesnt exist.";
    }
    else
    {
        int numberOfStudents = 0;
        string Line;
        // get number of student in the file
        if (!FileName.eof())
        {
            getline(FileName, Line);
            try
            {
                Student *arrayStudent = new Student[numberOfStudents];
                numberOfStudents = stoi(Line);
                readInputFile(numberOfStudents, FileName, arrayStudent);
            }
            catch (...)
            {
                cout << "Error While Reading Input File" << endl;
            }
        }
    }
}

void InputFile::readInputFile(int numberOfStudents, fstream &File, Student *arrayStudent)
{
    string id, name, gpa, dep;
    Student std;
    if (!File.eof())
    {
        // to take the line that write on the number of student
        getline(File, id);
    }
    if (!File.eof())
    {
        for (int i = 0; i < numberOfStudents; ++i)
        {
            getline(File, id);
            getline(File, name);
            getline(File, gpa);
            getline(File, dep);
            if (checkDataToReturnStudent(id, name, gpa, dep, std))
            {
            }
        }
    }
}

bool InputFile::checkDataToReturnStudent(string id, string name, string gpa, string dep, Student &std)
{
    try
    {
        int Id;
        float Gpa;
    }
    catch (...)
    {
    }
    //    Student std = new Student()
}
