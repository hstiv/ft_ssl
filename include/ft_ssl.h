#ifndef FT_SSL_H
# define FT_SSL_H

# include <stdint.h>
# include "libft.h"

# define MDPARAMS "pqrs\0"
# define USAGE "usage: ft_ssl command [command opts] [command args]\n"
# define F(X, Y, Z) ((X & Y) | (~X & Z))
# define G(X, Y, Z) ((X & Z) | (~Z & Y))
# define H(X, Y, Z) (X ^ Y ^ Z)
# define I(X, Y, Z) ( Y ^ (~Z & X))
/* Define the SHA shift, rotate left and rotate right macro */
#define SHA256_SHR(bits,word)      ((word) >> (bits))
#define SHA256_ROTL(bits,word)                         \
  (((word) << (bits)) | ((word) >> (32-(bits))))
#define SHA256_ROTR(bits,word)                         \
  (((word) >> (bits)) | ((word) << (32-(bits))))

/* Define the SHA SIGMA and sigma macros */
#define SHA256_SIGMA0(word)   \
  (SHA256_ROTR( 2,word) ^ SHA256_ROTR(13,word) ^ SHA256_ROTR(22,word))
#define SHA256_SIGMA1(word)   \
  (SHA256_ROTR( 6,word) ^ SHA256_ROTR(11,word) ^ SHA256_ROTR(25,word))
#define SHA256_sigma0(word)   \
  (SHA256_ROTR( 7,word) ^ SHA256_ROTR(18,word) ^ SHA256_SHR( 3,word))
#define SHA256_sigma1(word)   \
  (SHA256_ROTR(17,word) ^ SHA256_ROTR(19,word) ^ SHA256_SHR(10,word))

typedef struct	s_ssl
{
    int         *params;
    char        *file_name;
    char        *input_text;
}				t_ssl;

typedef struct	s_md5
{
	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;
	uint32_t	aa;
	uint32_t	bb;
	uint32_t	cc;
	uint32_t	dd;
	int			f;
	int			g;
	char		*bytes;
	char		*m;
	size_t		length;
}				t_md5;

typedef struct	s_sha256
{
	uint32_t	h[8];
	uint32_t	ah[8];
	uint32_t	*bytes;
	int			m;
	size_t		length;
}				t_sha256;

char			*md5(char *s);
char			*sha256(char *s);
int				error_option(char *s);
int             parse_md_arg(int argc, char **argv, t_ssl *data, int func_index);
char			*(*mdfunc[2])(char *);
char            *mdoptions[2];

#endif