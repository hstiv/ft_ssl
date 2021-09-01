#include "ft_ssl.h"

static char	*get_text(int fd)
{
	char		*s;
	char		buff[3];
	char		*tmp;
	int			input_size;

	s = ft_strdup("");
	input_size = 0;
	while (read(fd, buff, 1) > 0)
	{
		tmp = s;
		buff[1] = '\0';
		s = ft_strjoin(s, buff);
		ft_strdel(&tmp);
		input_size++;
	}
	if (input_size == 0)
		ft_strdel(&s);
	return (s);
}

static int	read_args(char *argv,int func_index)
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
		return (EXIT_SUCCESS);
	}
	return (md_print(g_mdfunc[func_index](g_ssl->input_text)));
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
	g_ssl->params[STDIN_MODE] = 0;
}

static int	stdin_handler(int func_index, int arg_count)
{
	g_ssl->input_text = get_text(0);
	if (!g_ssl->params[BASH_MODE] && g_ssl->input_text != NULL
		&& (g_ssl->params[_P] || !arg_count))
	{
		g_ssl->file_name = ft_strtrim(g_ssl->input_text);
		g_ssl->params[STDIN_MODE] = 1;
		if ((md_print(g_mdfunc[func_index](g_ssl->input_text)))
			== EXIT_FAILURE)
			return (EXIT_FAILURE);
		g_ssl->params[_P] = 0;
		g_ssl->params[STDIN_MODE] = 0;
	}
	else if (arg_count == 0)
	{
		if ((md_print(g_mdfunc[func_index]("")))
			== EXIT_FAILURE)
			return (EXIT_FAILURE);
		g_ssl->params[_P] = 0;
		g_ssl->params[STDIN_MODE] = 0;
	}
	return (EXIT_SUCCESS);
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
				return (ssl_cleaner(EXIT_FAILURE));
			set_options(argv[i][j]);
			j++;
		}
		i++;
	}
	stdin_handler(func_index, argc - i);
	while (i < argc)
		if (read_args(argv[i++], func_index) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
