/*
eg: Number = 5 ; set first bit
soln: 5 can be written as 0101
mask = 1<< k ; where k = 1
Therefor, 1<<k => 0001 <<1 => 0010

0010 OR 0101 => 0010 | 0101 => 0111

*/


#include <iostream>
using namespace std;

int setKthBit(int n, int k) {
    // Create a mask with the k-th bit set
    int mask = 1 << k;
    // Use bitwise OR to set the k-th bit in n
    return n | mask;
}

int main() {
    int number = 5; // Example number
    int k = 1; // Bit position to set

    int result = setKthBit(number, k);
    cout << "The result after setting the " << k << "-th bit of " << number << " is: " << result << endl;

    return 0;
}
