#include "ft_ssl.h"

static char	*read_file(char *path)
{
	int		fd;
	char	*s;

	fd = open(path, O_RDONLY);
	if (fd != -1)
		s = get_text(fd); 
	else
		no_file_err("base64");
	return(s);
	close(fd);
}

static void	in_out_options(int argc, char **argv, int *i, char *opt)
{
	if (!ft_strcmp(opt, "-i"))
	{
		if (g_ssl->params[I] == 1 || (*i)++ >= argc)
			fman("base64: Wrong options. -h", EXIT_FAILURE);
		g_ssl->params[I] = 1;
		g_ssl->input_file_text = read_file(argv[*i]);
		if (g_ssl->input_file_text == NULL)
			fman("base64: Cannot read input file.", EXIT_FAILURE);
	}
	else if (!ft_strcmp(opt, "-o"))
	{
		g_ssl->params[O] = 1;
		g_ssl->input_file_text = ft_strdup(argv[*i]);
		if (g_ssl->input_file_text == NULL)
			fman("base64: Memory allocation error. -h", EXIT_FAILURE);
	}
	else
		fman("base64: Wrong options. -h", EXIT_FAILURE);
}

static void	handle_option(int argc, char **argv, int *i)
{
	char		*opt;

	opt = ft_strtolower(argv[*i]);
	if (!ft_strcmp(opt, "-e"))
	{
		g_ssl->params[E] = 1;
		g_ssl->params[D] = 0;
	}
	else if (!ft_strcmp(opt, "-d"))
	{
		g_ssl->params[D] = 1;
		g_ssl->params[E] = 0;
	}
	else if (!ft_strcmp(opt, "-h") || !ft_strcmp(opt, "-help"))
		fman(B64_USAGE, EXIT_SUCCESS);
	else
		in_out_options(argc, argv, i, opt);
}

int	base64_parser(int argc, char **argv)
{
	int			i;

	i = 2;
	g_ssl->params[E] = 1;
	while (i < argc && argv && argv[i])
	{
		if (argv[i][0] == '-')
			handle_option(argc, argv, &i);
	}
	base64_print();
	return (EXIT_SUCCESS);
}