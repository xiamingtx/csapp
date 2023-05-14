#include <stdio.h>

/* WARNING: This is a buggy code*/
float sum_elements(float a[], unsigned length) {
	int i;
	float result = 0;

	for (i = 0; i <= length - 1; i ++ ) { 
		result += a[i];
	}
	return result;
}

/**
 *
 * Because the parameter length is unsigned, calculating 0-1 will use an unsigned operation, which is equivalent to modular addition. The result is UMax. ≤ The comp * arison also uses unsigned number comparison, and because any number is less than or equal to UMax, this comparison is always true! Therefore, the code will 
 * attempt to access illegal elements of array a.
 * There are two ways to correct this code: one is to declare length as an int type, and the other is to change the test condition of the for loop to i < length
 */
int main() {
	// float a[] = {3.14, 2.67};
	float a[] = {};
	unsigned len = sizeof(a) / sizeof(float);

	printf("res = %f\n", sum_elements(a, len));
	return 0;
}

