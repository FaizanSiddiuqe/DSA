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

// function of insertsion of node to and end
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
    Node *head = nullptr; // nullptr is the better appraoch according to modern c++

    // calling insertion function
    insertAtEnd(head, 12);
    insertAtEnd(head, 13);
    insertAtEnd(head, 14);

    // calling print (elements) function
    printElementsOfNodes(head);

    // call function for delete the nodes
    deleteNodes(head);
    return 0;
}