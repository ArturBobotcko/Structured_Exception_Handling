#include <stdio.h>
#include "../headers/lib.h"

#ifdef __PL_WINDOWS__

void print_error_message()
{
	printf("%s\n", exc.message);
	printf("Exception was raised in %s file in line %d\n", exc.file_name, exc.line);
}

#endif // __PL_WINDOWS__

#ifdef __PL_LINUX__

void fpe_signal_handler(int sig) {
	printf("%s:%d: exception: Division by zero (error code %d)\n", file, line, ZeroDivisionError);
	if (signal(SIGFPE, fpe_signal_react) == SIG_ERR) {
		perror("Error restoring a default signal");
	}
	longjmp(savebuf, ZeroDivisionError);
}

void segv_signal_handler(int sig) {
	printf("%s:%d: exception: Segmentation fault (error code %d)\n", file, line, SegmentationFault);
	if (signal(SIGSEGV, segv_signal_react) == SIG_ERR) {
		perror("Error restoring a default signal");
	}
	longjmp(savebuf, SegmentationFault);
}

void abrt_signal_handler(int sig) {
	printf("%s:%d: exception: Aborted (error code %d)\n", file, line, Aborted);
	if (signal(SIGABRT, abrt_signal_react) == SIG_ERR) {
		perror("Error restoring a default signal");
	}
	longjmp(savebuf, Aborted);
}

#endif // __PL_LINUX__