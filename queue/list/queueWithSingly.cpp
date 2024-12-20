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

// enqueue function
void enqueue(Node *&front, Node *&back, int data)
{
    Node *newNode = new Node(data);
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

// isEmpty funtion
bool isEmpty(Node *front, Node *back)
{
    return (front == nullptr && back == nullptr);
}
// dequeue function
void dequeue(Node *&front, Node *&back)
{
    if (isEmpty(front, back))
    {
        cout << "Can't perform this action Queue is Empty\n";
    }
    else
    {
        Node *nodeToDelete = front;

        // check deleting is a last node
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

// peak function to get the current value
int peek(Node *front)
{
    if (front == nullptr)
    {
        return -1;
    }

    return front->data;
}

int main()
{

Node* front = nullptr;
Node* back = nullptr;

// call enqueue functin
enqueue(front, back, 12);
enqueue(front, back, 14);
// call the peak function
// call the dequeue funciton
dequeue(front, back);
dequeue(front, back);
cout<<"Data on the Top:: "<<peek(front)<<endl;

return 0;
}