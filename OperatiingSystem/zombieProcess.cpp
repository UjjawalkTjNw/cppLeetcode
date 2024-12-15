#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main() {
    pid_t pid = fork();

    if (pid > 0) { // Parent process
        cout << "Parent process with PID: " << getpid() << " will sleep for 10 seconds." << endl;
        sleep(10); // Parent sleeps, during this time the child process becomes a zombie
        wait(NULL); // Parent reaps the child process
        cout << "Parent process reaped the child process." << endl;
    } else if (pid == 0) { // Child process
        cout << "Child process with PID: " << getpid() << " is terminating." << endl;
        exit(0); // Child process terminates
    } else {
        cerr << "Fork failed!" << endl;
        return 1;
    }

    return 0;
}
