#include <iostream>
using namespace std;

class SimpleQueue {
    int arr[100];
    int front, rear;

public:
    SimpleQueue() {
        front = 0;
        rear = -1;
    }

    void enqueue(int x) {
        if (rear == 99) {
            cout << "Queue Overflow\n";
            return;
        }
        arr[++rear] = x;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }
        return arr[front++];
    }

    bool isEmpty() {
        return front > rear;
    }

    int size() {
        return (rear - front + 1);
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Interleave using only ONE extra queue
    void interleave() {
        if (size() % 2 != 0) {
            cout << "Queue has odd number of elements, cannot interleave!" << endl;
            return;
        }

        int n = size();
        int half = n / 2;

        // Step 1: Put first half into extra queue
        SimpleQueue temp;
        for (int i = 0; i < half; i++) {
            temp.enqueue(dequeue());
        }

        // Step 2: Interleave temp (first half) with remaining (second half in current queue)
        while (!temp.isEmpty()) {
            enqueue(temp.dequeue());   // from first half
            enqueue(dequeue());        // from second half
        }
    }
};

int main() {
    SimpleQueue q;

    // Input
    q.enqueue(4);
    q.enqueue(7);
    q.enqueue(11);
    q.enqueue(20);
    q.enqueue(5);
    q.enqueue(9);

    cout << "Original Queue: ";
    q.display();

    q.interleave();

    cout << "Interleaved Queue: ";
    q.display();

    return 0;
}

