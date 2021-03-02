#include <stdint.h>

uint32_t			rotl32(uint32_t x, uint32_t n)
{
	return ((x << n) | (x >> (32 - n)));
}
