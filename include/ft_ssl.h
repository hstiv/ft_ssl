#ifndef FT_SSL_H
# define FT_SSL_H

# include "libft.h"
# include "md5.h"
# include "sha256.h"

# define BLOCK_64 64
# define BLOCK_32 32
# define BLOCK_512 512

# define MDPARAMS "pqrs"
# define USAGE "usage: ft_ssl command [command opts] [command args]"
# define ERR_1_1 "ft_ssl: Error: \'"
# define ERR_1_2 "\' is an invalid command.\n"
# define ERR_2 "Message Digest commands:"

# define REV_UINT32(n) \
(((n >> 24) | ((n & 0xff0000) >> 8) | \
((n & 0xff00) << 8) | (n << 24)))

typedef struct	s_ssl
{
    int         *params;
    char        *file_name;
    char        *input_text;
	int			func_index;
}				t_ssl;

char			*md5(char *s);
char			*sha256(char *s);
int				error_option(char *s, t_ssl *data);
int             parse_md_arg(int argc, char **argv, t_ssl *data, int func_index);
int				ssl_cleaner(t_ssl *data, int exit_result);
int				no_file_err(t_ssl *data, char *func_name);
int				md_print(char *msg, t_ssl *data);
char			*(*mdfunc[2])(char *);
char            *mdoptions[3];

#endif