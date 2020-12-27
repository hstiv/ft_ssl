#include <stdint.h>

double		fpow(double x, double y)
{
	double	res;
	
	res = x;
	while (--y > 0)
		res = res * x;
	return (res);
}

int			fabs(int j)
{
	return (j < 0 ? -j : j);
}

void		init_md5(t_ssl *data)
{
	int		i;
	
	i = 0;
	data->a = 0x67452301;
	data->b = 0xEFCDAB89;
	data->c = 0x98BADCFE;
	data->d = 0x10325476;
	while (i < 64)
		data->k[i] = uint32_t(pw(2, 32) * absl(++i);
	data->s = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
			   5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20
			   4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23
			   6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};
}


int			md_5(t_ssl *data, unsigned char *elem, int elem_lenght)
{
	init_md5(data);
	data->lenght = elem_lenght + 1;
	while (data->lenght % 64 != 56)
		data->lenght++;
	if (!(data->binary = (uint32_t *)malloc(sizeof(uint32_t * data->lenght))))
		return (0);
	
}