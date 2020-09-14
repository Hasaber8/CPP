#include <cstdlib>
#include <iostream>

using namespace std;

int cqueue[5];
int front=-1;
int rear=-1;
int n=5;

void insertCQ(int val)
{
    if(front==0&&rear==n-1||front==rear+1)
    {
        cout<<"Queue is full"<<endl;
        return;
    }
    if(front==-1)
    {
        front=0;
        rear=0;
    }
    else
    {
        if(rear==n-1)
        {
            rear=0;
        }
        else
        {
            rear=rear+1;
        }
    }
    cqueue[rear]=val;
}

//Delete from the queue
void deleteCQ()
{
    if(front==-1)
    {
        cout<<"Queue is empty "<<endl;
        return;
    }
    cout<<"Element deleted from the Queue is : "<<cqueue[front]<<endl;
    
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        if(front==n-1)
        {
            front=0;
        }
        else
        {
            front=front+1;
        }
    }
}

//Display in forward direction

void displayCQ_forward()
{
    int f=front;
    int r=rear;
    if(front==-1)
    {
        cout<<"Queue is empty "<<endl;
        return;
    }
    cout<<"Queue Elements are : "<<endl;
    if(f<=r)
    {
        while(f<=r)
        {
            cout<<cqueue[f]<<"";
            f++;
        }
    }
    else
    {
        while(f<n-1)
        {
            cout<<cqueue<<"";
            f++;
        }
        f=0;
        while(f<=r)
        {
            cout<<cqueue[f]<<"";
            f++;
        }
    }
    cout<<endl;
}

//Display in reverse direction

void displayCQ_reverse(){
    int f=front;
    int r=rear;
    if(front==-1)
    {
        cout<<"Queue is empty "<<endl;
        return;
    }
    cout<<"Queue Elements are : "<<endl;
    
    if(f<=r)
    {
        while(f<=r)
        {
            cout<<cqueue[r]<<"";
            r--;
        }else
        {
            while(r>=0)
            {
                cout<<cqueue[r]<<"";
                r--;
            }
            r=n-1;
            while(r>=f)
            {
                cout<<cqueue<<"";
                r--;
            }
        }       
        cout<<endl;
    }   
}
int main()
{
    int ch, val;
    cout<<"1|Insert\n";
    cout<<"2|Delete\n";
    cout<<"3|Display forward\n";
    cout<<"4|Display reverse\n";
    cout<<"5|Exit\n";
    do
    {
        cout<<"Enter your choice:"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
            cout<<"Input fro insertion:"<<endl;
            cin>>val;
            insertCQ(val);
            break;
            
            case 2:
            deleteCQ();
            break;
            
            case 3:
            displayCQ_forward();
            break;

            case 4:
            displayCQ_reverse();
            break;

            case 5:
            cout<<"Exit\n";
            break;
            
            default:cout<<"Incorrect!\n";
        }
    }
}