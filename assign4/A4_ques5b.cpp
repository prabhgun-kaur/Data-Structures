#include <iostream>
using namespace std;

// ---------------- Queue Class ----------------
class Queue {
    int *arr;
    int front, rear, size, capacity;

public:
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = rear = -1;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }
        int val = arr[front];
        front = (front + 1) % capacity;
        size--;
        if (size == 0) {
            front = rear = -1;
        }
        return val;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    int getSize() {
        return size;
    }
};

// ---------------- Stack Class ----------------
class Stack {
    Queue q;

public:
    Stack(int cap) : q(cap) {}

    void push(int val) {
        q.enqueue(val);

        
        int n = q.getSize();
        for (int i = 0; i < n - 1; i++) {
            int x = q.dequeue();
            q.enqueue(x);
        }
    }

    void pop() {
        if (q.isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << "Popped: " << q.dequeue() << endl;
    }

    void peek() {
        if (q.isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Top element: " << q.peek() << endl;
    }

    bool isEmpty() {
        return q.isEmpty();
    }
};


int main() {
    Stack s(50);

    s.push(10);
    s.push(20);
    s.push(30);

    s.peek();    // Should print 30
    s.pop();     // Pops 30
    s.peek();    // Should print 20
    s.pop();     // Pops 20
    s.pop();     // Pops 10
    s.pop();     // Stack Underflow

    return 0;
}