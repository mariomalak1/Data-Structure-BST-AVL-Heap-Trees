#include <iostream>
using namespace std;
template <class T>
struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;
    Node(T val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
template <class T>
class BST
{
private:
    Node<T> *root;
    Node<T> *insert(Node<T> *current, T data)
    {
        if (current == NULL)
        {
            current = new Node<T>(data);
        }
        else if (data < current->data)
        {
            current->left = insert(current->left, data);
        }
        else
        {
            current->right = insert(current->right, data);
        }
        return current;
    }
    Node<T> *search(Node<T> *current, T data)
    {
        if (current == NULL)
        {
            return NULL;
        }
        else if (data == current->data)
        {
            return current;
        }
        else if (data < current->data)
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
    void insert(T data)
    {
        root = insert(root, data);
    }
    Node<T> *getRoot()
    {
        return this->root;
    }
    void inOrder(Node<T> *current)
    {
        if (current != NULL)
        {
            inOrder(current->left);
            cout << current->data << " ";
            inOrder(current->right);
        }
    }
    void search(T data)
    {
        Node<T> *current = search(this->root, data);
        if (current != NULL)
        {
            cout << endl << current->data << " ";
        }
        else
        {
            cout << "Not Found";
        }
    }
    bool find(T data)
    {
        Node<T> *current = search(this->root, data);
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