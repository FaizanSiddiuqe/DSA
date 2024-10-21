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
// insert node as a first node
void insertAtFirst(Node *&head, int data)
{
    Node *newNode = new Node(data);
    Node *temp = head;
    newNode->next = temp;
    head = newNode;
}

// print all the nodes
void printAllNodes(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << "Data of given Nodes:: " << temp->data << endl;
        temp = temp->next;
    }
}

int main()
{

    // head ptr which store the address of first node

    Node *head = NULL; // assign to null its not pointing to anyone

    // creating the nodes
    insertAtEnd(head, 12);
    insertAtEnd(head, 13);
    insertAtEnd(head, 14);
    // inserting the node at the first of the linkedList
    insertAtFirst(head, 11);
    // printing the nodes
    printAllNodes(head);

    return 0;
}