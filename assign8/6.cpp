#include <iostream>
#include <climits>
using namespace std;

class PriorityQueue {
    int *heap;      
    int capacity;   
    int size;       

    
    int parent(int i)   { return (i - 1) / 2; }
    int left(int i)     { return 2*i + 1; }
    int right(int i)    { return 2*i + 2; }

    
    void heapifyDown(int i) {
        int l = left(i), r = right(i);
        int largest = i;
        if (l < size && heap[l] > heap[largest])
            largest = l;
        if (r < size && heap[r] > heap[largest])
            largest = r;
        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    
    void heapifyUp(int i) {
        while (i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

public:
    PriorityQueue(int cap) {
        capacity = cap;
        size = 0;
        heap = new int[cap];
    }

    ~PriorityQueue() {
        delete[] heap;
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == capacity;
    }

    void enqueue(int key) {
        if (isFull()) {
            cout << "Heap overflow — cannot insert\n";
            return;
        }
        heap[size] = key;
        size++;
        heapifyUp(size - 1);
    }

   
    int top() const {
        if (isEmpty()) {
            cout << "Heap is empty\n";
            return INT_MIN; 
        }
        return heap[0];
    }

   
    int dequeue() {
        if (isEmpty()) {
            cout << "Heap underflow — cannot dequeue\n";
            return INT_MIN;
        }
        int root = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
        return root;
    }
};

int main() {
    int n, cap;
    cout << "Enter capacity of priority queue: ";
    cin >> cap;
    PriorityQueue pq(cap);

    cout << "Enter number of elements to insert: ";
    cin >> n;
    cout << "Enter elements (priority = value):\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.enqueue(x);
    }

    cout << "Priority queue elements in decreasing priority (highest first):\n";
    while (!pq.isEmpty()) {
        cout << pq.dequeue() << " ";
    }
    cout << "\n";

    return 0;
}
