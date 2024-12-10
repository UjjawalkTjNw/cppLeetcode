/*
Eg1: n = 13 ; check if 2nd bit is set or not
Soln: 13 can be represented as 1101
Dry run1:
mask = 1<<k  where k = 2
=> 0001 <<2 i.e left shift by 2 bit => gives 0100
now do and with "n"
1101 & 0100 gives 0100 so 2nd bit is set

>> if k = 3 then shift 1 bu 3 bits left
i.e: 1<<3 => 0001 << 3 => 1000


*/



#include <iostream>
using namespace std;

bool isKthBitSet(int n, int k) {
    // Create a mask with the k-th bit set
    int mask = 1 << k;
    // Perform bitwise AND with n and mask, and check if result is non-zero
    return (n & mask) != 0;
}

int main() {
    int number = 13; // Example number
    int k = 2; // Bit position to check

    if (isKthBitSet(number, k)) {
        cout << "The " << k << "-th bit of " << number << " is set." << endl;
    } else {
        cout << "The " << k << "-th bit of " << number << " is not set." << endl;
    }

    return 0;
}
