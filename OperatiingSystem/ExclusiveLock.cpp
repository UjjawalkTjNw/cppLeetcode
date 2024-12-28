/*There are two threads that are trying to access same function that increment counter upto 100000 times.
it is expected that sice two threads are trying to increment so we get print as 200000 

But since threads are not properly synchronized they starts getting random value. This is race-condition


*/

#include <atomic>
#include<iostream>
#include<thread>

using namespace std;

int counter(0);

void increment_counter()
{
   for(int i = 0 ; i < 100000 ; i++){
       counter++;
   }
}

int main(){
    thread t1(increment_counter);
    thread t2(increment_counter);

    t1.join();
    t2.join();

    cout << "Counter value: " << counter << endl;

    return 0;
}







//Op will be some random value. It will be sometime 200000  or some very random value

//fix with lock_guard:

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int counter(0);
std::mutex counterMutex; // Mutex for synchronizing access to `counter`

void increment_counter()
{
   for(int i = 0 ; i < 100000 ; i++) {
       std::lock_guard<std::mutex> lock(counterMutex); // Lock the mutex
       counter++;
   }
}

int main() {
    thread t1(increment_counter);
    thread t2(increment_counter);

    t1.join();
    t2.join();

    cout << "Counter value: " << counter << endl;

    return 0;
}
