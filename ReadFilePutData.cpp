#include <iostream>
#include <fstream>
using namespace std;

const string FILENAME = "FileInput.txt";

class Student{
private:
    int Id;
    float GPA;
    string department;

public:
    string Name;

    Student(int id, string name, float gpa, string dep){
        Id = id;
        Name = name;
        GPA = gpa;
        department = dep;
    }
    Student(){
        Id = 0;
        Name = "";
        GPA = 0;
        department = "";
    }

    bool setId(int id){
        if (id > 100){
            cout << "you cant put id greater than 100" << endl;
            return false;
        } else{
            Id = id;
            return true;
        }
    }
    int getId(){
        return Id;
    }

    float getGPA(){
        return GPA;
    }
    bool setGPA(float gpa){
        if (gpa > 4){
            cout << "There's no GPA greater than 4" << endl;
            return false;
        }else{
            GPA = gpa;
            return true;
        }
    }

    string getDepartment(){
        return department;
    }
    bool setDepartment(string dep){
        if (dep == "IT" or dep == "DS" or dep == "CS" or dep == "IS" or dep == "AI"){
            department = dep;
            return true;
        }else{
            cout << "No Department Called " << dep << endl;
            return false;
        }
    }
    void printStudent(){
        cout << "[Student : " << Name << " ID : " << Id << " GPA : " << GPA << " In Department : " << department << "]" << endl;
    }

    Student operator=(const Student & std){
        this->Id = std.Id;
        cout << "yeer";
        this->Name = "skadmas";
        cout << this->Name << endl;
        this->Name = std.Name;
        cout << std.Name << endl;

        this->department = std.department;
        this->GPA = std.GPA;
        return *this;
    }
};

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
