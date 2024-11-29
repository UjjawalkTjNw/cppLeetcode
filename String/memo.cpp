#include <iostream>
#include <unordered_map>
#include <cstring> // For strlen

// Memoization map to store previously copied strings
std::unordered_map<const char*, char*> memo;

char* copyString(const char* source) {
    // Check if the source string has already been copied
    if (memo.find(source) != memo.end()) {
        return memo[source];
    }

    // Get the length of the source string
    size_t length = strlen(source);

    // Allocate memory for the destination string
    char* destination = new char[length + 1]; // +1 for the null terminator

    // Copy the string manually
    for (size_t i = 0; i <= length; ++i) {
        destination[i] = source[i];
    }

    // Store the copied string in the memo map
    memo[source] = destination;

    return destination;
}

int main() {
    const char* source = "Hello, World!";
    char* destination = copyString(source);

    std::cout << "Source: " << source << std::endl;
    std::cout << "Destination: " << destination << std::endl;

    // Clean up
    delete[] destination;

    return 0;
}
