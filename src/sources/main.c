#include "../headers/lib.h"

int main(int argc, char* argv[]) {
	BEGIN_EXCEPTION_HANDLING {
		int a = 10/0;
	}
	END_EXCEPTION_HANDLING

	return 0;
}