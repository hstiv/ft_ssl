#ifndef FT_SSL_H
# define FT_SSL_H

# include <stdint.h>

# define PARAMS "pqrs\0"
# define USAGE "usage: ft_ssl command [command opts] [command args]\n"

typedef struct	s_ssl
{
	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;
	uint32_t	k[64];
	uint32_t	s[64];
    int         param_options[4]; /* -p[0], -q[], -r[], -s[]*/
    char        *file_name;
    char        *input_text;
	
}				t_ssl;

void            func[2] = {&md5, &sha256};
char            *options[2] = {"md5\0","sha256\0"};

#endif