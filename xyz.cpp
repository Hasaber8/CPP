#include <iostream>
#include <string.h>
using namespace std;
string postfix(string exp); 
void evaluatePostfix(string exp);
class StackNode
{
public :
    char key;
    StackNode *next;
    StackNode(int val)
    {
        key = val;
        next=nullptr;
    }
};
void push (StackNode** head , char val)
{
    StackNode* new_node = new StackNode(val);
    new_node->next = *head;
    *head = new_node;
}
char pop(StackNode** head )
{
    if(head==nullptr)
    {
        cout<<"Empty Stack... cannot perform pop\n";
        return ' ';
    }
    StackNode* temp = *head;
    (*head) = (*head)->next;
    char popped = temp->key;
    free(temp);
    return popped;
}
bool isEmpty(StackNode* head)
{
    return head == nullptr;
}
char top(StackNode* head)
{
    if(isEmpty(head))
    {
        cout<<"Empty Stack\n";
        return ' ';
    }
    return head->key;
}
int main()
{
    cout<<"Enter the infix expression \n";
    string exp;
    cin>>exp;
    string temp ="231*+9-";
    evaluatePostfix(temp);
	return 0;
}
int precedence(char check)
{
    if(check == '+'  || check == '-' )
        return 1;
    else if (check== '*'  || check=='/' )
        return 2;
    else if(check == '^')
        return 3;
    else
        return -1;
}
string postfix(string exp)
{
    StackNode* head = nullptr;
    int size = exp.length();
    string op;
    for(int i = 0; i<size ; i++)
    {
        if( (exp[i] >= 'a' && exp[i] <= 'z') || isdigit(exp[i])  )
            op+= exp[i];
        
        else if(exp[i] == '(' )
            push(&head , exp[i]);
            
        else if(exp[i] == ')' )
        {
            while(isEmpty(head) == false && top(head) != '(')
            {
                char c = top(head);
                pop(&head);
                op+= c;
            }
            if(top(head) == '(')
                pop(&head);
        }
        else{
            while( (isEmpty(head) == false) && (precedence(exp[i]) <= precedence( top(head) ) ) )
            {
                    char c = top(head);
                    pop(&head);
                    op+= c;
            }
            push(&head , exp[i]);
        }
    }
    while(isEmpty(head) == false)
    {
        char c = top(head);
        pop(&head);
        op+= c;
    }
    cout<<"\nPostfix expression is   "<<op;
    return op;
}
void evaluatePostfix(string exp)
{
    StackNode* root = nullptr; 
    int size = exp.length();
    string evaluation;
    char op1{} , op2{};
    for(int i = 0 ; exp[i] ; i++)
    {
        if( (exp[i] >= 'a' && exp[i] <= 'z') || isdigit(exp[i])  )
        {
            push(&root , exp[i]-'0');
        }
        else
        {
            op1 = pop(&root);
            op2 = pop(&root);
            switch (exp[i])
            {
                case '+' : push(&root , op2 + op1);
                                break;
                case '-' : push(&root , op2 - op1);
                               break;
                case '*' : push(&root , op2 * op1);
                               break;
                case '/' : push(&root , op2 / op1);
                               break;
            }
        }
    }
    cout<<"\nEvaluation of postfix expression is   "<<pop(&root);
}