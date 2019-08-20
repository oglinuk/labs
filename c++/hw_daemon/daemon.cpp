#include "daemon.h"

void initDaemon() {
    pid_t pid, sid;

    // https://linux.die.net/man/3/syslog
    openlog("hwd", LOG_PID | LOG_NDELAY, 0);

    // Fork the parent process
    pid = fork();

    if(pid < 0) {
        syslog(LOG_ERR, "Failed to fork the parent process ...");
        exit(1);
    }

    // If successful; exit parent process
    if(pid > 0) {
        syslog(LOG_INFO, "Successfully created process %d", pid);
        exit(0);
    }

    // Check file mode
    umask(0); // 0 means full access


    // Create session ID for the child process
    sid = setsid();
    if(sid < 0) {
        syslog(LOG_ERR, "Failed to create session ID ...");
        exit(1);
    }

    // Change to the root dir
    if(chdir("/") < 0) {
        syslog(LOG_ERR, "Failed to change to root dir ...");
        exit(1);
    }

    std::cout << "Starting daemon process " << sid << " ...\n";

    // Closing file descriptors
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    // Infinite loop
    while(1) {
        // cat /var/log/syslog | grep hwd (ubuntu)
        syslog(LOG_INFO, "Hello world from the %d C++ daemon!", sid);
        sleep(42);
        exit(0);
    }
}