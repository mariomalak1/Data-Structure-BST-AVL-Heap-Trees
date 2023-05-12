//
// Created by ehaba on 5/11/2023.
//
#include <iostream>
#include<string>
#include "Student.h"
#ifndef UNTITLED3_MINHEAP_H
#define UNTITLED3_MINHEAP_H

class minHeap {

private :
private:
    int maxSize;
    int size;
    Student *array;
public:
    minHeap(){
        size = 0;
        array = new Student [size];
    }
    minHeap(int size){
        this-> maxSize = size;
        this->size = 0;
        array = new Student [maxSize];
    }
    int parent(int i) { return (i-1)/2; }
    int firstChild(int i) { return (i*2+1); }
    int secChild(int i) { return (i*2+2); }

    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }

    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }

    void insert(int id,string name ,float gpa,string dep){
        size++;
        Student *newArray = new Student [size];
        for (int i = 0; i < size-1;i++){
            newArray[i] = array[i];
        }
        newArray[size-1].setId(id);
        newArray[size-1].setDepartment(dep);
        newArray[size-1].setGPA(gpa);
        newArray[size-1].setName(name);
        array = newArray;

        int temp = size-1;
        while (temp != 0 && array[temp].getGPA() < array[parent(temp)].getGPA()) {
            swap(array[parent(temp)], array[temp]);
            temp = parent(temp);

        }

    }
    void sortByGpa(Student arr[], int size)
    {
        int min;
        for (int i = 0; i < size - 1; i++)
        {
            min = i;
            for (int j = i + 1; j < size; j++)
            {
                if (arr[j].getGPA() < arr[min].getGPA())
                {
                    min = j;
                }
            }
            swap(arr[min], arr[i]);
        }
    }

    void print() {
        Student *newArray = new Student [size];
        for (int i = 0; i < size;i++){
            newArray[i] = array[i];
        }
        sortByGpa(newArray,size);
        for (int i = 0;i < size;i++ ){
            newArray[i].printStudent();
        }
    }

    void swap(Student & a,Student & b){
        Student c ;
        c = a;
        a = b;
        b = c ;
    }


};


#endif //UNTITLED3_MINHEAP_H
