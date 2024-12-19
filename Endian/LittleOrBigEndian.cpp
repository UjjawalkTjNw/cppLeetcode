//Determine endianess
#include <iostream>

int main() {
    union {
        short int s;
        char c[2];
    } u;

    u.s = 1;

    if (u.c[0] == 1) {
        std::cout << "Little-Endian System" << std::endl;
    } else {
        std::cout << "Big-Endian System" << std::endl;
    }

    return 0;
}

/* Dry run of above code:
Sure, let's walk through an example of how the code determines the endianness.

When we run the code, it defines a union with a short int and an array of two char elements. Then it sets the short int to 1 (u.s = 1).

In memory, the short int 1 is represented as:

00000001 00000000 in a little-endian system (LSB at the lowest address)

00000000 00000001 in a big-endian system (MSB at the lowest address)

In a Little-Endian System:
The memory layout will look like this:

u.c[0] = 1 (00000001)

u.c[1] = 0 (00000000)

When the code checks u.c[0], it finds 1, so it prints:

Little-Endian System
In a Big-Endian System:
The memory layout will look like this:

u.c[0] = 0 (00000000)

u.c[1] = 1 (00000001)

When the code checks u.c[0], it finds 0, so it prints:

Big-Endian System
This example shows how the code accurately determines the endianness of the system by examining the byte order of a short int.
*/