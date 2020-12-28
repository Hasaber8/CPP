#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int leftThread;
    int rightThread;
    Node(int val)
    {
        this->data = val;
    }
};
class dtbt
{
private:
    Node *root;

public:
    dtbt()
    {
        root = new Node(INT_MAX);
        root->left = root->right = root;
        root->leftThread = 0;
        root->rightThread = 1;
    }
    void insert(int data)
    {
        Node *new_node = new Node(data);
        if (root->left == root && root->right == root)
        {
            new_node->left = root;
            root->left = new_node;
            new_node->leftThread = 0;
            new_node->rightThread = 0;
            root->leftThread = 1;
            new_node->right = root;
            return;
        }
        else
        {
            Node *current = root->left;
            while (true)
            {
                if (current->data > data)
                {
                    if (current->leftThread == 0)
                    {
                        new_node->left = current->left;
                        current->left = new_node;
                        new_node->leftThread = current->leftThread;
                        new_node->rightThread = 0;
                        current->leftThread = 1;
                        new_node->right = current;
                        break;
                    }
                    else
                    {
                        current = current->left;
                    }
                }
                else
                {
                    if (current->rightThread == 0)
                    {
                        new_node->right = current->right;
                        current->right = new_node;
                        new_node->rightThread = current->rightThread;
                        new_node->leftThread = 0;
                        current->rightThread = 1;
                        new_node->left = current;
                        break;
                    }
                    else
                    {
                        current = current->right;
                    }
                }
            }
        }
    }
    Node *findNextInorder(Node *current)
    {
        if (current->rightThread == 0)
        {
            return current->right;
        }
        current = current->right;
        while (current->leftThread != 0)
        {
            current = current->left;
        }
        return current;
    }
    void inorder()
    {
        Node *current = root->left;
        while (current->leftThread == 1)
        {
            current = current->left;
        }
        while (current != root)
        {
            cout << current->data << " ";
            current = findNextInorder(current);
        }
        cout << "\n";
    }
    void preorder()
    {
        Node *current = root->left;
        while (current != root)
        {
            cout << current->data << " ";
            if (current->left != root && current->leftThread != 0)
                current = current->left;
            else if (current->rightThread == 1)
            {
                current = current->right;
            }
            else
            {
                while (current->right != root && current->rightThread == 0)
                {
                    current = current->right;
                }
                if (current->right == root)
                    break;
                else
                {
                    current = current->right;
                }
            }
        }
        cout << "\n";
    }
    Node *inorderSuccessor(Node *current)
    {
        if (current->rightThread == 0)
            return current->right;
        current = current->right;
        while (current->leftThread == 1)
            current = current->left;
        return current;
    }
    Node *inorderPredecessor(Node *current)
    {
        if (current->leftThread == 0)
            return current->left;
        current = current->left;
        while (current->rightThread == 1)
        {
            current = current->right;
        }
        return current;
    }
    Node *caseA(Node *root, Node *parent, Node *current)
    {
        Node *parentSucc = current;
        Node *successor = current->right;
        while (successor->leftThread == 1)
        {
            parentSucc = successor;
            successor = successor->left;
        }
        current->data = successor->data;
        if (successor->leftThread == 0 && successor->rightThread == 0)
        {
            root->left = caseC(root, parentSucc, successor);
        }
        else
        {
            root->left = caseB(root, parentSucc, successor);
        }
        return root->left;
    }
    Node *caseB(Node *root, Node *parent, Node *current)
    {
        Node *child;
        if (current->leftThread == 1)
        {
            child = current->left;
        }
        else
        {
            child = current->right;
        }
        if (parent == nullptr)
        {
            root->left = child;
        }
        else if (current == parent->left)
        {
            parent->left = child;
        }
        else
        {
            parent->right = child;
        }
        Node *succesor = inorderSuccessor(current);
        Node *predecessor = inorderPredecessor(current);
        if (current->leftThread == 1)
        {
            predecessor->right = succesor;
        }
        else if (current->rightThread == 1)
        {
            succesor->left = predecessor;
        }
        free(current);
        return root->left;
    }
    Node *caseC(Node *root, Node *parent, Node *current)
    {
        if (parent == nullptr)
        {
            root->left = root;
        }
        else if (current == parent->left)
        {
            parent->leftThread = 0;
            parent->left = current->left;
        }
        else
        {
            parent->rightThread = 0;
            parent->right = current->right;
        }
        free(current);
        return root->left;
    }
};
int main()
{
    dtbt dtbt;
    dtbt.insert(124);
    dtbt.insert(22);
    dtbt.insert(4);
    dtbt.insert(52);
    dtbt.insert(6);
    dtbt.insert(2);
    dtbt.insert(32);
    dtbt.insert(99);
    dtbt.insert(100);
    cout << "Inorder:- \n";
    dtbt.inorder();
    cout << "Preorder:- \n";
    dtbt.preorder();
    return 0;
}
