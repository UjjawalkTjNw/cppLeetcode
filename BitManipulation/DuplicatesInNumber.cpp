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
/*Dry run
bit array:  00000000 00000000 00000000 00000000
lets say number = 126456
digit = 123456%10 =6
num = 123456/10 = 12345


bitArray & (1 << digit):

1<<6 == 00000000 00000000 00000000 00000001 << 6  = 00000000 00000000 00000000 01000000
and then do bitwise and with bit array: 00000000 00000000 00000000 00000000 so it results in 0 
that means it is not present in bit array so do bitArray |= (1 << digit);

00000000 00000000 00000000 00000000  | 00000000 00000000 00000000 01000000  == 00000000 00000000 00000000 01000000
so we stored 6  now

similarly u can think if 6 is again present then it will find that it is already in bit array and return true





*/