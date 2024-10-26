#include <iostream>
using namespace std;
// Note => this stack is made by simple array to understand how stack is work

// global variable by using to find the index
int top = -1;

// push element in the stack
void push(int stack[], int data)
{
    top++;
    stack[top] = data;
}

// pop element from the stack
void pop(int stack[])
{
    int elmentToDelete = stack[top];
    top--;
    cout << "Element is poped:: " << elmentToDelete << endl;
}

// check if stack is Empty
void isEmpty()
{
    if (top == -1)
    {
        cout << "Stck is empty\n";
    }
    else
    {
        cout << "Stack is not empty\n";
    }
}

// check is stack is fulfiled or not
void isFullFill(int size)
{
    if (top == size - 1)
    {
        cout << "Stack is full\n";
    }
    else
    {
        cout << "Stack is not full\n";
    }
}

// get the value
int Top(int stack[])
{
    int result = stack[top];
    return result;
}

int main()
{

    // create stack
    int stack[5];

    // call the push function
    push(stack, 1);
    push(stack, 2);
    push(stack, 34);
    // call the Top function
    cout << "Element on the top of the stack:: " << Top(stack) << endl;
    // call fulfiled function
    isFullFill(5);
    // call the isEmpty funtion
    isEmpty();
    // call the pop function
    pop(stack);
    cout << "Element on the top of the stack:: " << Top(stack) << endl;

    return 0;
}