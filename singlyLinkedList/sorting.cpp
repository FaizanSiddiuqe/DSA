#include <iostream>
using namespace std;

// making node
class Node
{
public:
    int data;
    Node *next;
    // constructor
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// inserting value at the end of the node
void insertAtEnd(Node *&head, int data)
{
    Node *newNode = new Node(data);

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// get the length of the given linked list
int getLength(Node *head)
{
    Node *temp = head;
    int count = 0;
    // checking if head is null there is no node
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        while (temp != NULL)
        {

            temp = temp->next;
            count++;
        }
        return count;
    }
}

// sorting in accending order using bubble sort
void sortinElementInAccendingOrder(Node *head, int size)
{
    if (head == NULL)
        return;

    for (int i = 0; i < size; i++)
    {
        Node *temp = head;
        for (int j = 0; j < size - 1; j++)
        {
            if (temp->data > temp->next->data)
            {
                int tempData = temp->data;
                temp->data = temp->next->data;
                temp->next->data = tempData;
            }
            temp = temp->next;
        }
    }
}

// print element of the given linked list
void prinElementofLinkedList(Node *head, int size)
{
    Node *temp = head;
    for (int i = 0; i < size; i++)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
int main()
{
    Node *head = NULL;
    // inserting the element
    insertAtEnd(head, 15);
    insertAtEnd(head, 14);
    insertAtEnd(head, 12);
    insertAtEnd(head, 13);
    insertAtEnd(head, 11);

    // size of the linked list
    int size = getLength(head);

    // sorting
    sortinElementInAccendingOrder(head, size);

    // print sorted element
    prinElementofLinkedList(head, size);
    return 0;
}