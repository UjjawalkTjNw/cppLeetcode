#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
    pid_t pid = fork();

    if (pid > 0) { // Parent process
        cout << "Parent process with PID: " << getpid() << " is finishing its execution." << endl;
    } else if (pid == 0) { // Child process
        sleep(10); // Child process sleeps for 10 seconds
        cout << "Child process with PID: " << getpid() << " is now orphaned and adopted by init." << endl;
    } else {
        cerr << "Fork failed!" << endl;
        return 1;
    }

    return 0;
}
