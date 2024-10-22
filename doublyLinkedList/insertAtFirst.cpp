#include <iostream>
using namespace std;

// creating node
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // constructor for creating newNode
    Node(int val)
    {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// insert at first
void insertAtBegining(Node *&head, int data)
{
    Node *newNode = new Node(data);

    if (head == nullptr)
    {
        cout << "Head is Empty || no linked list is present\n";
        return;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

/*
// function of insertion of node to an end
void insertAtEnd(Node *&head, int data)
{
    Node *newNode = new Node(data);

    // check condition if node is already exist
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        // creating temporary pointer which also point to first node
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        // giving the address of previous node to the prev pointer of newNode
        newNode->prev = temp;
    }
}
*/

// function for deleting the dynamically nodes
void deleteNodes(Node *&head)
{

    if (head == nullptr)
    {
        cout << "No Node is present to delete\n";
        return;
    }
    else
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
        cout << "All nodes are Deleted\n";
    }
}

// print all elements of the node's
void printElementsOfNodes(Node *head)
{
    Node *temp = head;

    // check condition if node is not present or say linkedList have zero size
    if (head == nullptr)
    {
        cout << "The list is Empty\n";
        return;
    }
    else
    {
        // while temp is not pointing to nullptr || mean next (pointer) of last node does point to nullptr
        while (temp != nullptr)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
}

int main()
{
    // head pointer which store the address of first node
    Node *head = nullptr;

    /*
     // call the function of insertation at the end
    insertAtEnd(head, 12);   // run this funtion when after run or complete the concept how insert at the begining
 insertAtEnd(head, 13);
    */

    // call the function of insertion at the begning of the list
    insertAtBegining(head, 11);

    // call the print functon
    printElementsOfNodes(head);

    // call the delete function
    deleteNodes(head);
    return 0;
}