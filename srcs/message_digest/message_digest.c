#include "ft_ssl.h"

static void	read_args(char *argv,int func_index)
{
	int			fd;

	g_ssl->file_name = ft_strdup(argv);
	fd = open(argv, O_RDONLY);
	if (fd != -1)
		g_ssl->input_text = get_text(fd);
	else if (g_ssl->params[_S])
	{
		g_ssl->input_text = ft_strdup(argv);
		if (g_ssl->file_name)
			ft_strdel(&g_ssl->file_name);
		g_ssl->params[_S] = 0;
	}
	close(fd);
	if (!g_ssl->input_text)
	{
		no_file_err(g_mdcmds[func_index]);
		if (g_ssl->file_name)
			ft_strdel(&g_ssl->file_name);
		return ;
	}
	md_print(g_mdfunc[func_index](g_ssl->input_text));
}

static void	set_options(char c)
{
	if (c == 'p' || c == 'P')
		g_ssl->params[_P] = 1;
	else if (c == 'q' || c == 'Q')
		g_ssl->params[_Q] = 1;
	else if (c == 'r' || c == 'R')
		g_ssl->params[_R] = 1;
	else if (c == 's' || c == 'S')
		g_ssl->params[_S] = 1;
	else if (c == 'h' || c == 'H')
		fman(MD_USAGE, EXIT_SUCCESS);
	g_ssl->params[STDIN_MODE] = 0;
}

static void	stdin_handler(int func_index, int arg_count)
{
	g_ssl->input_text = get_text(0);
	if (!g_ssl->params[BASH_MODE] && g_ssl->input_text != NULL
		&& (g_ssl->params[_P] || !arg_count))
	{
		g_ssl->file_name = ft_strtrim(g_ssl->input_text);
		g_ssl->params[STDIN_MODE] = 1;
		md_print(g_mdfunc[func_index](g_ssl->input_text));
		g_ssl->params[_P] = 0;
		g_ssl->params[STDIN_MODE] = 0;
	}
	else if (arg_count == 0)
	{
		md_print(g_mdfunc[func_index](""));
		g_ssl->params[_P] = 0;
		g_ssl->params[STDIN_MODE] = 0;
	}
}

int	parse_md_arg(int argc, char **argv, int func_index)
{
	int			i;
	int			j;

	i = 2;
	g_ssl->func_index = func_index;
	while (i < argc && argv && argv[i] && argv[i][0] == '-')
	{
		j = 1;
		while (argv[i][j] != '\0')
		{
			if (ft_strchr(MDPARAMS, argv[i][j]) == NULL)
				fman(MD_USAGE, EXIT_FAILURE);
			set_options(argv[i][j]);
			j++;
		}
		i++;
	}
	stdin_handler(func_index, argc - i);
	while (i < argc)
		read_args(argv[i++], func_index);
	return (EXIT_SUCCESS);
}
