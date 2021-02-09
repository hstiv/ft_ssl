#include "libft.h"

char	*res(int i, int n, int *convert)
{
	char		*base;
	char		*res;

	base = "0123456789abcdef";
	res = ft_strnew(i);
	i--;
	if (n == 1)
		res[0] = '-';
	while (i >= 0)
	{
		res[n] = base[convert[i]];
		n++;
		i--;
	}
	res[n] = '\0';
	return (res);
}

char	*ft_itoa_base(int value, int base)
{
	long int	val;
	int			i;
	int			n;
	int			convert[64];

	val = value;
	n = 0;
	if (val < 0)
	{
		val *= -1;
		if (base == 10)
			n = 1;
	}
	i = 0;
	if (val == 0)
		return (ft_strdup("0"));
	while (val != 0)
	{
		convert[i++] = val % base;
		val = val / base;
	}
	return (res(i, n, convert));
}