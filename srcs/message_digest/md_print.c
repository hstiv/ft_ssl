#include "ft_ssl.h"

static char			*str_filled(char *s, size_t final_size, char filler_symb)
{
	int				len;
	int				i;
	char			*str;

	i = -1;
	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * final_size + 1);
	ft_bzero(str, final_size);
	if (len < final_size)
	{
		while (++i < final_size)
			str[i] = filler_symb;
	}
	ft_memcpy(str, s, len);
	ft_memdel((void **)&s);
	return (str);
}

char				*md5_formatter(t_md5 *data)
{
	char			*s;
	int				i;
	char			*tmp;
	
	i = -1;
	s = (char *)malloc(sizeof(char) * 33);
	ft_bzero(s, 32);
	ft_memdel((void **)&data->bytes);
	tmp = str_filled(ft_itoa_base_extra(data->a, 16), 8, '0');
	ft_memcpy(s, tmp, ft_strlen(tmp));
	ft_memdel((void **)&tmp);
	tmp = str_filled(ft_itoa_base_extra(data->b, 16), 8, '0');
	ft_memcpy(s + 8, tmp, ft_strlen(tmp));
	ft_memdel((void **)&tmp);
	tmp = str_filled(ft_itoa_base_extra(data->c, 16), 8, '0');
	ft_memcpy(s + 16, tmp, ft_strlen(tmp));
	ft_memdel((void **)&tmp);
	tmp = str_filled(ft_itoa_base_extra(data->d, 16), 8, '0');
	ft_memcpy(s + 24, tmp, ft_strlen(tmp));
	ft_memdel((void **)&tmp);
	return (s);
}

char				*sha256_formatter(t_sha256 *data)
{
	int				i;
	char			*s;
	char			*tmp;
	
	i = -1;
	s = (char *)malloc(sizeof(char) * 65);
	ft_bzero(s, 64);
	while (++i < 8)
	{
		tmp = str_filled(ft_itoa_base_extra(data->h[i], 16), 8, '0');
		ft_memcpy(s + ((1 + i) * 8), tmp, ft_strlen(tmp));
		ft_memdel((void **)&tmp);
	}
	return (s);
}