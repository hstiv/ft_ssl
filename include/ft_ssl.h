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
	uint32_t	a0;
	uint32_t	b0;
	uint32_t	c0;
	uint32_t	d0;
	uint32_t	k[64];
	uint32_t	s[64];
	char		*bytes;
	char		*m;
	size_t		length;
}				t_sha256;

char			*md5(char *s);
char			*sha256(char *s);
char			*mdfunc[2] = {md5, sha256};
char            *mdoptions[2] = {"md5\0","sha256\0"};
int				error_option(char *s);
int             parse_md_arg(int argc, char **argv, t_ssl *data, char *f(char *));

#endif