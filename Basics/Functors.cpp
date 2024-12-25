#include <iostream>
using namespace std;

// Function
int add(int a, int b) {
    return a + b;
}

// Functor
class Add {
public:
    int operator()(int a, int b) {
        return a + b;
    }
};

int main() {
    // Using the function
    cout << "Function: " << add(3, 4) << endl;

    // Using the functor
    Add addFunctor;
    cout << "Functor: " << addFunctor(3, 4) << endl;

    return 0;
}




