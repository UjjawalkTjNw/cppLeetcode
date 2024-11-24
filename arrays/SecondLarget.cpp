#include <iostream>

int main() {
    int arr[] = {3, 1, 7, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int first_largest = arr[0];
    int second_largest = INT_MIN; // Initialize to minimum integer value

    for (int i = 1; i < n; ++i) {
        if (arr[i] > first_largest) {
            second_largest = first_largest;
            first_largest = arr[i];
        } else if (arr[i] > second_largest && arr[i] != first_largest) {
            second_largest  = arr[i];
        }
    }

    std::cout << "Second-last highest element: " << second_largest << std::endl;

    return 0;
}