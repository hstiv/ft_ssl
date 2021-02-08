#include "ft_ssl.h"

#define ERR_1_1 "ft_ssl: Error: \'"
#define ERR_1_2 "\' is an invalid command.\n"
#define ERR_2 "Message Digest commands:"

int				error_option(char *s)
{
	int			i;

	i = 0;
	ft_putstr_fd(ERR_1_1, 2);
	ft_putstr_fd(s, 2);
	ft_putendl_fd(ERR_1_2, 2);
	ft_putendl_fd(ERR_2, 2);
	while (mdoptions[i] != NULL)
		ft_putendl_fd(mdoptions[i++], 2);
	return (EXIT_FAILURE);
}

static int		parse_params(int argc, char **argv, t_ssl *data)
{
	int			i;

	i = -1;
	while (mdoptions[++i] != NULL)
		if (!ft_strcmp(mdoptions[i], argv[1]))
			return (parse_md_arg(argc, argv, data, i));
	return (EXIT_FAILURE);
}

static void		init_globals(void)
{
	mdoptions[0] = "md5";
	mdoptions[1] = "sha256";
	mdoptions[2] = NULL;
	mdfunc[0] = &md5;
	mdfunc[1] = &sha256;
}

int				main(int argc, char **argv)
{
	t_ssl		data;
	int			len;

	init_globals();
	if (argc < 1)
	{
		ft_putendl_fd(USAGE, 2);
		return (EXIT_FAILURE);
	}
	if (parse_params(argc, argv, &data) == EXIT_FAILURE)
		return (error_option(argv[1]));
	return (EXIT_SUCCESS);
}