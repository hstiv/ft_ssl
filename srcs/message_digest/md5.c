#include "ft_ssl.h"

const uint32_t k[BLOCK_64] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee, 0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be, 0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821, 
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa, 0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8, 
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed, 0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a, 
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c, 0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70, 
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05, 0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665, 
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039, 0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1, 
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1, 0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

const uint32_t s[BLOCK_64] = {
	7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
	5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
	6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
};

static void		init_md5(t_md5 *data)
{
	data->a[0] = 0x67452301;
	data->a[1] = 0xEFCDAB89;
	data->a[2] = 0x98BADCFE;
	data->a[3] = 0x10325476;
	data->aa[0] = 0;
	data->aa[1] = 0;
	data->aa[2] = 0;
	data->aa[3] = 0;
	data->m_cycle = 0;
}

static int		padding_bytes(t_md5 *md5, char *s)
{
	int			len;

	len = ft_strlen(s);
	md5->length = len + 1;
	while (md5->length % BLOCK_64 != 56)
		md5->length++;
	if (!(md5->bytes = ft_strnew(md5->length + BLOCK_64)))
		return (EXIT_FAILURE);
	ft_bzero(md5->bytes, md5->length + BLOCK_64);
	md5->bytes = ft_strcpy(md5->bytes, s);
	*(uint32_t*)(md5->bytes + len) = 128;
	*(uint32_t*)(md5->bytes + md5->length) = (uint32_t)(8 * len);
	return (EXIT_SUCCESS);
}

static void		md5_main_cycle(t_md5 *md5, int i)
{
	if (0 <= i && i <= 15)
	{
		md5->f = F(md5->aa[1], md5->aa[2], md5->aa[3]);
		md5->g = i;
	}
	else if (16 <= i && i <= 31)
	{
		md5->f = G(md5->aa[1], md5->aa[2], md5->aa[3]);
		md5->g = (5 * i + 1) % 16;
	}
	else if (32 <= i && i <= 47)
	{
		md5->f = H(md5->aa[1], md5->aa[2], md5->aa[3]);
		md5->g = (3 * i + 5) % 16;
	}
	else if (48 <= i && i <= 63)
	{
		md5->f = I(md5->aa[1], md5->aa[2], md5->aa[3]);
		md5->g = (7 * i) % 16;
	}
	md5->f = md5->f + md5->aa[0] + k[i] + md5->m[md5->g];
	md5->aa[0] = md5->aa[3];
	md5->aa[3] = md5->aa[2];
	md5->aa[2] = md5->aa[1];
	md5->aa[1] = md5->aa[1] + (ROTL(md5->f, s[i]));
}

char			*md5(char *s)
{
	t_md5		md5;
	int			i;

	init_md5(&md5);
	if (padding_bytes(&md5, s) == EXIT_FAILURE)
		return (NULL);
	printf("*** length = %ld ****\n", md5.length);
	while (md5.m_cycle < md5.length)
	{
		md5.m = (uint32_t *)(md5.bytes + md5.m_cycle);
		i = -1;
		while (++i < 4)
			md5.aa[i] = md5.a[i];
		i = -1;
		while (++i < BLOCK_64)
			md5_main_cycle(&md5, i);
		i = -1;
		while (++i < 4)
			md5.a[i] += md5.aa[i];
		md5.m_cycle += BLOCK_64;
	}
	printf("*** m_cycle = %d ****\n", md5.m_cycle);
	ft_strdel(&md5.bytes);
	return (md5_formatter(&md5));
}