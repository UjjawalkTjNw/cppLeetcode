#include <iostream>

#define MY_SIZEOF(type) (char *)(&type+1) - (char *)(&type)

int main() {
    int x;
    float y;
    char z;

    std::cout << "Size of int: " << MY_SIZEOF(x) << " bytes" << std::endl;
    std::cout << "Size of float: " << MY_SIZEOF(y) << " bytes" << std::endl;
    std::cout << "Size of char: " << MY_SIZEOF(z) << " bytes" << std::endl;

    return 0;
}

