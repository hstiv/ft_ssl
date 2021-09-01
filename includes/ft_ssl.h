#ifndef FT_SSL_H
# define FT_SSL_H

# include "libft.h"
# include "ft_md5.h"
# include "ft_sha256.h"
# include "ft_sha224.h"
# include "ft_sha512.h"
# include "ft_base64.h"

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
# define CP_CMD_COUNT 1
# define ST_CMD_COUNT 0

# define MDPARAMS "pqrs"
# define CPPARAMS "adeikopsv"
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
char			*g_cpcmds[CP_CMD_COUNT];
char			*(*(g_mdfunc)[MD_CMD_COUNT])(char *);
int				(*(g_cpfunc)[CP_CMD_COUNT])();

int				error_option(char *s);
int				parse_md_arg(int argc, char **argv,
					int func_index);
int             parse_cp_arg(int argc, char **argv,
					int func_index);
int				ssl_cleaner(int exit_result);
int				no_file_err(char *func_name);
int				md_print(char *msg);

#endif
