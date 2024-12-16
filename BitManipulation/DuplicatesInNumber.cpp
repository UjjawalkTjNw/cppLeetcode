#include <iostream>
using namespace std;

bool hasDuplicates(int num) {
    int bitArray = 0; // Bit array to store occurrence of digits

    while (num > 0) {
        int digit = num % 10; // Extract the last digit
        num /= 10; // Remove the last digit

        // Check if the digit is already in the bit array
        if (bitArray & (1 << digit)) {
            return true; // Duplicate found
        }

        // Mark the digit in the bit array
        bitArray |= (1 << digit);
    }

    return false; // No duplicates found
}

int main() {
    int num = 123456;

    if (hasDuplicates(num)) {
        cout << "The number " << num << " has duplicate digits." << endl;
    } else {
        cout << "The number " << num << " does not have duplicate digits." << endl;
    }

    return 0;
}
