#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int L = 2 * i + 1; // Left child index
    int R = 2 * i + 2; // Right child index

    if (L < n && arr[L] > arr[largest]) {
        largest = L;
    }
    if (R < n && arr[R] > arr[largest]) {
        largest = R;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    buildMaxHeap(arr, n);

    cout << "Max Heap array: ";
    printArray(arr, n);

    return 0;
}