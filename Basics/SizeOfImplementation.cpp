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





//code 1: in c language
#include <stdio.h>
#define my_sizeof(type) (char *)(&type+1)-(char*)(&type)

int main() {
    double x;
    printf("%ld\n", my_sizeof(x));
    return 0;
}


//code 2: in cpp
#include <iostream>
#define my_sizeof(type) (char *)(&type+1)-(char*)(&type)

int main() {
    double x;
    std::cout << my_sizeof(x) << std::endl;
    return 0;
}