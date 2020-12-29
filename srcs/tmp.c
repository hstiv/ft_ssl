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




int			md_5(t_ssl *data, unsigned char *elem, int elem_lenght)
{
	init_md5(data);
	data->lenght = elem_lenght + 1;
	while (data->lenght % 64 != 56)
		data->lenght++;
	if (!(data->binary = (uint32_t *)malloc(sizeof(uint32_t * data->lenght))))
		return (0);
	
}