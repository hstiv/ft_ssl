#include "ft_ssl.h"

uint32_t	ma_256(uint32_t a, uint32_t b, uint32_t c)
{
	return ((a & b) ^ (a & c) ^ (b & c));
}

uint32_t	ch_256(uint32_t e, uint32_t f, uint32_t g)
{
	return ((e & f) ^ (~e & g));
}

uint32_t	sigma0_256(uint32_t word)
{
	return (rotr_256(word, 2) ^ rotr_256(word, 13)
		^ rotr_256(word, 22));
}

uint32_t	sigma1_256(uint32_t word)
{
	return (rotr_256(word, 6) ^ rotr_256(word, 11)
		^ rotr_256(word, 25));
}
