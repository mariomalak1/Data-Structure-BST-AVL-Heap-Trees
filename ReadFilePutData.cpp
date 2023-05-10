#include <iostream>
#include <fstream>
#include "Student.h"
using namespace std;

const string FILENAME = "FileInput.txt";


class InputFile {
public:
    static void putDataInTrees();

private:
    static void readInputFile(int numberOfStudents, fstream &File, Student * arrayStudent);
    static bool checkDataToReturnStudent(string id, string name, string gpa, string dep, Student &std);
};

void InputFile::putDataInTrees(){
    fstream FileName;
    FileName.open(FILENAME, ios::in);
    if (!FileName) {
        cout << "File doesnt exist.";
    } else {
        int numberOfStudents = 0;
        string Line;
        // get number of student in the file
        if (!FileName.eof()) {
            getline(FileName, Line);
            try {
                Student * arrayStudent = new Student[numberOfStudents];
                numberOfStudents = stoi(Line);
                readInputFile(numberOfStudents, FileName, arrayStudent);
            }
            catch (...) {
                cout << "Error While Reading Input File" << endl;
            }
        }
    }

}

void InputFile::readInputFile(int numberOfStudents, fstream &File, Student * arrayStudent){
    string id, name, gpa, dep;
    Student std;
    if (!File.eof()){
        for (int i = 0; i < numberOfStudents; ++i) {
            getline(File, id);
            getline(File, name);
            getline(File, gpa);
            getline(File, dep);
            if (checkDataToReturnStudent(id, name, gpa, dep, std)){
                arrayStudent[i] = std;
            }
        }
    }
    for (int i = 0; i < numberOfStudents; ++i) {
        arrayStudent[i].printStudent();
    }
}

bool InputFile::checkDataToReturnStudent(string id, string name, string gpa, string dep, Student &std) {
    try {
        int Id;
        float Gpa;

        // convert from string to another data types
        Id = stoi(id);

        Gpa = stof(gpa);

        if (std.setId(Id)){
            if (std.setGPA(Gpa)){
                if (std.setDepartment(dep)){
                    std.Name = name;
                    return true;
                }
            }
        }
    }
    catch (...){
        return false;
    }
    return false;
}
