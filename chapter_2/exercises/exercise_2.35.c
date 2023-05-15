#include <stdio.h>

/* Determine whether arguments can be multiplied without overflow */
int tmult_ok(int x, int y) {
	int p = x * y;
	/* Either x is zero, or dividing p by x gives y */
	return !x || p / x = y;
}

int main() {
	int x = 0, y = 1;
	printf("x = %d, y = %d, x * y is overflow? %d", x, y, !tmult_ok(x, y));
	x = y = 1e6;
	printf("x = %d, y = %d, x * y is overflow? %d", x, y, !tmult_ok(x, y));

	return 0;
}
