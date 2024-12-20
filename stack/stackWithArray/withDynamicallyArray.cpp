#include <iostream>
using namespace std;

int top = -1; // top define the index in the stack  (-1 mean no there is no element in the  stack)

// push element from the stack
void push(int *&stack, int data, int size)
{
    if (top == size - 1)
    {
        cout << "Can't push any more element\n";
        return;
    }
    else
    {
        top++; // now top = 0 mean (zero index of the stack(stack))
        stack[top] = data;
    }
}

// pop element from the stack
void pop(int *&stack)
{

    // check if stack is not exist
    if (top == -1)
    {
        cout << "Can't pop the element because stack is empty\n";
        return;
    }
    else
    {
        cout << "Poped Element " << stack[top] << endl;
        top--;
    }
}

// check if stack is empty
void isEmpty()
{
    if (top != -1)
    {
        cout << "Stack is not Empty\n";
    }
    else
    {
        cout << "Stack is Empty\n";
    }
}

// check if stack is fullfilled
void isFullFilled(int size)
{
    if (top != size - 1)
    {
        cout << "Stack is not full\n";
        return;
    }
    else
    {
        cout << "Stack is full\n";
    }
}

// get the element from the stack  we can access only most top value from the stack
int Top(int *stack)
{
    // check if stack exist
    if (top == -1)
    {
        cout << "Stack is empty can't get any value\n";
        return -1;
    }
    // returning the element
    return stack[top];
}

int main()
{

    int size = 5;               // initialize the stack size
    int *stack = new int[size]; // declare as dynamically
    // call push function
    push(stack, 12, size);
    // call the pop function
    // pop(stack);
    // call the isEmpty function
    // isEmpty();
    // call isFullFilled
    // isFullFilled(size);

    delete[] stack; // free the allocate memory
    return 0;
}