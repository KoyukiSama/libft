
#include "tester_macro.h"

void memprint(const void *mem, size_t n)
{
	const unsigned char *p;
	
	p = mem;
	for (size_t i = 0; i < n; i++) {
		printf("%02x ", p[i]);
	}
	printf("\n");
}
