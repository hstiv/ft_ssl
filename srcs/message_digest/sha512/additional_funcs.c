#include "ft_ssl.h"

uint64_t	rotr_512(uint64_t x, uint64_t n)
{
	return ((x >> n) | (x << (64 - n)));
}

uint64_t	s0_512(uint64_t word)
{
	return (rotr_512(word, 1)
		^ rotr_512(word, 8) ^ (word >> 7));
}

uint64_t	s1_512(uint64_t word)
{
	return (rotr_512(word, 19)
		^ rotr_512(word, 61) ^ (word >> 6));
}

char	*sha512_formatter(t_sha512 *data)
{
	int				i;
	char			*s;
	char			*tmp;

	i = -1;
	s = ft_strnew(BLOCK_64 * 2);
	if (!(s))
		return (NULL);
	while (++i <= H)
	{
		tmp = str_filled(ft_itoa_base(
					data->h[i], 16), 8 * 2, '0', W_BEGIN);
		if (!(tmp))
			return (NULL);
		ft_memcpy(s + (i * 8 * 2), tmp, ft_strlen(tmp));
		ft_strdel(&tmp);
	}
	return (s);
}
