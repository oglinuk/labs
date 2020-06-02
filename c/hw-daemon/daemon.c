#include "daemon.h"

void init_daemon()
{
	pid_t pid, sid;

	// man syslog
	openlog("hw-daemon", LOG_PID | LOG_NDELAY, 0);

	// Fork the parent process
	pid = fork();

	if (pid < 0) {
		syslog(LOG_ERR, "Failed to fork the parent process ...");
		exit(1);
	}

	// If fork successful; exit parent process
	if (pid > 0) {
		syslog(LOG_INFO, "Successfully created process %d ...", pid);
		exit(0);
	}

	// Check file mode
	umask(0); // 0 means full access

	sid = setsid();
	if (sid < 0) {
		syslog(LOG_ERR, "Failed to create session ID ...");
		exit(1);
	}

	if (chdir("/") < 0) {
		syslog(LOG_ERR, "Failed to change to root dir ...");
		exit(1);
	}

	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	syslog(LOG_INFO, "Starting daemon process %d ...", sid);

	// cat /var/log/syslog (debian)
	syslog(LOG_INFO, "Hello world from the %d C hw-daemon example!", sid);
	exit(0);
}
