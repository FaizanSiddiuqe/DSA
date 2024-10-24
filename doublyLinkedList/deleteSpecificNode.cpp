#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // constructor for assigning the value to new node
    Node(int val)
    {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// function of insertsion of node to an end
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

// delete the specific node
void deleteSpecificNode(Node *&head, int val)
{
        if (head == nullptr)
        {
            cout << "Linked list is not present\n";
          return;
        }

       if (head->data == val)
        {
           Node *nodeToDelete = head->prev;
            head = head->next;
            if (head->prev != nullptr)
            {
               head->prev = nullptr;
            }
            delete nodeToDelete;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                if (temp->data == val)
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete temp;
                }
                else
                {
                    temp = temp->next;
                }
            }
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
    // creating the head pointer
    Node *head = nullptr;

    // call the function for creating new node
    insertAtEnd(head, 12);
    insertAtEnd(head, 13);
    insertAtEnd(head, 14);
    insertAtEnd(head, 15);
    insertAtEnd(head, 12);

    // call the delete function
    deleteSpecificNode(head, 14);
    deleteSpecificNode(head, 12);

    printElementsOfNodes(head);
    return 0;
}