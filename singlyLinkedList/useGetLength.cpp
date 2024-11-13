#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    // constructor for creating new node
    Node(int val)    {
        data = val;
        next = NULL;
    }
};

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
            count++;
            temp = temp->next;
        }
        return count;
    }
}

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

// print the element using for loop
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

    Node *head = NULL; // pointing to the null
    insertAtEnd(head, 12);
    insertAtEnd(head, 13);
    insertAtEnd(head, 14);
    int size = getLength(head);
    // print the size of the linked list || in this case we will get zero(0) size
    cout << "Size of the linked list :: " << size << endl;
    // print elements
    prinElementofLinkedList(head, size);
    return 0;
}
