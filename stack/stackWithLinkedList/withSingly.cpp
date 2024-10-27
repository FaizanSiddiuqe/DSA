#include <iostream>
using namespace std;

class Node
{
public:
    int data;   // node data
    Node *next; // node next | address | link

    // constructor
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// push function for adding the the node in the stack
void push(Node *&head, int data)
{
    // creating new node
    Node *newNode = new Node(data);

    // check if already node is present
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        head = newNode;
        head->next = temp;
        temp = head; // update the temp after new node
    }
}

// pop function for delete node from the stack
void pop(Node *&head)
{
    // check if node does not present or not present stack
    if (head == nullptr)
    {
        cout << "Can't pop the node because stack is empty\n";
    }
    else
    {
        Node *temp = head;
        Node *nodeToDelete = temp;
        head = temp->next;
        delete nodeToDelete;
        temp = nullptr; // updating the temp pointer after deleting the node
    }
}

// isEmpty function to check if stack is empty
bool isEmpty(Node *head)
{
    // if true mean stack is empty and similarly if false mean stack is not empty
    if (head == nullptr)
    {
        return true;
    }
    // other wise false
    return false;
}

// function to get the node data as well as can get its address etc
// mainly we get data
int Top(Node *head)
{
    // check if stack is empty
    if (head == nullptr)
    {
        cout << "Stack is Empty:: ";
    }

    // other wise we will return the Node
    return head->data;
}

int main()
{
    // creating head pointer which store the address of the last node
    Node *head = nullptr;
    // call the push function
    push(head, 12);
    push(head, 13);
    push(head, 14);
    // call  pop function
    pop(head);
    // call  top function
    int data = Top(head); // data of that which is placed at the top of the stack
    cout << "Data : " << data << endl;
    // call isEmpty function
    bool result = isEmpty(head);
    cout << boolalpha; // to convert 0 and 1 into true and false
    cout << "Is Stack Empty: " << result << endl;
    return 0;
}