#ifndef FT_SSL_H
# define FT_SSL_H

# include <stdint.h>
# include "libft.h"

# define MDPARAMS "pqrs\0"
# define USAGE "usage: ft_ssl command [command opts] [command args]\n"

typedef struct	s_ssl
{
    int         *params;
    char        *file_name;
    char        *input_text;
}				t_ssl;

typedef struct	s_md5
{
	uint32_t	a0;
	uint32_t	b0;
	uint32_t	c0;
	uint32_t	d0;
	uint32_t	k[64];
	uint32_t	s[64];
	char		*bytes;
	char		*str;
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
	char		*str;
	size_t		length;
}				t_sha256;

void            mdfunc[2] = {&md5, &sha256};
char            *mdoptions[2] = {"md5\0","sha256\0"};

int				error_option(char *s);
int				parse_params(int argc, char **argv, t_ssl *data);
int             parse_md_arg(int argc, char **argv, t_ssl *data);
uint32_t		md5(char *s);
uint32_t		sha256(char *s);

#endif