
#include <iostream>
using namespace std;

#define MAX 5   // Maximum size of Queue

class Queue {
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is FULL. Cannot insert " << value << endl;
        } else {
            if (front == -1) front = 0;   // first element
            arr[++rear] = value;
            cout << value << " inserted into the queue.\n";
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY. Cannot delete.\n";
        } else {
            cout << arr[front] << " removed from the queue.\n";
            front++;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is EMPTY.\n";
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY.\n";
        } else {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                if (q.isEmpty()) cout << "Queue is EMPTY.\n";
                else cout << "Queue is NOT empty.\n";
                break;
            case 6:
                if (q.isFull()) cout << "Queue is FULL.\n";
                else cout << "Queue is NOT full.\n";
                break;
            case 0:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
