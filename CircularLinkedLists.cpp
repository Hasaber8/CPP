#include <bits/stdc++.h>
using namespace std;

/* structure for a node */
class Node
{
public:
    int data;
    Node *next;
};

/* Function to insert a node at the beginning
of a Circular linked list */
void push(Node **head_ref, int data)
{
    Node *ptr1 = new Node();
    Node *temp = *head_ref;
    ptr1->data = data;
    ptr1->next = *head_ref;

    /* If linked list is not NULL then
    set the next of last node */
    if (*head_ref != NULL)
    {
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
        ptr1->next = ptr1; /*For the first node */

    *head_ref = ptr1;
}

/* Function to print nodes in
a given Circular linked list */
void printList(Node *head)
{
    Node *temp = head;
    if (head != NULL)
    {
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
}

/* Function to delete a given node from the list */
void deleteNode(Node **head, int key)
{

    if (*head == NULL) // If linked list is empty
        return;

    if ((*head)->data == key && (*head)->next == *head)
    { // If the list contains only a single node
        free(*head);
        *head = NULL;
        return;
    }

    Node *last = *head, *d;

    if ((*head)->data == key)
    {                               // If head is to be deleted
        while (last->next != *head) // Find the last node of the list
            last = last->next;

        // Point last node to the next of head i.e.
        // the second node of the list
        last->next = (*head)->next;
        free(*head);
        *head = last->next;
        return;
    }

    // Either the node to be deleted is not found
    // or the end of list is not reached
    while (last->next != *head && last->next->data != key)
    {
        last = last->next;
    }

    // If node to be deleted was found
    if (last->next->data == key)
    {
        d = last->next;
        last->next = d->next;
        free(d);
    }
    else
        cout << "\nNo such keyfound";
}

/* Driver program to test above functions */
int main()
{
    /* Initialize lists as empty */
    Node *head = NULL;

    /* Created linked list will be 11->2->56->12 */
    push(&head, 12);
    push(&head, 56);
    push(&head, 2);
    push(&head, 11);

    cout << "Contents of Circular Linked List\n ";
    printList(head);
    deleteNode(&head, 7);
    cout << "List After Deletion: ";
    printList(head);
    return 0;
}


