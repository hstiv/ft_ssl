#include "ft_ssl.h"

static char			*str_filled(char *s, size_t final_size, char filler_symb)
{
	size_t			len;
	char			*str;

	if (!s || !(str = ft_strnew(final_size)))
		return (NULL);
	len = ft_strlen(s);
	ft_memset(str + len, '0', final_size - len);
	ft_memcpy(str, s, len);
	ft_strdel(&s);
	return (str);
}


char				*md5_formatter(t_md5 *data)
{
	char			*s;
	int				i;
	char			*tmp;
	
	i = -1;
	if (!(s = ft_strnew(BLOCK_32)))
		return (NULL);
	while (++i < 4)
	{
		if (!(tmp = str_filled(ft_itoa_base_extra(data->a[i], 16), 8, '0')))
			return (NULL);
		ft_memcpy(s + ((i + 1) * 8), tmp, ft_strlen(tmp));
		ft_strdel(&tmp);
	}
	return (s);
}

char				*sha256_formatter(t_sha256 *data)
{
	int				i;
	char			*s;
	char			*tmp;
	
	i = -1;
	if (!(s = ft_strnew(BLOCK_64)))
		return (NULL);
	while (++i < 8)
	{
		if (!(tmp = str_filled(ft_itoa_base_extra(data->h[i], 16), 8, '0')))
			return (NULL);
		ft_memcpy(s + ((1 + i) * 8), tmp, ft_strlen(tmp));
		ft_strdel(&tmp);
	}
	return (s);
}