#include <iostream>
using namespace std;

class Node
{
public:
    int data;   // node data
    Node *prev; // node prev | address | link
    Node *next; // node next | address | link

    // constructor
    Node(int val)
    {
        data = val;
        prev = nullptr;
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
        temp->prev = head;
    }
}

void pop(Node *&head)
{
    // check if node does not present or not present stack
    if (head == nullptr)
    {
        cout << "Can't pop the node because stack is empty\n";
    }
    else
    {
        Node *nodToDelete = head;
        head = head->next;
        delete nodToDelete;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
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
        cout << "Stack is Empty";
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
    // call the isEmpty function
    cout << boolalpha; // this is used to formate the bool value
    cout << "Is Stack Empty: " << isEmpty(head) << endl;
    int value = Top(head);
    cout << "Data ::" << value << endl;
    // call the pop function
    pop(head);
    return 0;
}