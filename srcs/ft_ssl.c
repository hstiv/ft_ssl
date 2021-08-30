#include "ft_ssl.h"

static int	parse_params(int argc, char **argv, t_ssl *data)
{
	int			i;

	i = -1;
	while (g_mdoptions[++i] != NULL)
		if (ft_strcmp(g_mdoptions[i], argv[1]) == 0)
			return (parse_md_arg(argc, argv, data, i));
	return (error_option(argv[1], data));
}

static void	init_ssl(t_ssl *data, int *y)
{
	int			i;

	i = 0;
	*y = 1;
	g_mdoptions[0] = "md5";
	g_mdoptions[1] = "sha256";
	g_mdoptions[2] = "sha224";
	g_mdoptions[3] = "sha512";
	g_mdoptions[4] = NULL;
	g_mdfunc[0] = &md5;
	g_mdfunc[1] = &sha256;
	g_mdfunc[2] = &sha224;
	g_mdfunc[3] = &sha512;
	g_mdfunc[4] = NULL;
	while (i < 20)
		data->params[i++] = 0;
	data->input_text = NULL;
	data->file_name = NULL;
}

static char	**argv_format(char *s)
{
	char		**argv;
	char		**s1;
	int			len;
	int			i;

	s1 = ft_strsplit(s, ' ');
	len = ft_strlen2((const char **)s1);
	i = -1;
	argv = (char **)malloc(sizeof(char *) * (len + 2));
	argv[0] = ft_strdup("./ft_ssl");
	while (++i < len)
		argv[i + 1] = ft_strdup(s1[i]);
	argv[i + 1] = NULL;
	ft_arraydel((void **)s1);
	free(s1);
	return (argv);
}

int	main(int argc, char **argv)
{
	t_ssl		data;
	char		*line;
	int			y;
	char		**s;

	init_ssl(&data, &y);
	if (argc < 2)
	{
		data.params[BASH_MODE] = 1;
		while (y != 0)
		{
			ft_putstr("SSL> ");
			y = get_next_line(0, &line);
			if (y > 0)
			{
				s = argv_format(line);
				parse_params(ft_strlen2((const char **)s), s, &data);
				ft_arraydel((void **)s);
				free(s);
				ft_strdel(&line);
			}
		}
		return (EXIT_FAILURE);
	}
	return (parse_params(argc, argv, &data));
}
