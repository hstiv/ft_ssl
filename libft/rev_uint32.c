#include <stdint.h>

uint32_t		rev_uint32(uint32_t n)
{
	return ((n >> 24) | ((n & 0xff0000) >> 8) | 
			((n & 0xff00) << 8) | (n << 24));
}