#include "ft_ssl.h"

int	no_file_err(char *func_name)
{
	ft_putstr("ft_ssl: ");
	ft_putstr(func_name);
	ft_putstr(": ");
	ft_putstr(g_ssl->file_name);
	ft_putendl_fd(": No such file or directory", 2);
	return (ssl_cleaner(EXIT_FAILURE));
}

int	ssl_cleaner(int exit_result)
{
	if (g_ssl->file_name != NULL)
		ft_strdel(&g_ssl->file_name);
	if (g_ssl->input_text != NULL)
		ft_strdel(&g_ssl->input_text);
	return (exit_result);
}

int	error_option(char *s)
{
	int			i;

	i = 0;
	mprintf("%s%s%s\n%s\n\n%s\n\n%s\n", ERR_1_1, s, ERR_1_2, USAGE, STD_CMDS, ERR_2);
	while (i < MD_CMD_COUNT)
		ft_putendl_fd(g_mdcmds[i++], 2);
	mprintf("\n%s\n", ERR_3);
	i = 0;
	while (i < CP_CMD_COUNT)
		ft_putendl_fd(g_cpcmds[i++], 2);
	return (ssl_cleaner(EXIT_FAILURE));
}
