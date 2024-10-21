#include <iostream>
using namespace std;

class Node{
public:
int data;
Node* next;
// constructor for creating new node
Node(int val){
data = val;
next = NULL;
}
};

// get the length of the given linked list
int getLength(Node* head){
Node* temp = head;
int count = 0;
// checking if head is null there is no node
if (head == NULL)
{
   return 0;
}else
{
   while (temp != NULL)
{
    temp = temp->next;
    count++;
}
return count;
}
}

int main(){

Node* head = NULL; // pointing to the null 
int size = getLength(head);
// print the size of the linked list || in this case we will get zero(0) size 
cout<<"Size of the linked list :: "<<size<<endl;
return 0;
}
