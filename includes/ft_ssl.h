#ifndef FT_SSL_H
# define FT_SSL_H

# include "libft.h"
# include "ft_md5.h"
# include "ft_sha256.h"
# include "ft_sha224.h"
# include "ft_sha512.h"

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
# define J 9
# define K 10
# define L 11
# define M 12
# define N 13
# define O 14
# define P 15
# define Q 16
# define R 17
# define S 18
# define T 19
# define U 20
# define V 21
# define W 22
# define X 23
# define Y 24
# define Z 25

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
# define STDIN_MODE 26
# define BASH_MODE 27
# define PARAM_COUNT 30

# define MD_CMD_COUNT 4
# define ST_CMD_COUNT 0

# define MDPARAMS "pqrsh"
# define MD_USAGE "\t-p\techo STDIN to STDOUT and append the check sum to STDOUT.\n \
\t-q\tquiet mode.\n \
\t-r\treverse the format of the out put.\n \
\t-s\tprint the sum of the given string.\n"
# define B64_USAGE "\t-d\tdecode mode.\n\
\t-e\tencode mode (default).\n\
\t-i\tinput file\n\
\t-o\tout put file\n"
# define USAGE "usage: ft_ssl command [command opts] [command args]"
# define STD_CMDS "Standard commands:"
# define ERR_1_1 "ft_ssl: Error: \'"
# define ERR_1_2 "\' is an invalid command.\n"
# define ERR_2 "Message Digest commands:"
# define ERR_3 "Cipher commands:"

typedef struct s_ssl
{
	int			params[PARAM_COUNT];
	char		*file_name;
	char		*input_text;
	int			func_index;
}				t_ssl;

t_ssl			*g_ssl;

char			*g_mdcmds[MD_CMD_COUNT];
char			*(*(g_mdfunc)[MD_CMD_COUNT])(char *);

void			man(char *s, int exit_code);
char			*get_text(int fd);
int				parse_md_arg(int argc, char **argv,
					int func_index);
void			md_print(char *msg);
void			clean_exit(int exit_code);
void			fman(char *usage, int exit_code);
void			no_file_err(char *func_name);
char			*ft_strtolower(char *str);

#endif
