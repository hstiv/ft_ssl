#include "ft_ssl.h"

static int	parse_params(int argc, char **argv)
{
	int			i;

	i = -1;
	while (++i < MD_CMD_COUNT + CP_CMD_COUNT + ST_CMD_COUNT)
	{
		if (i < MD_CMD_COUNT && !ft_strcmp(g_mdcmds[i], argv[1]))
			return (parse_md_arg(argc, argv, i));
		else if (!ft_strcmp("base64", argv[1]))
			return (base64_parser(argc, argv));
		else if (!ft_strcmp("exit", argv[1]))
			clean_exit(EXIT_SUCCESS);
		else if (!ft_strcmp("help", argv[1]))
		{
			if (g_ssl->params[BASH_MODE])
				mprintf("%s\n\n%s\n\n%s\n", USAGE, STD_CMDS, ERR_2);
			else
				man(NULL, EXIT_SUCCESS);
		}
	}
	return (EXIT_FAILURE);
}

static void	init_ssl(t_ssl *data)
{
	int			i;

	i = -1;
	g_mdcmds[0] = "md5";
	g_mdcmds[1] = "sha256";
	g_mdcmds[2] = "sha224";
	g_mdcmds[3] = "sha512";
	g_cpcmds[0] = "base64";
	g_mdfunc[0] = &md5;
	g_mdfunc[1] = &sha256;
	g_mdfunc[2] = &sha224;
	g_mdfunc[3] = &sha512;
	g_cpfunc[0] = &base64;
	while (++i < PARAM_COUNT - 2)
		data->params[i] = 0;
	data->input_text = NULL;
	data->file_name = NULL;
	data->input_file_text = NULL;
	data->output_file_path = NULL;
	g_ssl = data;
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
	if (argv == NULL)
		fman("Memory allocation error", EXIT_FAILURE);
	argv[0] = ft_strdup("./ft_ssl");
	while (++i < len)
		argv[i + 1] = ft_strdup(s1[i]);
	argv[i + 1] = NULL;
	ft_arraydel((void **)s1);
	free(s1);
	return (argv);
}

void	bash_mode()
{
	char		*line;
	int			y;
	char		**s;

	g_ssl->params[BASH_MODE] = 1;
	y = 1;
	while (y != 0)
	{
		ft_putstr("SSL> ");
		y = get_next_line(0, &line);
		if (y > 0)
		{
			s = argv_format(line);
			if (parse_params(ft_strlen2((const char **)s), s) == EXIT_FAILURE)
				mprintf("Invalid command \'%s\'; type \"help\" for a list.", s);
			ft_arraydel((void **)s);
			free(s);
			ft_strdel(&line);
		}
	}
	clean_exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_ssl		data;

	init_ssl(&data);
	if (argc < 2)
		bash_mode();
	return (parse_params(argc, argv));
}
