#include<iostream>
using namespace std;
class Deque
{
private:
    int* data;
    int capacity;
    int front;   
    int rear;    
    int count;   

public:
    Deque(int size)
    {
        capacity = size;
        data = new int[capacity];
        front = 0;
        rear = capacity - 1;
        count = 0;
    }
    ~Deque()
    {
        delete[] data;
    }
    bool isEmpty()
    {
        return count == 0;
    }
    bool isFull()
    {
        return count == capacity;
    }
    bool push(int item)
    {
        if (isFull())return false;
        front = (front - 1 + capacity) % capacity;
        data[front] = item;
        count++;
        return true;
    }
    bool pop(int& item)
    {
        if (isEmpty())return false;
        item = data[front];
        front = (front + 1) % capacity;
        count--;
        return true;
    }
    bool inject(int item)
    {
        if (isFull())return false;
        rear = (rear + 1) % capacity;
        data[rear] = item;
        count++;
        return true;
    }
    bool eject(int& item)
    {
        if (isEmpty())return false;
        item = data[rear];
        rear = (rear - 1 + capacity) % capacity;
        count--;
        return true;
    }
};