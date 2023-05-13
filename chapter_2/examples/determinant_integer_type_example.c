#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>  // support Macro PRId32 & PRIu64

// #define PRId32 "d"
// #define PRIu64 "lu"

int main() {
	int32_t x = 1;
	uint64_t y = 2;

	/* 
	 * in 64-bits system:
	 * #define PRId32 "d"
	 * #define PRIu64 "lu"
	 *
	 * then the printf call above becomes:
	 * printf("x = %d, y = %lu\n", x, y);
	 */
	printf("x = %" PRId32 ", y = %" PRIu64 "\n", x, y);

	return 0;
}
