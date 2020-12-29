#include "ft_ssl.h"

void			init_md5(t_md5 *data)
{
	// int		i;
	
	// i = 0;
	data->a0 = 0x67452301;
	data->b0 = 0xEFCDAB89;
	data->c0 = 0x98BADCFE;
	data->d0 = 0x10325476;
	// while (i < 64)
	// 	data->k[i] = uint32_t(pw(2, 32) * absl(++i);

	data->k ={
		0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee 0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
		0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be, 0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821, 
		0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa, 0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8, 
		0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed, 0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a, 
		0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c, 0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70, 
		0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05, 0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665, 
		0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039, 0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1, 
		0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1, 0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
		}
	data->s = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
			   5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20
			   4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23
			   6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};
}

uint32_t		md5(char *s)
{
	t_md5		md5;

	init_md5(&md5);
	md5.str = ft_strdup(s);
	md5.lenght = ft_strlen(s) + 1;
	while (md5.lenght % 64 != 56)
		md5.lenght++;
	if (!(md5.bytes = malloc(sizeof(md5.lenght + 64))))
		return (0);
	md5.bytes = ft_bzero(md5.bytes, md5.lenght + 64);
	
}