#include <iostream>
#include <cstring> // Include the C string library

int main() {
    char source[] = "Hello, World!";
    char destination[50]; // Make sure the destination array is large enough

    // Use strcpy to copy the content from source to destination
    strcpy(destination, source);

    // Output the copied string
    std::cout << "Source: " << source << std::endl;
    std::cout << "Destination: " << destination << std::endl;

    return 0;
}
