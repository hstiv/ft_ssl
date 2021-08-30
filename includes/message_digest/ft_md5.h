#ifndef FT_MD5_H
# define FT_MD5_H

# include <stdint.h>

# define A0 0
# define B0 1
# define C0 2
# define D0 3

typedef struct s_md5
{
	uint32_t	a[4];
	uint32_t	aa[4];
	uint32_t	f;
	char		*bytes;
	uint32_t	*m;
	uint32_t	length;
	uint32_t	m_cycle;
}				t_md5;

char			*md5(char *s);
char			*md5_formatter(t_md5 *data);
uint32_t		f_func(uint32_t x, uint32_t y, uint32_t z);
uint32_t		g_func(uint32_t x, uint32_t y, uint32_t z);
uint32_t		h_func(uint32_t x, uint32_t y, uint32_t z);
uint32_t		i_func(uint32_t x, uint32_t y, uint32_t z);

#endif
