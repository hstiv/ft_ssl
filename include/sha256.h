/* Define the SHA shift, rotate left and rotate right macro */
# define SHA256_SHR(bits, word) ((word) >> (bits))
# define SHA256_ROTL(bits, word) \
(((word) << (bits)) | ((word) >> (32 - (bits))))
# define SHA256_ROTR(bits,word) \
(((word) >> (bits)) | ((word) << (32 - (bits))))
# define SHA256_AND(a, b) (a & b)

/* Define the SHA SIGMA and sigma macros */
# define SHA256_SIGMA0(word) \
(SHA256_ROTR(2, word) ^ SHA256_ROTR(13, word) ^ SHA256_ROTR(22, word))
# define SHA256_SIGMA1(word) \
(SHA256_ROTR(6, word) ^ SHA256_ROTR(11, word) ^ SHA256_ROTR(25, word))
# define SHA256_sigma0(word) \
(SHA256_ROTR(7, word) ^ SHA256_ROTR(18, word) ^ SHA256_SHR(3, word))
# define SHA256_sigma1(word) \
(SHA256_ROTR(17, word) ^ SHA256_ROTR(19, word) ^ SHA256_SHR(10, word))
# define SHA256_MA(a, b, c) \
(SHA256_AND(a, b) ^ SHA256_AND(a, c) ^ SHA256_AND(b, c))
# define SHA256_CH(e, f, g) \
(SHA256_AND(e, f) ^ SHA256_AND(!e, g))

typedef struct	s_sha256
{
	uint32_t	h[8];
	uint32_t	ah[8];
	uint32_t	w[512];
	uint32_t	s0;
	uint32_t	s1;
	uint32_t	*bytes;
	int			m;
	size_t		length;
}				t_sha256;

char			*sha256_formatter(t_sha256 *data);
