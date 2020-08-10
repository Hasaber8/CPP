#include <iostream>
#include <string.h>
using namespace std;

typedef struct student
{
    int roll_num;
    char name [20];
    float marks;
}stud;

void create(stud s[20],int n);
void display(stud s[20],int n);
void bubble_sort(stud s[20],int n);
void search(stud s[20],int n,float key);

int main()
{
    stud s[20];
    int ch, n, result;
    float key;
    char x[20];
    do
{
    cout<<"\n 1) Create Student Database";
    cout<<"\n 2) Display Student records";
    cout<<"\n 3) Bubble Sort";
    cout<<"\n 6) Linear Search";
    cout<<"\n 8) Exit";
    cout<<"\n Enter your choice:- ";
    cin>>ch;

switch(ch)
{
    case 1:
    cout<<"\n Enter the number of Records:- ";
    cin>>n;
    create(s,n);
    break;
    case 2:
    display(s,n);
    break;
    case 3:
    bubble_sort(s,n);
    break;
    case 6:
    cout<<"\n Enter the marks you want to search:- ";
    search(s,n,key);
    break;
    case 8:return 0;
        default:cout<<"\n Invalid Choice, Please enter the correct choice please."<<endl;
}
}while(ch!=8);
}
void create (stud s[20], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        cout<<"\n Enter the roll number:- ";
        cin>>s[i].roll_num;
        cout<<"\n Enter your name:- ";
        cin>>s[i].name;
        cout<<"\n Enter the marks:- ";
        cin>>s[i].marks;
    }
}

void display(stud s[20], int n)
{
    int i;
    cout<<"\n"<<"\t"<<"Roll No."<<"\t"<<"Name"<<"\t"<<"Marks";
    for (i=0;i<n;i++)
    {
        cout<<"\n";
        cout<<"\t"<<s[i].roll_num<<"\t"<<s[i].name<<"\t"<<s[i].marks;
    }
}

// Bubble Sort to sort in ascending order on roll number
void bubble_sort(stud s[20], int n)
{
    int i,j;
    stud temp;
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            if(s[j].roll_num>s[j+1].roll_num)
            {
                temp=s[j];
                s[j]=s[j+1];
                s[j=1]=temp;
            }
        }
    }
} 

// Linear search for marks if more than one student having same marks print all of them

void search(stud s[20], int n, float key)
{
    int i, flag=0;
    for (i=0; i<n; i++)
    {
        if (key==s[i].marks)
        {
            cout<<"\n"<<"\t"<<"Roll No."<<"\t"<<"Name"<<"\t"<<"Marks";
            cout<<"\n\t"<<s[i].roll_num<<"\t"<<s[i].name<<"\t"<<s[i].marks;
            flag=1;
        }
    }
    if(flag==0)
    cout<<"marks you are searching is not present";
}