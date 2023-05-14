#include <stdio.h>

/* Determine whether arguments can be added without overflow */
int uadd_ok(unsigned x, unsigned y)
{
	unsigned sum = x + y;
	// printf("sum = %u\n", sum);
	return sum >= x;
}

int main() {
	unsigned x = 1, y = 2;
	printf("x = %u, y = %u, x + y overflow? %d\n", x, y, !uadd_ok(x, y));
	x = y = 1 << 31;
	printf("x = %u, y = %u, x + y overflow? %d\n", x, y, !uadd_ok(x, y));
	return 0;
}
