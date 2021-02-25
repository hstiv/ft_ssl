/* Define the SHA SIGMA and sigma macros */
# define SIGMA0(word) \
(ROTR(word, 2) ^ ROTR(word, 13) ^ ROTR(word, 22))
# define SIGMA1(word) \
(ROTR(word, 6) ^ ROTR(word, 11) ^ ROTR(word, 25))
# define S0(word) \
(ROTR(word, 7) ^ ROTR(word, 18) ^ (word >> 3))
# define S1(word) \
(ROTR(word, 17) ^ ROTR(word, 19) ^ (word >> 10))
# define MA(a, b, c) \
((a & b) ^ (a & c) ^ (b & c))
# define CH(e, f, g) \
((e & f) ^ (~e & g))

typedef struct	s_sha224
{
	uint32_t	h[8];
	uint32_t	ah[8];
	uint32_t	w[512];
	uint32_t	s0;
	uint32_t	s1;
	uint32_t	*bytes;
	int			m;
	size_t		length;
}				t_sha224;

char			*sha224(char *s);
char			*sha224_formatter(t_sha224 *data);
