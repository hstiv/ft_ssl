#include "ft_ssl.h"

static const uint64_t	g_k[80] = {
	0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f,
	0xe9b5dba58189dbbc, 0x3956c25bf348b538, 0x59f111f1b605d019,
	0x923f82a4af194f9b, 0xab1c5ed5da6d8118, 0xd807aa98a3030242,
	0x12835b0145706fbe, 0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,
	0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235,
	0xc19bf174cf692694, 0xe49b69c19ef14ad2, 0xefbe4786384f25e3,
	0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65, 0x2de92c6f592b0275,
	0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5,
	0x983e5152ee66dfab, 0xa831c66d2db43210, 0xb00327c898fb213f,
	0xbf597fc7beef0ee4, 0xc6e00bf33da88fc2, 0xd5a79147930aa725,
	0x06ca6351e003826f, 0x142929670a0e6e70, 0x27b70a8546d22ffc,
	0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed, 0x53380d139d95b3df,
	0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6,
	0x92722c851482353b, 0xa2bfe8a14cf10364, 0xa81a664bbc423001,
	0xc24b8b70d0f89791, 0xc76c51a30654be30, 0xd192e819d6ef5218,
	0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8,
	0x19a4c116b8d2d0c8, 0x1e376c085141ab53, 0x2748774cdf8eeb99,
	0x34b0bcb5e19b48a8, 0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb,
	0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3, 0x748f82ee5defb2fc,
	0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec,
	0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915,
	0xc67178f2e372532b, 0xca273eceea26619c, 0xd186b8c721c0c207,
	0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178, 0x06f067aa72176fba,
	0x0a637dc5a2c898a6, 0x113f9804bef90dae, 0x1b710b35131c471b,
	0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc,
	0x431d67c49c100d4c, 0x4cc5d4becb3e42b6, 0x597f299cfc657e2a,
	0x5fcb6fab3ad6faec, 0x6c44198c4a475817
};

static void	init_sha512(t_sha512 *data)
{
	data->h[H0] = 0x6a09e667f3bcc908;
	data->h[H1] = 0xbb67ae8584caa73b;
	data->h[H2] = 0x3c6ef372fe94f82b;
	data->h[H3] = 0xa54ff53a5f1d36f1;
	data->h[H4] = 0x510e527fade682d1;
	data->h[H5] = 0x9b05688c2b3e6c1f;
	data->h[H6] = 0x1f83d9abfb41bd6b;
	data->h[H7] = 0x5be0cd19137e2179;
}

static void	padding(char *s, t_sha512 *data)
{
	int				i;

	data->length = ft_strlen(s) * 8;
	data->m = ((data->length + 160) / 1024) + 1;
	data->bytes = (uint64_t *)ft_memalloc(data->m * BLOCK_64 * 2);
	if (!(data->bytes))
		clean_exit(EXIT_FAILURE);
	ft_memcpy((char *)data->bytes, s, ft_strlen(s));
	((char *)data->bytes)[ft_strlen(s)] = 128;
	i = -1;
	while (++i < (data->m * 32) - 1)
		data->bytes[i] = rev_uint64(data->bytes[i]);
	data->bytes[((data->m * 1024 - 128) / 64) + 1] = data->length;
}

static void	fout(t_sha512 *data, int i)
{
	int				j;
	uint64_t		s0;
	uint64_t		s1;

	j = 16;
	ft_bzero(data->w, BLOCK_512);
	ft_memcpy(data->w, data->bytes + (i * 16), BLOCK_512);
	while (j < 80)
	{
		s0 = s0_512(data->w[j - 15]);
		s1 = s1_512(data->w[j - 2]);
		data->w[j] = data->w[j - 16] + s0 + data->w[j - 7] + s1;
		j++;
	}
}

static void	swap_words(t_sha512 *d)
{
	uint64_t		t1;
	uint64_t		t2;
	uint64_t		ch;
	int				i;

	i = -1;
	while (++i <= H)
		d->ah[i] = d->h[i];
	i = -1;
	while (++i < 80)
	{
		ch = ch_512(d->ah[E], d->ah[F], d->ah[G]);
		t1 = d->ah[H] + sigma1_512(d->ah[E]) + ch + g_k[i] + d->w[i];
		t2 = sigma0_512(d->ah[A]) + ma_512(d->ah[A], d->ah[B], d->ah[C]);
		d->ah[H] = d->ah[G];
		d->ah[G] = d->ah[F];
		d->ah[F] = d->ah[E];
		d->ah[E] = d->ah[D] + t1;
		d->ah[D] = d->ah[C];
		d->ah[C] = d->ah[B];
		d->ah[B] = d->ah[A];
		d->ah[A] = t1 + t2;
	}
}

char	*sha512(char *s)
{
	t_sha512		data;
	int				i;
	int				l;

	i = -1;
	init_sha512(&data);
	padding(s, &data);
	while (++i < data.m)
	{
		fout(&data, i);
		swap_words(&data);
		l = -1;
		while (++l <= H)
			data.h[l] += data.ah[l];
	}
	ft_memdel((void **)&data.bytes);
	return (sha512_formatter(&data));
}
