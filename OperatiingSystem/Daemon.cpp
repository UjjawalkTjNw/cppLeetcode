#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void createDaemon() {
    pid_t pid;

    // Step 1: Fork off the parent process
    pid = fork();

    if (pid < 0) {
        // Fork failed
        std::cerr << "Fork failed!" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        // Exit the parent process
        std::cout << "Daemon process created with PID: " << pid << std::endl;
        exit(EXIT_SUCCESS);
    }

    // Step 2: Create a new session and make the child process the session leader
    if (setsid() < 0) {
        std::cerr << "Failed to create a new session!" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Step 3: Fork again to ensure the daemon cannot acquire a terminal
    pid = fork();

    if (pid < 0) {
        std::cerr << "Fork failed!" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        // Exit the first child
        exit(EXIT_SUCCESS);
    }

    // Step 4: Change the file mode mask
    umask(0);

    // Step 5: Change the working directory to root to avoid locking a directory
    if (chdir("/") < 0) {
        std::cerr << "Failed to change working directory to root!" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Step 6: Close all open file descriptors
    for (int fd = sysconf(_SC_OPEN_MAX); fd >= 0; fd--) {
        close(fd);
    }

    // Step 7: Redirect standard files to /dev/null
    int devNull = open("/dev/null", O_RDWR);
    if (devNull >= 0) {
        dup2(devNull, STDIN_FILENO);  // Redirect standard input
        dup2(devNull, STDOUT_FILENO); // Redirect standard output
        dup2(devNull, STDERR_FILENO); // Redirect standard error
        close(devNull);
    }

    // The daemon code
    while (true) {
        // Your daemon task goes here
        sleep(5); // Simulate periodic work
    }
}

int main() {
    createDaemon();
    return 0;
}


/*
1. Forking the Parent Process
-----------------------------------------
pid = fork();
Why? Forking creates a new process (child) from the parent process. The parent process exits, and the child continues execution. This is the first step to ensure that the new process becomes independent of the terminal.
Behavior:
pid > 0: We're in the parent process. The parent exits using exit(EXIT_SUCCESS);, ensuring the child can run in the background.
pid == 0: We're in the child process. It continues execution.


2. Creating a New Session
---------------------------------------
if (setsid() < 0) {
    std::cerr << "Failed to create a new session!" << std::endl;
    exit(EXIT_FAILURE);
}
Why? The setsid() system call makes the process the leader of a new session, detaches it from any controlling terminal, and prevents it from reacquiring one.
Outcome: The process is no longer tied to the terminal where it was started.


3. Fork Again
---------------------------
pid = fork();
Why? This second fork() ensures that the process is no longer a session leader. Being a session leader allows processes to reacquire a terminal, which we want to prevent.
Behavior:
pid > 0: The first child exits immediately.
pid == 0: The grandchild process (actual daemon) continues.


4. File Mode Mask
-----------------------------
umask(0);
Why? The umask() function sets the file mode creation mask to 0. This ensures that the daemon has full access to the files it creates (no restrictive permissions inherited).
Outcome: Files created by the daemon won't have restricted permissions unless explicitly set.


5. Changing the Working Directory
-------------------------------------------------
if (chdir("/") < 0) {
    std::cerr << "Failed to change working directory to root!" << std::endl;
    exit(EXIT_FAILURE);
}
Why? Changing the working directory to / (root directory) ensures the daemon doesn't keep any directory open. This prevents the daemon from blocking the unmounting of the current directory.
Outcome: The daemon is no longer tied to any specific filesystem location.


6. Closing File Descriptors
---------------------------------------
cpp
Copy
Edit
for (int fd = sysconf(_SC_OPEN_MAX); fd >= 0; fd--) {
    close(fd);
}
Why? File descriptors for stdin, stdout, and stderr (and potentially others) are inherited from the parent process. These need to be closed to make the daemon independent of the terminal.
Outcome: The daemon no longer interacts with the terminal.

7. Redirecting Standard Files
--------------------------------------------

int devNull = open("/dev/null", O_RDWR);
if (devNull >= 0) {
    dup2(devNull, STDIN_FILENO);
    dup2(devNull, STDOUT_FILENO);
    dup2(devNull, STDERR_FILENO);
    close(devNull);
}
Why? Daemons do not need input or output from a terminal. Redirecting stdin, stdout, and stderr to /dev/null ensures that any attempt to read from or write to these streams results in no operation.
Outcome: The daemon runs silently without any unintended interaction with the terminal.

8. Main Daemon Loop
-------------------------------------------
while (true) {
    sleep(5); // Simulate periodic work
}
Why? After the setup steps, the daemon performs its tasks here. A while(true) loop ensures it runs indefinitely, as daemons are designed to do.
Outcome: Replace this part with the specific functionality the daemon is meant to perform.-
-----------------------------------------------

How It Works Overall
Parent Process Ends: The parent process exits, leaving the child process to run in the background.
Detach from Terminal: The child process becomes independent of the terminal by creating a new session (setsid()).
No Terminal Reacquisition: The second fork ensures the daemon cannot reacquire a terminal.
Independent Environment: The daemon resets its working directory, closes file descriptors, and redirects standard streams, making it independent.
Daemon Work: The daemon enters its main loop, where it performs its designated tasks.
Common Use Cases
System Services: Daemons are often used for running background tasks like web servers, logging, monitoring, etc.
Cron-like Processes: Tasks that need periodic execution.
Network Services: Listening for and processing incoming connections or messages.


*/






