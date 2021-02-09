#include "libft.h"

char				*str_filled(char *s, size_t final_size, char filler_symb)
{
	size_t			len;
	char			*str;

	if (!s || !(str = ft_strnew(final_size)))
		return (NULL);
	len = ft_strlen(s);
	ft_memset(str, filler_symb, final_size);
	ft_memcpy(str, s, len);
	ft_strdel(&s);
	return (str);
}