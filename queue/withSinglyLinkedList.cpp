#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// add node into the queue
// we use enqueue function for insertion of node
void enQueue(Node *&front, Node *&back, int data)
{

    // creating new node
    Node *newNode = new Node(data);

    // check if head && tail both are empty
    if (front == nullptr && back == nullptr)
    {
        front = newNode;
        back = newNode;
    }
    else
    {
        back->next = newNode;
        back = newNode;
    }
}

// delete node
// use deQueue function

void deQueue(Node *&front, Node *&back)
{
    if (front == nullptr)
    {
        cout << "Queue is not Exist or Empty\n";
        return;
    }
    else
    {
        
        Node *nodeToDelete = front;
        // check if front of next is exist or not
        if (front->next == nullptr)
        {
            front = nullptr;
            back = nullptr;
        }
        else
        {
            front = front->next;
        }
        delete nodeToDelete;
    }
}

// function to check queue if empty

bool isEmpty(Node *front, Node *back)
{
    if (front == nullptr && back == nullptr)
    {
        return true;
    }
    return false;
}

// print queue

void printQueue(Node *front)
{
    if (front == nullptr)
    {
        cout << "Queue is Empty\n";
        return;
    }
    else
    {
        Node *temp = front;
        while (temp != nullptr)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
}

int main()
{
    Node *front = nullptr;
    Node *back = nullptr;
    enQueue(front, back, 12);
    enQueue(front, back, 14);
    enQueue(front, back, 16);
    cout << boolalpha;
    // cout << isEmpty(front, back) << endl;
    printQueue(front);
    deQueue(front, back);
    printQueue(front);
    return 0;
}