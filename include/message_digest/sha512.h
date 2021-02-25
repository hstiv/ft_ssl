# define ROTR_512(X, N) ((X >> N) | (X << (64 - N)))

# define SIGMA0_512(word) \
(ROTR(word, 28) ^ ROTR(word, 34) ^ ROTR(word, 39))
# define SIGMA1_512(word) \
(ROTR_512(word, 14) ^ ROTR_512(word, 18) ^ ROTR_512(word, 41))
# define S0_512(word) \
(ROTR_512(word, 1) ^ ROTR_512(word, 8) ^ (word >> 7))
# define S1_512(word) \
(ROTR_512(word, 19) ^ ROTR_512(word, 61) ^ (word >> 6))
# define MA_512(a, b, c) \
((a & b) ^ (a & c) ^ (b & c))
# define CH_512(e, f, g) \
((e & f) ^ (~e & g))

typedef struct	s_sha512
{
	uint64_t	h[8];
	uint64_t	ah[8];
	uint64_t	w[512];
	uint64_t	s0;
	uint64_t	s1;
	uint64_t	*bytes;
	int			m;
	size_t		length;
}				t_sha512;

char			*sha512(char *s);
char			*sha512_formatter(t_sha512 *data);
