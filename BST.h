#include <iostream>
#include "Student.h"
using namespace std;

struct Node
{
    Student data;
    Node *left;
    Node *right;
    Node(Student val)
    {
        data.Name = val.Name;
        data.setId(val.getId());
        data.setDepartment(val.getDepartment());
        data.setGPA(val.getGPA());
        left = NULL;
        right = NULL;
    }
};

class BST
{
private:
    Node *root;
    Node *insert(Node *current, Student data)
    {
        if (current == NULL)
        {
            current = new Node(data);
        }
        else if (data.getId() < current->data.getId())
        {
            current->left = insert(current->left, data);
        }
        else
        {
            current->right = insert(current->right, data);
        }
        return current;
    }
    Node *search(Node *current, Student data)
    {
        if (current == NULL)
        {
            return NULL;
        }
        else if (data.getId() == current->data.getId())
        {
            return current;
        }
        else if (data.getId() < current->data.getId())
        {
            return search(current->left, data);
        }
        else
        {
            return search(current->right, data);
        }
    }

public:
    BST()
    {
        this->root = NULL;
    }
    void insert(Student data)
    {
        root = insert(root, data);
    }
    Node *getRoot()
    {
        return this->root;
    }
    void inOrder(Node *current)
    {
        if (current != NULL)
        {
            inOrder(current->left);
            cout << current->data.getId() << " " << current->data.Name << " " << current->data.getDepartment() << " " << current->data.getGPA() << "\n";
            inOrder(current->right);
        }
    }
    void search(Student data)
    {
        Node *current = search(this->root, data);
        if (current != NULL)
        {
            cout << current->data.getId() << " " << current->data.Name << " " << current->data.getDepartment() << " " << current->data.getGPA() << "\n";
        }
        else
        {
            cout << "Not Found";
        }
    }
    bool find(Student data)
    {
        Node *current = search(this->root, data);
        if (current != NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};