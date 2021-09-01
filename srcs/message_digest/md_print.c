#include "ft_ssl.h"

static const char	*g_opt[5] = {
	"MD5",
	"SHA256",
	"SHA224",
	"SHA512",
	NULL
};

static void	print_stdin(char *msg)
{
	if (g_ssl->params[_P])
		mprintf("%s\n%s\n", g_ssl->file_name, msg);
	else
		ft_putendl_fd(msg, 1);
}

static void	print_output(char *msg)
{
	if (g_ssl->params[STDIN_MODE])
		print_stdin(msg);
	else if (!g_ssl->params[_Q])
	{
		if (!g_ssl->params[_R])
		{
			ft_putstr((g_opt[g_ssl->func_index]));
			if (g_ssl->file_name)
				mprintf(" (%s) = ", g_ssl->file_name);
			else
				mprintf(" (\"%s\") = ", g_ssl->input_text);
			ft_putendl(msg);
		}
		else
		{
			ft_putstr(msg);
			if (g_ssl->file_name)
				mprintf(" %s\n", g_ssl->file_name);
			else
				mprintf(" \"%s\"\n", g_ssl->input_text);
		}
	}
	else
		ft_putendl_fd(msg, 1);
}

int	md_print(char *msg)
{
	int				i;

	i = -1;
	if (msg == NULL)
	{
		ft_putendl_fd("Error: malloc() doesn't work!", 2);
		return (ssl_cleaner(EXIT_FAILURE));
	}
	print_output(msg);
	ft_strdel(&msg);
	if (g_ssl->input_text)
		ft_strdel(&g_ssl->input_text);
	if (g_ssl->file_name)
		ft_strdel(&g_ssl->file_name);
	while (++i < 5)
		g_ssl->params[i] = 0;
	return (EXIT_SUCCESS);
}
