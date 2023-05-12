#include <stdio.h>

void inplace_swap(int *x, int *y) {
	*y = *x ^ *y; 
	*x = *x ^ *y;
	*y = *x ^ *y;
}

void reverse_array(int a[], int cnt) {
	int first, last;

	/* 
	 * error example: for (first = 0, last = cnt - 1; first <= last; first ++ , last -- )
	 *
	 * if the array length is odd, the middle element will be assigned a value of 0 due to a ^ a = 0
	 * 
	 * e.g. if a = {1, 2, 3, 4, 5}  =>  reversed_a = {5, 4, 0, 2, 1} 
   	 */
	for (first = 0, last = cnt - 1; first < last; first ++ , last -- ) {
		inplace_swap(&a[first], &a[last]);
	}
}

void print_array(int a[], int len) {
	for (int i = 0; i < len; i ++ ) { 
		printf("%d ", a[i]);
	}
	puts("");
}

int main() {
	int a[] = {1, 2, 3, 4};
	int b[] = {1, 2, 3, 4, 5};
	int len_a = sizeof(a) / sizeof(int);
	int len_b = sizeof(b) / sizeof(int);
	reverse_array(a, len_a);
	print_array(a, len_a);
	reverse_array(b, len_b);
	print_array(b, len_b);

	return 0;
}
