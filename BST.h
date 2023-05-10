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
        data.setName(val.getName());
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
    Node *search(Node *current, int id)
    {
        if (current == NULL)
        {
            return NULL;
        }
        else if (id == current->data.getId())
        {
            return current;
        }
        else if (id < current->data.getId())
        {
            return search(current->left, id);
        }
        else
        {
            return search(current->right, id);
        }
    }
    Node *findMax(Node *current)
    {
        if (current == NULL)
        {
            return NULL;
        }
        else if (current->right == NULL)
        {
            return current;
        }
        else
        {
            return findMax(current->right);
        }
    }
    Node *remove(Node *current, int id)
    {
        if (current == NULL)
        {
            return NULL;
        }
        if (id < current->data.getId())
        {
            current->left = remove(current->left, id);
        }
        else if (id > current->data.getId())
        {
            current->right = remove(current->right, id);
        }
        else
        {
            if (current->left == NULL && current->right == NULL)
            {

                delete current;
                current = NULL;
            }
            else if (current->left != NULL && current->right == NULL) // one child left
            {
                current->data = current->left->data;
                if (current->left->left != NULL)
                {
                    current->left = current->left->left;
                }
                else
                {
                    delete current->left;
                    current->left = NULL;
                }
            }
            else if (current->left == NULL && current->right != NULL) // one child right
            {
                current->data = current->right->data;
                if (current->right->right != NULL)
                {
                    current->right = current->right->right;
                }
                else
                {
                    delete current->right;
                    current->right = NULL;
                }
            }
            else
            {
                Node *max = findMax(current->left);
                current->data = max->data;
                current->left = remove(current->left, max->data.getId());
            }
        }
        return current;
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
            cout << current->data.getId() << " " << current->data.getName() << " " << current->data.getDepartment() << " " << current->data.getGPA() << "\n";
            inOrder(current->right);
        }
    }
    void search(int id)
    {
        Node *current = search(this->root, id);
        if (current != NULL)
        {
            cout << current->data.getId() << " " << current->data.getName() << " " << current->data.getDepartment() << " " << current->data.getGPA() << "\n";
        }
        else
        {
            cout << "Not Found" << endl;
        }
    }
    bool find(int id)
    {
        Node *current = search(this->root, id);
        if (current != NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void remove(int id)
    {
        if (find(id))
        {
            root = remove(root, id);
            cout << "Deleted" << endl;
        }
        else
        {
            cout << "Item Not Found to delete " << endl;
        }
    }
};