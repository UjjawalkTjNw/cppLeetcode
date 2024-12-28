
/*
max heap stores max elemnt at top
so if u add minus before each element it will heapfify and bring lowest at top

Then again convert back to positive value by applying minus
This was the lowest will remain at top
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Function to convert max heap to min heap
priority_queue<int, vector<int>, greater<int>> convertMaxToMinHeap(priority_queue<int> maxHeap) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    // Convert max heap to min heap by pushing negative values
    while (!maxHeap.empty()) {
        minHeap.push(-maxHeap.top());
        maxHeap.pop();
    }
    
    // Convert back to positive values
    priority_queue<int, vector<int>, greater<int>> finalMinHeap;
    while (!minHeap.empty()) {
        finalMinHeap.push(-minHeap.top());
        minHeap.pop();
    }
    
    return finalMinHeap;
}

int main() {
    // Example max heap
    priority_queue<int> maxHeap;
    maxHeap.push(10);
    maxHeap.push(20);
    maxHeap.push(15);
    maxHeap.push(30);
    maxHeap.push(40);

    // Convert to min heap
    priority_queue<int, vector<int>, greater<int>> minHeap = convertMaxToMinHeap(maxHeap);

    // Print min heap
    cout << "Min Heap: ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;

    return 0;
}
