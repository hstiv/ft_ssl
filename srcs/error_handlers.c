#include "ft_ssl.h"

void	no_file_err(char *func_name)
{
	mprintf("ft_ssl: %s: %s: No such file or directory\n",
		func_name, g_ssl->file_name);
	clean_exit(EXIT_FAILURE);
}

void	fman(char *usage, int exit_code)
{
	mprintf("%s", usage);
	clean_exit(exit_code);
}

void	clean_exit(int exit_code)
{
	if (g_ssl->file_name != NULL)
		ft_strdel(&g_ssl->file_name);
	if (g_ssl->input_text != NULL)
		ft_strdel(&g_ssl->input_text);
	exit (exit_code);
}

void	man(char *s, int exit_code)
{
	int			i;

	i = 0;
	if (exit_code == EXIT_FAILURE)
		mprintf("%s%s%s\n%s\n\n%s\n\n%s\n", ERR_1_1,
			s, ERR_1_2, USAGE, STD_CMDS, ERR_2);
	else
		mprintf("%s\n\n%s\n\n%s\n", USAGE, STD_CMDS, ERR_2);
	while (i < MD_CMD_COUNT)
		ft_putendl_fd(g_mdcmds[i++], 2);
	mprintf("\n%s\n", ERR_3);
	clean_exit(exit_code);
}
