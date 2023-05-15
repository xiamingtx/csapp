#include <stdio.h>
#include <stdint.h>

/* Determine whether arguments can be multiplied without overflow */
int tmult_ok(int x, int y) {
	/* 
	 * Compute product without overflow 
	 * If we write this line as int64_t pll = x * y, the product will be calculated using 32-bit values (which may overflow), 
	 * and then the sign will be extended to 64 bits.
	 */
	int64_t pll = (int64_t)x * y;
	/* see if casting to int preserves value */
	return pll == (int) pll;
}

int main() {
	int x = 0, y = 1;
	printf("x = %d, y = %d, x * y is overflow? %d\n", x, y, !tmult_ok(x, y));
	x = y = 1e6;
	printf("x = %d, y = %d, x * y is overflow? %d\n", x, y, !tmult_ok(x, y));

	return 0;
}
