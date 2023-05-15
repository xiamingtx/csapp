#include <stdio.h>

int div16(int x) {
	/* Compute bias to be either 0 (x >= 0) or 15 (x < 0) */
	int bias = (x >> 31) & 0xF;
	return (x + bias) >> 4;
}
	
int main() {
	int x = 31;
	printf("x = %d, x / 16 = %d, x // 16 = %f\n", x, div16(x), x / 16.0);
	
	x = 64;
	printf("x = %d, x / 16 = %d, x // 16 = %f\n", x, div16(x), x / 16.0);
	
	x = -12340;
	printf("x = %d, x / 16 = %d, x // 16 = %f\n", x, div16(x), x / 16.0);
	return 0;
}
