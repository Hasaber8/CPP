#include <iostream>
#include <iomanip>
using namespace std;

int total_booked=0;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node()
    {
        data=0;
        next=NULL;
        prev=NULL;
    }
};

class LinkedList
{
public:

    Node *first;

    //Constructor
    LinkedList()
    {
        first=NULL;
    }

    //Creating LinkedList
    void Create()
    {
        Node *last,*t;

        first=new Node;
        first->data=0;
        first->next=first;
        first->prev=first;
        last=first;

        for(int i=0; i<6; i++)
        {
            t=new Node;
            t->data=0;
            t->prev=last;
            t->next=first;
            last->next=t;
            last=t;
        }
    }

    //Random Seat Booking
    void Random_booking(int n)
    {
        for(int i=0; i<3; i++)
        {
            int val=n+i;
            val=(val*(i+1))%7;

            Node *p=first;
            for(int j=0; j<val; j++)
            {
                p=p->next;
            }
            if(p->data==0)
            {
                p->data=1;
                total_booked++;
            }
        }
    }

    //Seat cancellation
    void Delete_Seat(int n)
    {
        Node *p=first;

        int c=1;

        while(c!=n)
        {
            c++;
            p=p->next;
        }

        if(p->data==1)
        {
            p->data=0;
            total_booked--;
            cout<<endl<<"Cancellation Successful"<<endl;
        }
        else
        {
            cout<<endl<<"You Have Entered a Seat Which is not Booked"<<endl;
        }
    }

    //Function to display
    void Display()
    {
        Node *p=first;

        do
        {
            cout<<setw(10)<<p->data;
            p=p->next;
        }
        while(p!=first);
        cout<<endl;
    }

    //Seat booking
    void Book_Seat(int n)
    {
        Node *p=first;

        int c=1;

        while(c!=n)
        {
            c++;
            p=p->next;
        }

        if(p->data==0)
        {
            p->data=1;
            total_booked++;
            cout<<endl<<"Booking Successful"<<endl;
        }
        else
        {
            cout<<endl<<"U Have Entered a Seat Which is Booked"<<endl;
        }

    }
};

void Display_All(LinkedList a[])
{

    cout<<endl<<setw(50)<<"---Status Of Seats---"<<endl;
    cout<<"---------------------------------------------------------------------------------"<<endl;
    cout<<"  "<<"R/C";
    for(int i=1;i<=7;i++)
        cout<<setw(10)<<i;
    cout<<endl<<"---------------------------------------------------------------------------------"<<endl;
    for(int i=0; i<10; i++)
    {
        cout<<"  "<<i+1<<" ";
        if(i!=9)
            cout<<" ";
        a[i].Display();
    }
    cout<<endl;
    cout<<"---------------------------------------------------------------------------------"<<endl;
}

int main()
{
    LinkedList arr[10];

    //Create The Seats...
    for(int i=0; i<10; i++)
    {
        LinkedList l;
        l.Create();
        l.Random_booking(i+10);
        arr[i]=l;
    }

    //Display_All(arr);
    bool flag=true;
    while(flag)
    {

        cout<<"---------------------------------------------------------------------------------"<<endl;
        Display_All(arr);

        cout<<"----MENU----"<<endl;
        cout<<"1: Booking a Seat"<<endl;
        cout<<"2: Canceling a Seat"<<endl;
        cout<<"0: Exit"<<endl;

        int choice;
        cout<<endl<<"Enter Your Choice: ";
        cin>>choice;

        if(choice==1)
        {
            if(total_booked>=70)
            {
                cout<<"Sorry, all Seats Are Booked"<<endl;
            }
            else
            {
                int row,col;
                cout<<endl<<"Enter row: ";
                cin>>row;

                if(row>0 && row<=10)
                {
                    cout<<"Enter column: ";
                    cin>>col;

                    if(col>0 && col<=7)
                    {
                        arr[row-1].Book_Seat(col);
                    }
                    else
                    {
                        cout<<endl<<"U Have Entered Wrong Column Number"<<endl;
                        cout<<"Booking Unsuccessful"<<endl;
                    }
                }
                else
                {
                    cout<<endl<<"You have Entered Wrong Row Number"<<endl;
                    cout<<"Booking Unsuccessful"<<endl;
                }
            }
        }

        else if(choice==2)
        {
            if(total_booked<=0)
            {
                cout<<endl<<"No Seat is Booked for Cancellation"<<endl;
            }
            else
            {
                int row,col;
                cout<<endl<<"Enter row: ";
                cin>>row;

                if(row>0 && row<=10)
                {
                    cout<<"Enter col: ";
                    cin>>col;

                    if(col>0 && col<=7)
                    {
                        arr[row-1].Delete_Seat(col);
                    }
                    else
                    {
                        cout<<endl<<"U Have Entered Wrong Column Number"<<endl;
                        cout<<"Cancellation Unsuccessful"<<endl;
                    }

                }
                else
                {
                    cout<<endl<<"U Have Entered Wrong Row Number"<<endl;
                    cout<<"Cancellation Unsuccessful"<<endl;
                }
            }
        }
        else if(choice==0)
        {
            cout<<endl<<"Program Executed Successfully"<<endl;
            cout<<"Thank You"<<endl;
            flag=false;
        }
        else
        {
            cout<<endl<<"Pls Enter a Valid Choice(0-2)"<<endl;
        }
    }
}