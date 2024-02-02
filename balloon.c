#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int random_(int max) {
	return (int)(max * random() / RAND_MAX);
}

int main(int argc, char** argv) {
	long long MiB = 1024 * 1024;
	long long GiB = 1024 * MiB;
	long long size = atoi(argv[1]) * MiB;
	printf("Inflating %.2f GiB = %.1f MiB = %lld B ...\n", (float)size / GiB, (float)size / MiB, size);

	void* ptr = malloc(size);
	for (long long i = 0; i < size; i++) {
		((char*)ptr)[i] = (char)random_(256);
	}
	
	printf("Inflated.\n");
	while (1) {
		sleep(120); // seconds
	}
	// unreachable
	return 0;
}
