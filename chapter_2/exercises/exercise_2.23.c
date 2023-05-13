#include <stdio.h>

typedef unsigned char * byte_pointer;

/*
 * The function func1 extracts a value from the low 8 bits of the parameter and obtains an integer in [0, 255]
 */
int func1(unsigned word) {
	return (int) ((word << 24) >> 24);
}

/*
 * The function func2 also extracts a value from the low 8 bits of the parameter 
 * but it also needs to be sign extended, resulting in a number between -128 and 127
 */
int func2(unsigned word) {
	return ((int) word << 24) >> 24;
}

void show_bytes(byte_pointer start) {
	for (int i = 0; i < sizeof(int); i ++ ) {
		printf(" %.2x", start[i]);
	}
	puts("");
}
	
void test_func() {
	unsigned words[] = {0x00000076, 0x87654321, 0x000000c9, 0xEDCBA987};
	int len = sizeof(words) / sizeof(unsigned);
	for (int i = 0; i < len; i ++ ) {
		puts("{");
		unsigned word = words[i];
		int res1 = func1(word);
		int res2 = func2(word);
		show_bytes((byte_pointer) &word), show_bytes((byte_pointer) &res1), show_bytes((byte_pointer) &res2);
		puts("}\n");
	}
}

int main() {
	test_func();
	return 0;
}
