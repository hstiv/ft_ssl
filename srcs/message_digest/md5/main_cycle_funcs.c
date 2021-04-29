#include "ft_ssl.h"

uint32_t			f_func(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x & y) | (~x & z));
}

uint32_t			g_func(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x & z) | (y & ~z));
}

uint32_t			h_func(uint32_t x, uint32_t y, uint32_t z)
{
	return (x ^ y ^ z);
}

uint32_t			i_func(uint32_t x, uint32_t y, uint32_t z)
{
	return (y ^ (x | ~z));
}

char				*md5_formatter(t_md5 *data)
{
	char			*s;
	int				i;
	char			*tmp;

	i = -1;
	if (!(s = ft_strnew(BLOCK_32)))
		return (NULL);
	while (++i <= D)
	{
		if (!(tmp = str_filled(ft_itoa_base(
			rev_uint32(data->a[i]), 16), 8, '0', W_END)))
			return (NULL);
		ft_memcpy(s + (i * 8), tmp, ft_strlen(tmp));
		ft_strdel(&tmp);
	}
	return (s);
}
