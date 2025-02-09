#include <iostream>
#include <cstring> // For comparison with standard strcpy

// Custom implementation of strcpy
char* customStrcpy(char* destination, const char* source) {
    if (destination == nullptr || source == nullptr) {
        return nullptr; // Handle null pointers
    }

    char* destStart = destination; // Save the start of the destination pointer

    // Copy each character from source to destination
    while ((*destination++ = *source++) != '\0') {
        // The loop body is empty because the assignment and increment are done in the condition
    }

    return destStart; // Return the start of the destination string
}

int main() {
    const char* source = "Hello, World!";
    char destination[50]; // Ensure the destination has enough space

    // Using the custom strcpy
    customStrcpy(destination, source);

    // Display the result
    std::cout << "Source: " << source << std::endl;
    std::cout << "Destination: " << destination << std::endl;

    return 0;
}
