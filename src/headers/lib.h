#ifndef LIB_H
#define LIB_H

#ifdef __PL_WINDOWS__

#include <setjmp.h> // библиотека с функциями setjmp и longjmp
#include <stdio.h> // библиотека с функцией printf

enum {
	FALSE, // = 0, исключение не вызвано
	TRUE // = 1, исключение вызвано
};

void print_error_message(); // функция для вывода сообщения об ошибке

typedef struct exception // структура, содержащая всю информацию об исключении
{
	jmp_buf savebuf; 
	char* message; // сообщение, переданное функцией throw(err_message)
	char* file_name; // название файла, выбросившего исключение
	int line; // номер строки, где было выброшено исключение
	int exception_raised; // идентификатор исключения (FALSE или TRUE)
} exception;

exception exc; 

#define BEGIN_EXCEPTION_HANDLING \
	if ((exc.exception_raised = setjmp(exc.savebuf)) == FALSE) // проверка на состояние исключения

#define END_EXCEPTION_HANDLING else {print_error_message();} // вывод сообщения об ошибке в случае, если исключение вызвано

#define throw(err_message) exc.file_name = __FILE__; \
					exc.line = __LINE__; \
					exc.message = err_message; \
					exc.exception_raised = TRUE; \
					longjmp(exc.savebuf, exc.exception_raised);

#endif // __PL_WINDOWS__

#ifdef __PL_LINUX__

#include <setjmp.h>
#include <signal.h>
#include <stdlib.h>

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