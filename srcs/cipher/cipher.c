#include "ft_ssl.h"

static char		*get_text(int fd)
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

static int		read_args(char *argv, int func_index)
{
	int			fd;
	
	printf("Here\n");
	g_ssl->file_name = ft_strdup(argv);
	if ((fd = open(argv, O_RDONLY)) != -1)
		g_ssl->input_text = get_text(fd);
	close(fd);
	if (!g_ssl->input_text)
	{
		no_file_err(g_cpcmds[func_index]);
		(g_ssl->file_name) ? ft_strdel(&g_ssl->file_name) : 0;
		return (EXIT_SUCCESS);
	}
	return (g_cpfunc[func_index]());
}

static void		set_options(char c)
{
	char		ca;

	ca = ft_tolower(c) - 'a';
	if (ca >= 0 && ca <= 25)
		g_ssl->params[(int)ca] = 1;
	g_ssl->params[STDIN_MODE] = 0;
}

static int		stdin_handler(int func_index)
{
	if (!g_ssl->params[BASH_MODE] && (g_ssl->input_text = get_text(0)) != NULL)
	{
		g_ssl->file_name = ft_strtrim(g_ssl->input_text);
		g_ssl->params[STDIN_MODE] = 1;
		if (g_cpfunc[func_index](g_ssl->input_text, g_ssl->params) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		g_ssl->params[STDIN_MODE] = 0;
		ft_strdel(&g_ssl->input_text);
		g_ssl->input_text = NULL;
	}
	return (EXIT_SUCCESS);
}

int             parse_cp_arg(int argc, char **argv,  int func_index)
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
			if (ft_strchr(CPPARAMS, argv[i][j]) == NULL)
				return (error_option(argv[i])); /* EXIT_FAILURE */
			set_options(argv[i][j]);
			j++;
		}
		i++;
	}
	stdin_handler(func_index);
	while (i < argc)
		if (read_args(argv[i++], func_index) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}