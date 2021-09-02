#include "ft_ssl.h"

uint32_t	rotr_224(uint32_t x, uint32_t n)
{
	return ((x >> n) | (x << (32 - n)));
}

uint32_t	s0_224(uint32_t word)
{
	return (rotr_224(word, 7) ^ rotr_224(word, 18)
		^ (word >> 3));
}

uint32_t	s1_224(uint32_t word)
{
	return (rotr_224(word, 17) ^ rotr_224(word, 19)
		^ (word >> 10));
}

char	*sha256_formatter(t_sha256 *data)
{
	int				i;
	char			*s;
	char			*tmp;

	i = -1;
	s = ft_strnew(BLOCK_64);
	if (!(s))
		return (NULL);
	while (++i <= H)
	{
		tmp = str_filled(ft_itoa_base(data->h[i], 16), 8, '0', W_BEGIN);
		if (!(tmp))
			return (NULL);
		ft_memcpy(s + (i * 8), tmp, ft_strlen(tmp));
		ft_strdel(&tmp);
	}
	return (s);
}
