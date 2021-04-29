#ifndef F_SHA256_H
# define F_SHA256_H

# include <stdint.h>

typedef struct	s_sha256
{
	uint32_t	h[8];
	uint32_t	ah[8];
	uint32_t	w[512];
	uint32_t	s0;
	uint32_t	s1;
	uint32_t	*bytes;
	int			m;
	size_t		length;
}				t_sha256;

char			*sha256(char *s);
char			*sha256_formatter(t_sha256 *data);
uint32_t		rotr_256(uint32_t x, uint32_t n);
uint32_t		sigma0_256(uint32_t word);
uint32_t		sigma1_256(uint32_t word);
uint32_t		s0_256(uint32_t word);
uint32_t		s1_256(uint32_t word);
uint32_t		ma_256(uint32_t a, uint32_t b, uint32_t c);
uint32_t		ch_256(uint32_t e, uint32_t f, uint32_t g);

#endif
