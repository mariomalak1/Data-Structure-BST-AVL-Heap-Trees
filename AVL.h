#include <iostream>
#include "Student.h"
#include <cmath>
using namespace std;
struct Node_Avl
{
    Student data;
    Node_Avl *left;
    Node_Avl *right;
    Node_Avl(Student val)
    {
        data.setName(val.getName());
        data.setId(val.getId());
        data.setDepartment(val.getDepartment());
        data.setGPA(val.getGPA());
        left = NULL;
        right = NULL;
    }
};
class AVL
{
private:
    Node_Avl *root;
    int height(Node_Avl *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        int lheight = height(node->left);
        int rheight = height(node->right);
        return max(lheight, rheight) + 1;
    }
    bool isBalanced(Node_Avl *node)
    {
        if (node == NULL)
        {
            return true;
        }
        if (abs(height(node->left) - height(node->right)) > 1)
        {
            return false;
        }
        return isBalanced(node->left) && isBalanced(node->right);
    }
    int balanceFactor(Node_Avl *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        return height(node->left) - height(node->right);
    }
    Node_Avl *rotateLeft(Node_Avl *node)
    {
        Node_Avl *right = node->right;
        node->right = right->left;
        right->left = node;
        return right;
    }
    Node_Avl *rotateRight(Node_Avl *node)
    {
        Node_Avl *left = node->left;
        node->left = left->right;
        left->right = node;
        return left;
    }
    Node_Avl *insert(Node_Avl *node, Student s)
    {
        if (node == NULL)
        {
            node = new Node_Avl(s);
            return node;
        }
        if (s.getId() < node->data.getId())
        {
            node->left = insert(node->left, s);
        }
        else if (s.getId() >= node->data.getId())
        {
            node->right = insert(node->right, s);
        }
        else
        {
            return node;
        }
        int BalanceFactor = balanceFactor(node);
        if (BalanceFactor > 1 && s.getId() < node->left->data.getId()) // left left imbalance
        {
            node = rotateRight(node);
        }
        if (BalanceFactor > 1 && s.getId() > node->left->data.getId()) // left right imbalance
        {

            node = rotateLeft(node);
            return rotateRight(node);
        }
        if (BalanceFactor < -1 && s.getId() > node->right->data.getId()) // right right imbalance
        {
            node = rotateLeft(node);
        }
        if (BalanceFactor < -1 && s.getId() < node->right->data.getId()) // right left imbalance
        {
            node = rotateRight(node);
            return rotateLeft(node);
        }
        return node;
    }
    void inOrder(Node_Avl *node)
    {
        if (node == NULL)
        {
            return;
        }
        inOrder(node->left);
        cout << "********************************" << endl;
        cout << "Student ID: " << node->data.getId() << endl;
        cout << "Student Name: " << node->data.getName() << endl;
        cout << "Student GPA: " << node->data.getGPA() << endl;
        cout << "Student Department: " << node->data.getDepartment() << endl;
        cout << "********************************" << endl;
        inOrder(node->right);
    }
    void preOrder(Node_Avl *node)
    {
        if (node == NULL)
        {
            return;
        }
        cout << "********************************" << endl;
        cout << "Student ID: " << node->data.getId() << endl;
        cout << "Student Name: " << node->data.getName() << endl;
        cout << "Student GPA: " << node->data.getGPA() << endl;
        cout << "Student Department: " << node->data.getDepartment() << endl;
        cout << "********************************" << endl;
        preOrder(node->left);
        preOrder(node->right);
    }
    Node_Avl *search(Node_Avl *current, int id)
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
    bool find(int id)
    {
        Node_Avl *current = search(this->root, id);
        if (current != NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    Node_Avl *findMax(Node_Avl *current)
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
    Node_Avl *remove(Node_Avl *current, int id)
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
                Node_Avl *max = findMax(current->left);
                current->data = max->data;
                current->left = remove(current->left, max->data.getId());
            }
        }
        int BalanceFactor = balanceFactor(current);
        if (BalanceFactor > 1 && balanceFactor(current->left) >= 0) // left left imbalance
        {
            current = rotateRight(current);
        }
        if (BalanceFactor > 1 && balanceFactor(current->left) < 0) // left right imbalance
        {

            current = rotateLeft(current);
            return rotateRight(current);
        }
        if (BalanceFactor < -1 && balanceFactor(current->left) <= 0) // right right imbalance
        {
            current = rotateLeft(current);
        }
        if (BalanceFactor < -1 && balanceFactor(current->left) > 0) // right left imbalance
        {
            current = rotateRight(current);
            return rotateLeft(current);
        }
        return current;
    }

public:
    AVL()
    {
        this->root = NULL;
    }
    void insert(Student s)
    {
        root = insert(root, s);
    }
    void inOrder()
    {
        inOrder(root);
    }
    void search(int id)
    {
        Node_Avl *current = search(this->root, id);
        if (current != NULL)
        {
            cout << "Student ID: " << current->data.getId() << endl;
            cout << "Student Name: " << current->data.getName() << endl;
            cout << "Student GPA: " << current->data.getGPA() << endl;
            cout << "Student Department: " << current->data.getDepartment() << endl;
        }
        else
        {
            cout << "\033[31mNot Found\033[0m" << endl;
        }
    }
    void preOrder()
    {
        preOrder(root);
    }
    void remove(int id)
    {
        if (find(id))
        {
            root = remove(root, id);
            cout << "\033[31mDeleted\033[0m" << endl;
        }
        else
        {
            cout << "\033[31mItem Not Found to delete \033[0m" << endl;
        }
    }
};