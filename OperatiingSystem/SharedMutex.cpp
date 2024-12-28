/*Code1:
The threads are in synchronization, so first thread will do read, then second thread will do write , then third thread will do read
so op will come in order:
T1: 123 read
T2: 4 write
T3: 1234 read
*/
#include <iostream>
#include <thread>
#include <shared_mutex>
#include <vector>

std::shared_mutex sharedMutex;
std::vector<int> sharedData = {1, 2, 3};

void readData() {
    std::shared_lock<std::shared_mutex> readLock(sharedMutex);
    std::cout << "Reading sharedData: ";
    for (const auto& val : sharedData) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

void writeData(int value) {
    std::unique_lock<std::shared_mutex> writeLock(sharedMutex);
    sharedData.push_back(value);
    std::cout << "Writing to sharedData: " << value << std::endl;
}

int main() {
    std::thread reader1(readData);
    reader1.join();

    std::thread writer(writeData, 4);
    writer.join();

    std::thread reader2(readData);
    reader2.join();

    return 0;
}






/*code2:
shared_mutex is not present
When there is no sync bw threads i.e no coordination then lets say one thread is reading then at same time another thread might start reading
or write is performed first
Means order of operation will not be consistent
*/

#include <iostream>
#include <thread>
#include <vector>

std::vector<int> sharedData = {1, 2, 3};

void readData() {
    std::cout << "Reading sharedData: ";
    for (const auto& val : sharedData) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

void writeData(int value) {
    sharedData.push_back(value);
    std::cout << "Writing to sharedData: " << value << std::endl;
}

int main() {
    std::thread reader1(readData);
    reader1.join();

    std::thread writer(writeData, 4);
    writer.join();

    std::thread reader2(readData);
    reader2.join();

    return 0;
}









































