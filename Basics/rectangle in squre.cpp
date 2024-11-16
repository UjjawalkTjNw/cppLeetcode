#include <iostream>

bool canFitInSquare(int length, int width, int side) {
    // Compare squares of the diagonal and the side length of the square
    return (length * length + width * width) <= (side * side);
}

int main() {
    int length, width, side;

    // Input the dimensions of the rectangle and the side of the square
    std::cout << "Enter the length and width of the rectangle: ";
    std::cin >> length >> width;
    std::cout << "Enter the side length of the square: ";
    std::cin >> side;

    // Check if the rectangle can fit in the square
    if (canFitInSquare(length, width, side)) {
        std::cout << "The rectangle can fit inside the square.\n";
    } else {
        std::cout << "The rectangle cannot fit inside the square.\n";
    }

    return 0;
}
