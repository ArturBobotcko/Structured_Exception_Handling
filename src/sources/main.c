#include "../headers/lib.h"

int main(int argc, char* argv[]) {
	#ifdef __PL_WINDOWS__
	BEGIN_EXCEPTION_HANDLING {
		int b = 0;
		if (b == 0) {
			throw("Zero division error");
		}
		int a = 10 / b;
		printf("%d\n", a);
	}
	END_EXCEPTION_HANDLING

	BEGIN_EXCEPTION_HANDLING {
		int* a = NULL;
		if (a == NULL) {
			throw("Null pointer");
		}
		int b = *a;
	}
	END_EXCEPTION_HANDLING

	BEGIN_EXCEPTION_HANDLING {
		int* a = malloc(sizeof(int));
		free(a);
		throw("Memory error");
		free(a);
	}
	END_EXCEPTION_HANDLING
	#endif

	#ifdef __PL_LINUX__
		BEGIN_EXCEPTION_HANDLING{
			int a = 10 / 0;
	}
		END_EXCEPTION_HANDLING

		BEGIN_EXCEPTION_HANDLING{
			int* a = NULL;
			int b = *a;
	}
		END_EXCEPTION_HANDLING

		BEGIN_EXCEPTION_HANDLING{
			int* a = malloc(sizeof(int));
			free(a);
			free(a);
	}
		END_EXCEPTION_HANDLING
	#endif
	return 0;
}