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
    // check if linked list is exist
    if (head == nullptr)
    {
        cout << "Linked list is not present\n";
        return;
    }
    Node *temp = head;
    while (temp != nullptr) // Loop until temp reaches the end of the list
    {
        if (temp->data == val) // Node with the value to be deleted is found
        {
            // Case 1: Deleting the head node
            if (temp->prev == nullptr)
            {
                Node *nodeToDelete = temp;
                head = temp->next; // Update the head to the next node
                if (head != nullptr)
                {
                    head->prev = nullptr; // Set the new head's previous pointer to null
                }
                temp = head;         // Update temp to the next node
                delete nodeToDelete; // Free the memory of the deleted node
            }
            // Case 2: Deleting the tail node
            else if (temp->next == nullptr)
            {
                Node *nodeToDelete = temp;
                temp->prev->next = nullptr; // Update the previous node's next pointer to null
                delete nodeToDelete;        // Free the memory of the deleted node
                temp = nullptr;             // End the loop since the tail was deleted
            }
            // Case 3: Deleting a middle node
            else
            {
                Node *nodeToDelete = temp;
                temp->prev->next = temp->next; // Update the previous node's next pointer
                temp->next->prev = temp->prev; // Update the next node's previous pointer
                temp = temp->next;             // Move temp to the next node before deleting
                delete nodeToDelete;           // Free the memory of the deleted node
            }
        }
        else
        {
            temp = temp->next; // Move to the next node if no match is found
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
    insertAtEnd(head, 14);
    insertAtEnd(head, 12);

    // call the delete function
    deleteSpecificNode(head, 12);
    printElementsOfNodes(head);
    return 0;
}