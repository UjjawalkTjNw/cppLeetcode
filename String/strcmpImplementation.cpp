#include <iostream>

// Custom implementation of strcmp
int customStrcmp(const char* str1, const char* str2) {
    if (str1 == nullptr || str2 == nullptr) {
        // Handle null pointers; you could define your behavior here
        return -1; // Assuming -1 for invalid inputs
    }

    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }

    // Return the difference between the characters where they differ
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}

int main() {
    const char* string1 = "Hello";
    const char* string2 = "Hello";
    const char* string3 = "World";

    // Compare strings using custom strcmp
    std::cout << "Comparing \"" << string1 << "\" and \"" << string2 << "\": "
              << customStrcmp(string1, string2) << std::endl;  // return 0 since same

    std::cout << "Comparing \"" << string1 << "\" and \"" << string3 << "\": "
              << customStrcmp(string1, string3) << std::endl;                  // gives negative value  becos string1 is smaller than string3 in length also, also if u think ascii in that also

    std::cout << "Comparing \"" << string3 << "\" and \"" << string1 << "\": "
              << customStrcmp(string3, string1) << std::endl;   // gives positive value becos string3 is bigger than string1 in length also.

    return 0;
}
