#include "../headers/lib.h"

int main(int argc, char* argv[]) {
	BEGIN_EXCEPTION_HANDLING {
		int a = 10/0;
	}
	END_EXCEPTION_HANDLING

	BEGIN_EXCEPTION_HANDLING {
		int* a = NULL;
		int b = *a;
	}
	END_EXCEPTION_HANDLING

	BEGIN_EXCEPTION_HANDLING {
		int* a = malloc(sizeof(int));
		free(a);
		free(a);
	}
	END_EXCEPTION_HANDLING

	return 0;
}