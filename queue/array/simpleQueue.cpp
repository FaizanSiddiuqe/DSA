#include <iostream>
using namespace std;

class Queue
{
private:
    int *arr;
    int front;
    int rear;
    int capacity;

public:
    Queue(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        front = 0;
        rear = 0;
    }

    ~Queue()
    {
        delete[] arr;
    }

    void enqueue(int data)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            arr[rear] == data;
            if (front > 0 && rear == capacity - 1)
            {
                rear = 0;
            }
            else
            {
                rear++;
            }
        }
    }

    void dequeue()
    {
        front++;
    }
    int getValue()
    {
        return (arr[front]);
    }
    bool isFull()
    {
        return (front == 0 && rear == capacity - 1);
    }
};

int main()
{

    Queue q(5);
    q.enqueue(10);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout << "Value at first index:: " << q.getValue() << endl;
    q.dequeue();
    cout << "Value at first index:: " << q.getValue() << endl;
    return 0;
}