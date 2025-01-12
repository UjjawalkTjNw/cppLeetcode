#include <iostream>
#include <vector>
#include <algorithm>

// A custom comparator as a callback
bool descendingOrder(int a, int b) {
    return a > b;
}

int main() {
    std::vector<int> numbers = {3, 1, 4, 1, 5, 9};
    
    // Using a callback to define custom sorting order
    std::sort(numbers.begin(), numbers.end(), descendingOrder);

    std::cout << "Sorted numbers in descending order: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
