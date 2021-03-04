#include "ft_ssl.h"

mdcmds = {
	"md5",
	"sha256",
	"sha224",
	"sha512",
	NULL
};

mdfunc = {
	&md5,
	&sha256,
	&sha224,
	&sha512,
	NULL
};

cpcmd = {
	"base64"
};

cpfunc = {
	&base64
};

static int		parse_params(int argc, char **argv, t_ssl *data)
{
	int			i;

	i = -1;
	while (++i < MD_CMD_COUNT + CP_CMD_COUNT + ST_CMD_COUNT)
	{
		if (i < MD_CMD_COUNT && ft_strcmp(mdcmds[i], argv[1]) == 0)
			return (parse_md_arg(argc, argv, data, i));
		else if (i < CP_CMD_COUNT && ft_strcmp(cpcmds[i], argv[1]) == 0)
			return (parse_cp_arg(argc, argv, data, i));
	}
	return (error_option(argv[1], data));
}

static void		init_ssl(t_ssl *data)
{
	int			i;

	i = -1;
	while (++i < PARAM_COUNT - 2)
		data->params[i] = 0;
	data->input_text = NULL;
	data->file_name = NULL;
}

static char		**argv_format(char *s)
{
	char		**argv;
	char		**s1;
	int			len;
	int			i;

	s1 = ft_strsplit(s, ' ');
	len = ft_strlen2((const char **)s1);
	i = -1;
	argv = (char **)malloc(sizeof(char*) * (len + 2));
	argv[0] = ft_strdup("./ft_ssl");
	while (++i < len)
		argv[i + 1] = ft_strdup(s1[i]);
	argv[i + 1] = NULL;
	ft_arraydel((void **)s1);
	free(s1);
	return (argv);
}

int				main(int argc, char **argv)
{
	t_ssl		data;
	char		*line;
	int			y;
	char		**s;

	init_ssl(&data);
	y = 1;
	if (argc < 2)
	{
		data.params[BASH_MODE] = 1;
		while (y != 0)
		{
			ft_putstr("SSL> ");
			line = NULL;
			if ((y = get_next_line(0, &line)) != 0)
			{
				s = argv_format(line);
				ft_strdel(&line);
				parse_params(ft_strlen2((const char **)s), s, &data);
				ft_arraydel((void **)s);
				free(s);
			}
		}
		return (EXIT_FAILURE);		
	}
	return (parse_params(argc, argv, &data));
}