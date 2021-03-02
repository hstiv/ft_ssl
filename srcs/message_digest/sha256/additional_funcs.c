#include "ft_ssl.h"

uint32_t		rotr_256(uint32_t x, uint32_t n)
{
	return ((x >> n) | (x << (32 - n)));
}

uint32_t		s0_256(uint32_t word)
{
	return (rotr_256(word, 7) ^ rotr_256(word, 18)
			^ (word >> 3));
}

uint32_t		s1_256(uint32_t word)
{
	return (rotr_256(word, 17) ^ rotr_256(word, 19)
			^ (word >> 10));
}

char				*sha224_formatter(t_sha224 *data)
{
	int				i;
	char			*s;
	char			*tmp;
	
	i = -1;
	if (!(s = ft_strnew(BLOCK_64)))
		return (NULL);
	while (++i < H)
	{
		if (!(tmp = str_filled(ft_itoa_base(data->h[i], 16), 8, '0', W_BEGIN)))
			return (NULL);
		ft_memcpy(s + (i * 8), tmp, ft_strlen(tmp));
		ft_strdel(&tmp);
	}
	return (s);
}