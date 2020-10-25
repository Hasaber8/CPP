#include <iostream>
using namespace std;
typedef struct node
{ 
    char data;
    struct node *left;
    struct node *right;
}node;

typedef struct stacknode
{
    node *data;
    struct stacknode *next;
}stacknode;

class stack
{
    stacknode *top;
    public:
    stack()
    {
        top=NULL;
    }
    
    node *topp()
    {
        return (top -> data);
    }
    
    int isempty()
    {
        if(top==NULL)
            return 1;
        return 0;
    }
    
    void push(node* a)
    {
        stacknode *p;
        p=new stacknode();
        p->data=a;
        p->next=top;
        top=p;
    }
    
    node* pop()
    {
        stacknode *p;
        node* x;
        x=top->data;
        p=top;
        top=top->next;

        return x;
    }
};

node* create_per(char prefix[10]);
node* create_post(char postfix[10]);
void inorder_non_recursive(node *t);
void inorder(node *p);
void preorder(node *p);
void postorder(node *p);
void postorder_non_recursive(node *t);
void preorder_non_recursive(node *t);

node* create_post(char postfix[10])
{
    node *p,*p1,*p2;
    stack s;
        for (int i=0;postfix[i]!='\0';i++)
        {
            char token=postfix[i];
            if(isalnum(token))
            {
                p=new node();
                p->data=token;
                p->left=NULL;
                p->right=NULL;
                s.push(p);
            }
            else
            {
                p1 = s.pop();
                p2 = s.pop();
                p=new node();
                p->data=token;
                p->left=p2;
                p->right=p1;
                s.push(p);
            }
        }
        return s.pop();
}

node* create_per(char prefix[10])
{
    node *p;
    stack s;
    int i;
        for (int i;prefix[i]!='\0';i++)
        {

        }
        i=i-1;
    for(;i>=0;i--)
    {
        char token=prefix[i];
        if(isalnum(token))
        {
            p=new node();
            p->data=token;
            p->left=NULL;
            p->right=NULL;
            s.push(p);
        }
        else
        {
            p=new node();
            p->data=token;
            p->left=s.pop();
            p->right=s.pop();
            s.push(p);
        }
    }
    return s.pop();
}

void inorder(node *p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        cout<<p -> data;
        inorder(p->right);
    }
}

void preorder(node *p)
{
    if(p!=NULL)
    {
        cout<<p -> data;
        preorder(p->left);
        preorder(p->right);
    }
}

void postorder(node *p)
{
    if(p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        cout<<p->data;
    }
}

void inorder_non_recursive(node *t)
{
    stack s;
    while(t!=NULL)
    {
        s.push(t);
        t=t->left;
    }
    while(s.isempty()!=1)
    {
        t=s.pop();
        cout<<t->data;
        t=t->right;
        while(t!=NULL)
        {
            s.push(t);
            t=t->left;
        }
    }
}

void preorder_non_recursive(node *t)
{
    stack s;
    while(t!=NULL)
    {
        cout<<t->data;
        s.push(t);
        t=t->left;
    }
    while(s.isempty()!=1)
    {
        t=s.pop();
        t=t->right;
        while(t!=NULL)
        {
            cout<<t->data;
            s.push(t);
            t=t->left;
        }
    }
}

void postorder_non_recursive(node *t)
{
    stack s;
    while(t!=NULL)
    {
        cout<<t->data;
        s.push(t);
        t=t->left;
    }
    while(s.isempty()!=1)
    {
        t=s.pop();
        t=t->right;
        while(t!=NULL)
        {
            cout<<t->data;
            s.push(t);
            t=t->left;
        }
    }
}

int main()
{
    node *r=NULL, *r1;
    char postfix[10],prefix[10];
    int x;
    int ch,choice,result;
    do
    {
        cout<<"\n\t****TREE OPERATIONS****\n1. Construct tree from postfix / prefix expression";
        cout<<"\n2. Inorder Traversal of tree";
        cout<<"\n3. Preorder Traversal of tree";
        cout<<"\n4. Postorder Traversal of tree";
        cin>>ch;
        switch(ch)
        {
            case 1:cout<<"ENTER CHOICE: \n1. PostFix Expression \n2. Prefix Expression";
                cin>>choice;
                if(choice==1)
                {
                    cout<<"\nEnter postfix Expression:- ";
                    cin>>postfix;
                    r=create_post(postfix);
                }
                else
                {
                    cout<<"\nEnter prefix Expression:- ";
                    cin>>prefix;
                    r=create_per(prefix);
                }
                cout<<"\n\nTree created succesfully";
                break;
            case 2:cout<<"Inorder Traversal of tree:\n";
                inorder(r);
                cout<<"\nInorder traversal without recursion:- ";
                inorder_non_recursive(r);
                break;
            case 3:cout<<"Postorder Traversal of tree:\n";
                postorder(r);
                cout<<"\nPostorder traversal without recursion:- ";
                postorder_non_recursive(r);
                break;
            case 4:cout<<"Preorder traversal of tree:\n";
                preorder(r);
                cout<<"\nPreorder traversal without recursion:- ";
                preorder_non_recursive(r);
                break;
        }
    }while(ch!=5);
        return 0;
}