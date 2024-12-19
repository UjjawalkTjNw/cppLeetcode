
// Converting 16-bit Integer from Little-Endian to Big-Endian:
#include <iostream>

short int little_to_big_endian(short int num) {
    return ((num & 0xFF) << 8) | ((num >> 8) & 0xFF);
}

int main() {
    short int little_endian_num = 0x1234;
    short int big_endian_num = little_to_big_endian(little_endian_num);

    std::cout << "Little-Endian: " << std::hex << little_endian_num << std::endl;
    std::cout << "Big-Endian: " << std::hex << big_endian_num << std::endl;

    return 0;
}

/*Dry run of above:

num = 0x1234 (in binary: 00010010 00110100)



First Operation: num & 0xFF
0xFF is 11111111 in binary. This masks the lower 8 bits.
num & 0xFF extracts the lower byte (rightmost 8 bits):
00010010 00110100
&
00000000 11111111
------------------
00000000 00110100 (in hex: 0x34)


Shift Left Operation: (num & 0xFF) << 8
This shifts the result from the previous step (0x34) 8 bits to the left:
00000000 00110100 (in binary: 00110100)
<< 8
00110100 00000000 (in hex: 0x3400)



Second Operation: num >> 8
This shifts num 8 bits to the right, extracting the upper byte:
00010010 00110100
>> 8
00000000 00010010 (in hex: 0x12)


Bitwise AND Operation: ((num >> 8) & 0xFF)
This ensures that only the lower byte of the result from the previous step is considered:
00000000 00010010
&
00000000 11111111
------------------
00000000 00010010 (in hex: 0x12)




Bitwise OR Operation: ((num & 0xFF) << 8) | ((num >> 8) & 0xFF)
This combines the two results:
00110100 00000000 (0x3400)
|
00000000 00010010 (0x12)
------------------------
00110100 00010010 (in hex: 0x3412)



Output:
Little-Endian: 0x1234:
Little-Endian: 1234


Big-Endian: 0x3412:
Big-Endian: 3412



similarly we can do for below code

*/




//Converting 16-bit Integer from Big-Endian to Little-Endian:

#include <iostream>

short int big_to_little_endian(short int num) {
    return ((num >> 8) & 0xFF) | ((num & 0xFF) << 8);
}

int main() {
    short int big_endian_num = 0x1234;
    short int little_endian_num = big_to_little_endian(big_endian_num);

    std::cout << "Big-Endian: " << std::hex << big_endian_num << std::endl;
    std::cout << "Little-Endian: " << std::hex << little_endian_num << std::endl;

    return 0;
}