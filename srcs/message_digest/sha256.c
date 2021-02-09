#include "ft_ssl.h"

const uint32_t s_k[BLOCK_64] = {
	0x428A2F98, 0x71374491, 0xB5C0FBCF, 0xE9B5DBA5, 0x3956C25B, 0x59F111F1, 0x923F82A4, 0xAB1C5ED5,
	0xD807AA98, 0x12835B01, 0x243185BE, 0x550C7DC3, 0x72BE5D74, 0x80DEB1FE, 0x9BDC06A7, 0xC19BF174,
	0xE49B69C1, 0xEFBE4786, 0x0FC19DC6, 0x240CA1CC, 0x2DE92C6F, 0x4A7484AA, 0x5CB0A9DC, 0x76F988DA,
	0x983E5152, 0xA831C66D, 0xB00327C8, 0xBF597FC7, 0xC6E00BF3, 0xD5A79147, 0x06CA6351, 0x14292967,
	0x27B70A85, 0x2E1B2138, 0x4D2C6DFC, 0x53380D13, 0x650A7354, 0x766A0ABB, 0x81C2C92E, 0x92722C85,
	0xA2BFE8A1, 0xA81A664B, 0xC24B8B70, 0xC76C51A3, 0xD192E819, 0xD6990624, 0xF40E3585, 0x106AA070,
	0x19A4C116, 0x1E376C08, 0x2748774C, 0x34B0BCB5, 0x391C0CB3, 0x4ED8AA4A, 0x5B9CCA4F, 0x682E6FF3,
	0x748F82EE, 0x78A5636F, 0x84C87814, 0x8CC70208, 0x90BEFFFA, 0xA4506CEB, 0xBEF9A3F7, 0xC67178F2
};

static void			init_sha256(t_sha256 *data)
{
	int				i;

	i = -1;
	data->h[0] = 0x6A09E667;
	data->h[1] = 0xBB67AE85;
	data->h[2] = 0x3C6EF372;
	data->h[3] = 0xA54FF53A;
	data->h[4] = 0x510E527F;
	data->h[5] = 0x9B05688C;
	data->h[6] = 0x1F83D9AB;
	data->h[7] = 0x5BE0CD19;
	while (++i < 8)
		data->ah[i] = data->h[i];
}	

static int			padding(char *s, t_sha256 *data)
{
	int				i;

	data->length = ft_strlen(s) * 8;
	data->m = ((data->length + 80) / 512) + 1;
	if (!(data->bytes = malloc(64 * data->m)))
		return (EXIT_FAILURE);
	ft_bzero(data->bytes, 64 * data->m);
	ft_strncpy((char*)data->bytes, s, ft_strlen(s));
	((char*)data->bytes)[ft_strlen(s)] = 128;
	i = -1;
	while (++i < (data->m * 16) - 1)
		data->bytes[i] = REV_UINT32(data->bytes[i]);
	data->bytes[(((data->m * 512) - 64) / 32) + 1] = data->length;
	return (EXIT_SUCCESS);
}

static void			fout(t_sha256 *data, int i)
{
	int				j;
	uint32_t		s0;
	uint32_t		s1;

	j = 16;
	ft_bzero(data->w, 512);
	ft_memcpy(data->w, &data->bytes[i * 16], 512);
	while (j < 64)
	{
		data->s0 = SHA256_sigma0(j - 15);
		data->s1 = SHA256_sigma1(j - 2);
		data->w[j] = data->w[j - 16] + data->s0 + data->w[j - 7] + data->s1;
		j++;
	}
	j = -1;
	while (++j < 8)
		data->ah[j] = data->h[j];
}

static void			swap_words(t_sha256 *d, int j)
{
	uint32_t		t1;
	uint32_t		t2;
	uint32_t		ch;
	uint32_t		ma;

	ma = SHA256_MA(d->ah[0], d->ah[1], d->ah[2]);
	ch = SHA256_CH(d->ah[4], d->ah[5], d->ah[6]);
	t2 = SHA256_SIGMA0(d->ah[0]) + ma;
	t1 = d->ah[7] + SHA256_SIGMA1(d->ah[4]) + ch + s_k[j] + d->w[j];
	d->ah[7] = d->ah[6];
	d->ah[6] = d->ah[5];
	d->ah[5] = d->ah[4];
	d->ah[4] = d->ah[3] + t1;
	d->ah[3] = d->ah[2];
	d->ah[2] = d->ah[2];
	d->ah[1] = d->ah[0];
	d->ah[0] = t1 + t2;
}

char				*sha256(char *s)
{
	t_sha256		data;
	int				i;
	int				j;
	int				l;

	i = -1;
	init_sha256(&data);
	if (padding(s, &data) == EXIT_FAILURE)
		return NULL;
	while (++i < data.m)
	{
		fout(&data, i);
		j = -1;
		while (++j < 64)
			swap_words(&data, j);
		l = -1;
		while (++l < 8);
			data.h[l] += data.ah[l];
		ft_bzero(data.w, 512);
	}
	ft_memdel((void **)&data.bytes);
	return(sha256_formatter(&data));
}