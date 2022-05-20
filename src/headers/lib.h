#ifndef LIB_H
#define LIB_H

#ifdef __PL_LINUX__

#include <setjmp.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

jmp_buf savebuf;

void (*fpe_signal_react)(int);
void (*segv_signal_react)(int);
void (*abrt_signal_react)(int);

enum Errors {
	ZeroDivisionError = 1,
	SegmentationFault,
	Aborted
};

char* file;
int line;
int jmp;

// Begin exception handling
#define BEGIN_EXCEPTION_HANDLING \
	jmp = setjmp(savebuf); \
	if (jmp == 0) { \
		file = __FILE__; \
		line = __LINE__; \
		fpe_signal_react = signal(SIGFPE, fpe_signal_handler); \
		segv_signal_react = signal(SIGSEGV, segv_signal_handler); \
		abrt_signal_react = signal(SIGABRT, abrt_signal_handler); \
	} \
	if (jmp == 0)

// End exception handling
#define END_EXCEPTION_HANDLING else {}

void fpe_signal_handler(int sig);
void segv_signal_handler(int sig);
void abrt_signal_handler(int sig);

#endif // __PL_LINUX__

#endif // LIB_H