#include <stdio.h>

/* Determine whethre arguments can be added without overflow*/
int tadd_ok(int x, int y) {
	int sum = x + y;
	// printf("res = %d\n", sum);
	int neg_over = x < 0 && y < 0 && sum >= 0;
	int pos_over = x >= 0 && y >= 0 && sum < 0;
	return !neg_over && !pos_over;
}

int main() {
	int x = 1, y = 2;
	printf("x = %d, y = %d, x + y overflow? %d\n", x, y, !tadd_ok(x, y));
	x = y = 2e9;
	printf("x = %d, y = %d, x + y overflow? %d\n", x, y, !tadd_ok(x, y));
	return 0;
}
