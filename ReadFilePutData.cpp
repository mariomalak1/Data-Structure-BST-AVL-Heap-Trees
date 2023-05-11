#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Student.h"
using namespace std;

const string FILENAME = "FileInput.txt";

class InputFile
{
public:
    static void LoadInVector(vector<Student> &arrayStudent);

private:
    static void readInputFile(int numberOfStudents, fstream &File, vector<Student> &arrayStudent);
    static bool checkDataToReturnStudent(string id, string name, string gpa, string dep, Student &std);
};

void InputFile::LoadInVector(vector<Student> &arrayStudent)
{
    fstream FileName;
    FileName.open(FILENAME, ios::in);
    if (!FileName)
    {
        cout << "File Doesn't exist.";
    }
    else
    {
        int numberOfStudents;
        string Line;
        // get number of student in the file
        if (!FileName.eof())
        {
            getline(FileName, Line);
            try
            {
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

void InputFile::readInputFile(int numberOfStudents, fstream &File, vector<Student> &arrayStudent)
{
    string id, name, gpa, dep;
    Student student;
    if (!File.eof())
    {
        for (int i = 0; i < numberOfStudents; ++i)
        {
            getline(File, id);
            getline(File, name);
            getline(File, gpa);
            getline(File, dep);
            if (checkDataToReturnStudent(id, name, gpa, dep, student))
            {
                arrayStudent.push_back(student);
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

        // convert from string to another data types
        Id = stoi(id);

        Gpa = stof(gpa);

        if (std.setId(Id))
        {
            if (std.setGPA(Gpa))
            {
                if (std.setDepartment(dep))
                {
                    std.setName(name);
                    return true;
                }
            }
        }
    }
    catch (...)
    {
        return false;
    }
    return false;
}
