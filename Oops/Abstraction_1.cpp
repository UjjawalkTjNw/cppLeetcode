#include <iostream>

class Car {
public:
    void start() {
        // Start the engine, engage gears, etc. (implementation details)
        std::cout << "Car started\n";
    }

    void stop() {
        // Apply brakes, disengage gears, etc. (implementation details)
        std::cout << "Car stopped\n";
    }
};

int main() {
    Car myCar;
    myCar.start();
    myCar.stop();
    return 0;
}