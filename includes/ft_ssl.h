#ifndef FT_SSL_H
# define FT_SSL_H

# include "libft.h"
# include "md5.h"
# include "sha256.h"
# include "sha224.h"
# include "sha512.h"

# define BLOCK_64 64
# define BLOCK_32 32
# define BLOCK_512 512
# define A 0
# define B 1
# define C 2
# define D 3
# define E 4
# define F 5
# define G 6
# define H 7
# define I 8
# define H0 0
# define H1 1
# define H2 2
# define H3 3
# define H4 4
# define H5 5
# define H6 6
# define H7 7
# define _P 0
# define _Q 1
# define _R 2
# define _S 3
# define STDIN_MODE 4
# define BASH_MODE 15


# define MDPARAMS "pqrs"
# define USAGE "usage: ft_ssl command [command opts] [command args]"
# define ERR_1_1 "ft_ssl: Error: \'"
# define ERR_1_2 "\' is an invalid command.\n"
# define ERR_2 "Message Digest commands:"

typedef struct	s_ssl
{
    int         params[20];
    char        *file_name;
    char        *input_text;
	int			func_index;
}				t_ssl;

int				error_option(char *s, t_ssl *data);
int             parse_md_arg(int argc, char **argv, t_ssl *data, int func_index);
int				ssl_cleaner(t_ssl *data, int exit_result);
int				no_file_err(t_ssl *data, char *func_name);
int				md_print(char *msg, t_ssl *data);
char			*(*mdfunc[5])(char *);
char            *mdoptions[5];

#endif