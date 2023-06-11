#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int random_(int max) {
	return (int)(max * random() / RAND_MAX);
}

int main(int argc, char** argv) {
	int MB = 1000 * 1000;
	int size = atoi(argv[1]) * MB;
	printf("Inflating %d MB ...\n", size / MB);

	void* ptr = malloc(size);
	for (int i = 0; i < size; i++) {
		((char*)ptr)[i] = (char)random_(256);
	}
	
	printf("Inflated %d MB.\n", size / MB);
	while (1) {
		sleep(120); // seconds
	}
	// unreachable
	return 0;
}
