/*Code1: with recursive mutex:
Explanation
Recursive Locking:

The std::recursive_mutex allows the same thread to lock it multiple times. Each lock() call must be matched with a corresponding unlock().
In this example, incrementCounter locks the mutex, increments the counter, and recursively calls itself. The same thread is locking the mutex multiple times without deadlock.
std::lock_guard:

Simplifies the use of locks by automatically unlocking when the scope is exited.
Shared Resource:

sharedCounter is the shared resource protected by recursiveMutex.
Thread Safety:

Both threads safely increment sharedCounter using the recursive mutex.

Counter: 1 (times left: 5)
Counter: 2 (times left: 4)
Counter: 3 (times left: 3)
Counter: 4 (times left: 2)
Counter: 5 (times left: 1)
Counter: 6 (times left: 5)
Counter: 7 (times left: 4)
Counter: 8 (times left: 3)
Counter: 9 (times left: 2)
Counter: 10 (times left: 1)
Final Counter Value: 10


Step-by-Step Execution
Thread t1 Starts:

t1 acquires the std::recursive_mutex:
Lock count = 1.
On recursive calls, the lock count increases:
Lock count = 2, 3, 4, 5.
Thread t1 Completes:

As the recursive calls return, the lock count decreases:
Lock count = 4, 3, 2, 1.
When t1 exits the recursion entirely, the lock count reaches 0, and the mutex is fully released.
Thread t2 Starts:

t2 now acquires the std::recursive_mutex because it is no longer locked by t1.
The lock count for t2 starts at 1 and increases with each recursive call:
Lock count = 2, 3, 4, 5.
Thread t2 Completes:

As with t1, the lock count decreases as the recursive calls return:
Lock count = 4, 3, 2, 1.
When t2 finishes, the lock count reaches 0, and the mutex is released.
*/
/*
That is one thread does not keep the mutex locked indefenitely, once the task is finished it unlocks and lets other thread lock and access it
This way it avoids deadlock situation
*/


#include <iostream>
#include <thread>
#include <mutex>

std::recursive_mutex recursiveMutex; // Recursive mutex
int sharedCounter = 0;

// Function demonstrating recursive locking
void incrementCounter(int times) {
    if (times <= 0) {
        return;
    }

    std::lock_guard<std::recursive_mutex> lock(recursiveMutex); // Lock the recursive mutex
    sharedCounter++; // Increment the shared counter
    std::cout << "Counter: " << sharedCounter << " (times left: " << times << ")\n";

    incrementCounter(times - 1); // Recursive call
}

int main() {
    std::thread t1(incrementCounter, 5); // Thread 1 increments the counter 5 times
    std::thread t2(incrementCounter, 5); // Thread 2 increments the counter 5 times

    t1.join();
    t2.join();

    std::cout << "Final Counter Value: " << sharedCounter << std::endl;

    return 0;
}




/*
code2:
In this case, mutex is locked once, increment counter by one and it keeps the mutex locked indefenitely
i.e: it prints 1 as counter and hangs after that
i.e one thread will keep mutex locked indefenitely and mutex will not be available to other threads. This leads deadlock situation
*/

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mutex; // Regular mutex
int sharedCounter = 0;

void incrementCounter(int times) {
    if (times <= 0) {
        return;
    }

    std::lock_guard<std::mutex> lock(mutex); // Lock the regular mutex
    sharedCounter++; // Increment the shared counter
    std::cout << "Counter: " << sharedCounter << " (times left: " << times << ")\n";

    incrementCounter(times - 1); // Recursive call
}

int main() {
    std::thread t1(incrementCounter, 5); // Thread 1 increments the counter 5 times
    t1.join();

    std::cout << "Final Counter Value: " << sharedCounter << std::endl;

    return 0;
}


