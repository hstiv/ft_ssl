#include "ft_ssl.h"

uint32_t	ma_224(uint32_t a, uint32_t b, uint32_t c)
{
	return ((a & b) ^ (a & c) ^ (b & c));
}

uint32_t	ch_224(uint32_t e, uint32_t f, uint32_t g)
{
	return ((e & f) ^ (~e & g));
}

uint32_t	sigma0_224(uint32_t word)
{
	return (rotr_224(word, 2) ^ rotr_224(word, 13)
		^ rotr_224(word, 22));
}

uint32_t	sigma1_224(uint32_t word)
{
	return (rotr_224(word, 6) ^ rotr_224(word, 11)
		^ rotr_224(word, 25));
}
