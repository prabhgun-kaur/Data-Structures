#include <iostream>
using namespace std;


void heapify_max(int arr[], int n, int i) {
    int largest = i;        
    int l = 2*i + 1;        
    int r = 2*i + 2;        

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify_max(arr, n, largest);
    }
}

void heapify_min(int arr[], int n, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] < arr[smallest])
        smallest = l;
    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify_min(arr, n, smallest);
    }
}


void heapSortAscending(int arr[], int n) {
   
    for (int i = n/2 - 1; i >= 0; i--)
        heapify_max(arr, n, i);

    
    for (int i = n - 1; i >= 0; i--) {
        
        swap(arr[0], arr[i]);
        
        heapify_max(arr, i, 0);
    }
}


void heapSortDescending(int arr[], int n) {
   
    for (int i = n/2 - 1; i >= 0; i--)
        heapify_min(arr, n, i);

    
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify_min(arr, i, 0);
    }
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    
    int *arr1 = new int[n];
    int *arr2 = new int[n];
    for (int i = 0; i < n; i++) {
        arr1[i] = arr[i];
        arr2[i] = arr[i];
    }

    heapSortAscending(arr1, n);
    cout << "Sorted in ascending order: ";
    printArr(arr1, n);

    heapSortDescending(arr2, n);
    cout << "Sorted in descending order: ";
    printArr(arr2, n);

    delete[] arr;
    delete[] arr1;
    delete[] arr2;
    return 0;
}
