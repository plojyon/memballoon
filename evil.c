/**
 * Evil balloon-popping program.
 * Use for testing.
 * Allocate `increment` MB every `timeout` seconds.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int random_(int max) {
	return (int)(max * random() / RAND_MAX);
}

int main(int argc, char** argv) {
	int MB = 1000 * 1000;
	int increment = 100 * MB;
	int timeout = 1; // in s
	for (int i = 0; ; i++) {
		char* ptr = malloc(increment * sizeof(char));
		for (int j = 0; j < increment; j++) {
			ptr[j] = (char)random_(256);
		}
		printf("%d MB allocated ...\n", increment * (i+1) / MB);
		sleep(timeout);
	}
	// unreachable
	return 0;
}

