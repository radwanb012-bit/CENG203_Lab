#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue()
{
    front = nullptr;
    rear = nullptr;
    count = 0;

}

Queue::~Queue()
{
    int dummy;
    while (dequeue(dummy));
}

void Queue::enqueue(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = newNode; 
    }
    else {
        rear->next = newNode; 
    }
    rear = newNode;
    count++;
}

bool Queue::dequeue(int& value)
{
    if (isEmpty()) return false;

    value = front->data;
    Node* temp = front;
    front = front->next;
    delete temp;
    count--;

    if (isEmpty()) {
        rear = nullptr; 
    }
    return true;
}

bool Queue::peek(int& value) const
{
    if (isEmpty()) return false;
    value = front->data;
    return true;
}

bool Queue::isEmpty() const
{
    return front == nullptr;
}

int Queue::size() const
{
    return count;
}

void Queue::display() const
{
    cout << "front ->";
    Node* current = front;
    while (current != nullptr) {
        cout << " " << current->data;
        current = current->next;
    }
    if (isEmpty()) {
        cout << " (empty)";
    }
    else {
        cout << " <- rear";
    }
    cout << endl;
}