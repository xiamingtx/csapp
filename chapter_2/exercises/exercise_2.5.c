#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
	size_t i;
	for (i = 0; i < len; i ++ ) {
		printf(" %.2x", start[i]);
	}
	printf("\n");
}

void show_int(int x) {
	printf("show_int: ");
	show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
	printf("show_float: ");
	show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
	printf("show_pointer: ");
	show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val) {
	int ival = val;
	float fval = (float) ival;
	int *pval = &ival;
	show_int(ival);
	show_float(fval);
	show_pointer(pval);
}

int main() {
	int x = 12345;
	/*
	 * hex(12345) = 0x00003039
	 *
	 * show_int:  39 30 00 00        
 	 * show_float:  00 e4 40 46
	 * show_pointer:  38 b6 08 c3 fc 7f 00 00
	 *
	 * Linux32、Windows、Linux64: little endian 
	 * Sun: big endian
	 *
	 * Linux64 uses 8-bytes addresses
	 * Linux32、Windows、Sun use 4-bytes addresses
	 */
	test_show_bytes(x);
	
	printf("exercise: \n");

	int val = 0x87654321;
	byte_pointer valp = (byte_pointer) &val;
	show_bytes(valp, 1);
	show_bytes(valp, 2);
	show_bytes(valp, 3);
	
	return 0;
}
