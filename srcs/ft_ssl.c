#include "ft_ssl.h"

static int		parse_params(int argc, char **argv, t_ssl *data)
{
	int			i;

	i = -1;
	while (mdoptions[++i] != NULL)
		if (ft_strcmp(mdoptions[i], argv[1]) == 0)
			return (parse_md_arg(argc, argv, data, i));
	return (error_option(argv[1], data));
}

static void		init_ssl(t_ssl *data)
{
	mdoptions[0] = "md5";
	mdoptions[1] = "sha256";
	mdoptions[2] = NULL;
	mdfunc[0] = &md5;
	mdfunc[1] = &sha256;
	data->params = NULL;
	data->input_text = NULL;
	data->file_name = NULL;
}

int				main(int argc, char **argv)
{
	t_ssl		data;
	int			len;

	init_ssl(&data);
	if (argc < 2)
	{
		ft_putendl_fd(USAGE, 2);
		return (EXIT_FAILURE);
	}
	return (parse_params(argc, argv, &data));
}