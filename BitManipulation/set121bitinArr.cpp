#include <iostream>
#include <bitset>

const int ARRAY_SIZE = 10;
const int BITS_PER_LONG = sizeof(long) * 8;

int main() {
    long arr[ARRAY_SIZE] = {0}; // Initialize array to 0
    int bits_to_set = 121;

    for (int i = 0; i < ARRAY_SIZE && bits_to_set > 0; ++i) {
        if (bits_to_set >= BITS_PER_LONG) {
            arr[i] = ~0; // Set all bits in this element to 1
            bits_to_set -= BITS_PER_LONG;
        } else {
            arr[i] = (1L << bits_to_set) - 1; // Set the remaining bits to 1
            bits_to_set = 0;
        }
    }
    //Dry run: 121 >=32 : set all 32 bit of element 0 of array as 1
    //121-32=89 >=32 :set all 32 bit of element 1 of array as 1
    //89-32 = 57 >=32 set all 32 bit of element 2 of array as 1
    //57-32 =25 <32 so go to else condn

    //Working of (1L << bits_to_set) - 1
    // it sets left bit mentioned by bits_to_set [in this case 25th left bit ] as 1
    // 00000001000000000000000000000000
    //substract -1 will set all 25 bits right of this 1 as 1
    // therefore it has now set remaining 25 bits (32+32+32+25)= 121 bits


    // Print the array as bitsets to verify
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::cout << "Element " << i << ": " << std::bitset<BITS_PER_LONG>(arr[i]) << std::endl;
    }

    return 0;
}
