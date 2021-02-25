#include "ft_ssl.h"

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
		if (!(tmp = str_filled(ft_itoa_base(REV_UINT32(data->a[i]), 16), 8, '0', W_END)))
			return (NULL);
		ft_memcpy(s + (i * 8), tmp, ft_strlen(tmp));
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
	while (++i <= H)
	{
		if (!(tmp = str_filled(ft_itoa_base(data->h[i], 16), 8, '0', W_BEGIN)))
			return (NULL);
		ft_memcpy(s + (i * 8), tmp, ft_strlen(tmp));
		ft_strdel(&tmp);
	}
	return (s);
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

char				*sha512_formatter(t_sha512 *data)
{
	int				i;
	char			*s;
	char			*tmp;
	
	i = -1;
	if (!(s = ft_strnew(BLOCK_64 * 2)))
		return (NULL);
	while (++i <= H)
	{
		if (!(tmp = str_filled(ft_itoa_base(data->h[i], 16), 8 * 2, '0', W_BEGIN)))
			return (NULL);
		ft_memcpy(s + (i * 8 * 2), tmp, ft_strlen(tmp));
		ft_strdel(&tmp);
	}
	return (s);
}