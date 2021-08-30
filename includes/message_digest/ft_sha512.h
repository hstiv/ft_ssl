#ifndef FT_SHA512_H
# define FT_SHA512_H

# include <stdint.h>

typedef struct s_sha512
{
	uint64_t	h[8];
	uint64_t	ah[8];
	uint64_t	w[512];
	uint64_t	s0;
	uint64_t	s1;
	uint64_t	*bytes;
	int			m;
	size_t		length;
}				t_sha512;

char			*sha512(char *s);
char			*sha512_formatter(t_sha512 *data);
uint64_t		rotr_512(uint64_t x, uint64_t n);
uint64_t		sigma0_512(uint64_t word);
uint64_t		sigma1_512(uint64_t word);
uint64_t		s0_512(uint64_t word);
uint64_t		s1_512(uint64_t word);
uint64_t		ma_512(uint64_t a, uint64_t b, uint64_t c);
uint64_t		ch_512(uint64_t e, uint64_t f, uint64_t g);

#endif
