#include <iostream>
using namespace std;

struct node 
{
   char data;
   node *left;
   node *right;
};

char PostFix[50];
int top = -1;
node *a[50];
int r(char inputch) 
{
   if (inputch == '+' || inputch == '-' || inputch == '*' || inputch== '/')
      return (-1);
   else if (inputch >= 'A' || inputch <= 'Z')
      return (1);
   else if (inputch >= 'a' || inputch <= 'z')
      return (1);
   else
      return (-100);
}

int isempty()
{
    if(top==NULL)
        return 1;
    return 0;
}

void push(node *tree) 
{
   top++;
   a[top] = tree;
}

node *pop() 
{
   top--;
   return (a[top + 1]);
}

void create_post(char *suffix) 
{
   char s;
   node *newl, *p1, *p2;
   int flag;
   s = suffix[0];
   for (int i = 1; s != 0; i++) 
   {
      flag = r(s);
      if (flag == 1) 
      {
         newl = new node;
         newl->data = s;
         newl->left = NULL;
         newl->right = NULL;
         push(newl);
      } 
      else 
      {
         p1 = pop();
         p2 = pop();
         newl = new node;
         newl->data = s;
         newl->left = p2;
         newl->right = p1;
         push(newl);
      }
      s = suffix[i];
   }
}

void preOrder(node *tree) 
{
   if (tree != NULL) 
   {
      cout << tree->data;
      preOrder(tree->left);
      preOrder(tree->right);
   }
}

void inOrder(node *tree) 
{
   if (tree != NULL) 
   {
      inOrder(tree->left);
      cout << tree->data;
      inOrder(tree->right);
   }
}

void postOrder(node *tree) 
{
   if (tree != NULL) 
   {
      postOrder(tree->left);
      postOrder(tree->right);
      cout << tree->data;
   }
}

void postorder_non_recursive(node *tree)
{
    while(tree !=NULL)
    {
        cout<<tree->data;
        push(tree);
        tree=tree->left;
    }
    while(isempty()!=1)
    {
        tree=pop();
        tree=tree->right;
        while(tree !=NULL)
        {
            cout<<tree->data;
            push(tree);
            tree=tree->left;
        }
    }
}

int main(int argc, char **argv) 
{
   cout << "Enter Postfix Expression : ";
   cin >> PostFix;
   create_post(PostFix);
   cout << "\nIn-Order Traversal : ";
   inOrder(a[0]);
   cout << "\nPre-Order Traversal : ";
   preOrder(a[0]);
   cout << "\nPost-Order NonRecursive Traversal : ";
   postorder_non_recursive(a[0]);
   cout << "\nPost-Order Traversal : ";
   postOrder(a[0]);
   return 0;
}