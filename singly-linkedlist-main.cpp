#include<iostream>
using namespace std;

// Class to create the nodes
class Node{
    public:
        int key;// Will be unique to each node
        int data;// data can be repetitive
        Node * next;// next pointer is a pointer of type Node, which will point to the object of node type only

        Node(){// Default constructor
            key = 0;
            data = 0;
            next = NULL;
        }
        Node(int k, int d){// Parameteried constructor
            key = k;
            data = d;
        }
};

// Class in which the linking takes place
class SinglyLinkedList{
    public:
        Node * head;// Whenever we create an object of SinglyLinkedList, inside that object we will have a pointer which points to the head of the node

        SinglyLinkedList(){
            head = NULL;// head basically stores addresses, so NULL if nothing is passed
        }
        SinglyLinkedList(Node * n){// Passing the arguments by address
            head = n;// for head pointer to point to the newly passed node  
        }

        // 1.Check if a node exists using key value and avoid duplicate key values
        Node * nodeExists(int k){
            Node * temp = NULL;

            Node * ptr = head;// Store address in head pointer locally in temp, for traversing

            while (ptr != NULL)
            {
                // executes when the node exists
                if (ptr -> key == k)
                {
                    temp = ptr;
                }
                ptr = ptr -> next;// to store adress of the next node
            }
            return temp;
        }

        // 2.Append a node to the list
        void appendNode(Node * n){
            if (nodeExists(n -> key) != NULL)// because that function returns null when the key value does not already exist
            {
            cout <<"Node already exists with key value : "<<n -> key<<". Append another node with different key value"<<endl;
            }
            else
            {
                if (head == NULL)// when there is no previous node
                {
                    head = n;
                    cout << "Node Appended" << endl;
                }
                else
                {
                    // first traverse to the last node
                    Node * ptr = head;
                    while (ptr -> next != NULL)
                    {
                        ptr = ptr -> next;
                    }
                    ptr -> next = n;
                    cout << "Node Appended" << endl;
                }
            }
        }

        // 3.Prepend a node to the list
        void prependNode(Node * n){
            if (nodeExists(n -> key) != NULL)// because that function returns null when the key value does not already exist
            {
                cout<<"Node already exists with key value: "<<n -> key<<". Append another node with different key value"<< endl;
            }
            else
            {
                n -> next = head;// store the address of the first node in next pointer of the new node
                head = n;// change value of head to the adress of the new first node
                cout << "Node Prepended" << endl;
            }
        }

        // 4.Insert a node after a particular node in the list
        void insertNodeAfter(int k, Node * n){
            Node * ptr = nodeExists(k);// we will get a value back if the node exists
            // The pointer will directly point to the node whose key value is given
            if (ptr == NULL)
            {
                cout << "No node exists with key value: " << k << endl;
            }
            else
            {
                if (nodeExists(n -> key) != NULL)// because that function returns null when the key value does not already exist
                {
                    cout<<"Node already exists with key value: "<<n -> key<<". Append another node with different key value"<<endl;
                }
                else
                {
                    n -> next = ptr -> next;// store the same address which is in the node after which it is to be appended
                    ptr -> next = n;// link the node to the new node
                    cout<<"Node Inserted"<<endl;
                }
            }
        }

        // 5.Delete node by unique key
        void deleteNodeByKey(int k){
            if (head == NULL)
            {
                cout<<"List is empty, can't delete anything"<<endl;
            } 
            else if (head != NULL)
            {
                if (head -> key == k)
                {
                    head = head -> next;
                    cout<<"Node unlinked with key value: "<<k<<endl;
                }
                else
                {
                    Node * temp = NULL;
                    Node * prevptr = head;// points to the first node
                    Node * currentptr = head -> next;// points to the next node
                    while (currentptr != NULL)
                    {
                        if (currentptr -> key == k)
                        {
                            temp = currentptr;
                            currentptr = NULL;// found, done to stop while loop
                        }
                        else// traversing
                        {
                            prevptr = prevptr -> next;
                            currentptr = currentptr -> next;
                        }
                    }
                    if (temp != NULL)
                    {
                        prevptr -> next = temp -> next;// skip the node to be deleted
                        cout<<"Node unlinked with key value: "<<k<<endl;
                    }
                    else
                    {
                        cout<<"Node doesn't exist with key value: "<<k<<endl;
                    }
                }
            }
        }

        // 6.Update node using key
        void updateNodeByKey(int k, int d){
            Node * ptr = nodeExists(k);
            if (ptr != NULL)
            {
                ptr -> data = d;
                cout<<"Node data updated successfully"<<endl;
            }
            else
            {
                cout<<"Node doesn't exist with key value: "<<k<<endl;
            }
        }

        //  7.Printing the Linked List
        void printList(){
            if (head == NULL)
            {
                cout<<"No nodes are present";
            }
            else
            {
                cout<<endl<<"Singly Linked List values are:";
                Node * temp = head;

                while (temp != NULL)
                {
                    cout << "(" << temp -> key << "," << temp -> data << ") --> ";
                    temp = temp -> next;
                }
            }
        }
};

// Main function
int main(){
    SinglyLinkedList s;
    int option;
    int key1, k1, data1;
    do
    {
        cout<<"\nWhich operation to perform? Enter the option. \nEnter 0 to exit"<<endl;
        cout<<"1. appendNode()"<<endl;
        cout<<"2. prependNode()"<<endl;
        cout<<"3. insertNodeAfter()"<<endl;
        cout<<"4. deleteNodeByKey()"<<endl;
        cout<<"5. updateNodeByKey()"<<endl;
        cout<<"6. print()"<<endl;
        cout<<"7. Clear Screen"<<endl<<endl;

        cin >> option;

        Node * n1 = new Node();

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout<<"Append Node Operation \nEnter key & data of the Node to be appended"<<endl;
            cin >> key1;
            cin >> data1;
            n1 -> key = key1;
            n1 -> data = data1;
            s.appendNode(n1);
            break;

        case 2:
            cout<<"Prepend Node Operation \nEnter key & data of the Node to be prepended"<<endl;
            cin >> key1;
            cin >> data1;
            n1 -> key = key1;
            n1 -> data = data1;
            s.prependNode(n1);
            break;

        case 3:
            cout<<"Insert Node After Operation \nEnter key of existing Node after which you want to insert the new Node"<<endl;
            cin >> k1;
            cout << "Enter key & data of the New Node first: " << endl;
            cin >> key1;
            cin >> data1;
            n1 -> key = key1;
            n1 -> data = data1;
            s.insertNodeAfter(k1, n1);
            break;

        case 4:
            cout<<"Delete Node By Key Operation \nEnter key of the Node to be deleted"<<endl;
            cin >> k1;
            s.deleteNodeByKey(k1);
            break;

        case 5:
            cout<<"Update Node By Key Operation \nEnter key & new data to be updated"<<endl;
            cin >> key1;
            cin >> data1;
            s.updateNodeByKey(key1, data1);
            break;

        case 6:
            s.printList();
            break;

        case 7:
            system("cls");
            break;
            default:
            cout << "Enter Proper Option number " << endl;
            }
    }while (option != 0);

    return 0;
}