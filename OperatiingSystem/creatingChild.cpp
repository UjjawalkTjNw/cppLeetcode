#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
    pid_t pid = fork();

    if (pid < 0) { // Error in fork()
        cerr << "Fork failed!" << endl;
        return 1;
    } else if (pid == 0) { // Child process
        cout << "This is the child process with PID: " << getpid() << endl;
        cout << "The child's parent PID: " << getppid() << endl;
    } else { // Parent process
        cout << "This is the parent process with PID: " << getpid() << endl;
        cout << "The parent's child PID: " << pid << endl;
    }

    return 0;
}
