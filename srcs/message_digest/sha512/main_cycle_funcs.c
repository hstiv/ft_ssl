#include "ft_ssl.h"

uint64_t	sigma0_512(uint64_t word)
{
	return (rotr_512(word, 28) ^ rotr_512(word, 34)
		^ rotr_512(word, 39));
}

uint64_t	sigma1_512(uint64_t word)
{
	return (rotr_512(word, 14) ^ rotr_512(word, 18)
		^ rotr_512(word, 41));
}

uint64_t	ma_512(uint64_t a, uint64_t b, uint64_t c)
{
	return ((a & b) ^ (a & c) ^ (b & c));
}

uint64_t	ch_512(uint64_t e, uint64_t f, uint64_t g)
{
	return ((e & f) ^ (~e & g));
}
