#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class Tree{
    public:
    int maxLevel = 0;

    void leftView(Node *root,int level){
        if(root == NULL){
            return;
        }
        if(maxLevel<level){
            cout<<root->data<<" ";
            maxLevel = level;
        }
        leftView(root->right,level+1);
        leftView(root->left,level+1);
    }
};


int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    Tree tree;
    tree.leftView(root,1);
    return 0;
}