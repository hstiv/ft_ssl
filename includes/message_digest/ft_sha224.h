#ifndef FT_SHA224_H
# define FT_SHA224_H

# include <stdint.h>

typedef struct s_sha224
{
	uint32_t	h[8];
	uint32_t	ah[8];
	uint32_t	w[512];
	uint32_t	s0;
	uint32_t	s1;
	uint32_t	*bytes;
	int			m;
	size_t		length;
}				t_sha224;

char			*sha224(char *s);
char			*sha224_formatter(t_sha224 *data);
uint32_t		rotr_224(uint32_t x, uint32_t n);
uint32_t		sigma0_224(uint32_t word);
uint32_t		sigma1_224(uint32_t word);
uint32_t		s0_224(uint32_t word);
uint32_t		s1_224(uint32_t word);
uint32_t		ma_224(uint32_t a, uint32_t b, uint32_t c);
uint32_t		ch_224(uint32_t e, uint32_t f, uint32_t g);

#endif
