#include "ft_ssl.h"

int				error_option(char *s)
{
	int			i;

	i = 0;
	write(1, "ft_ssl: Error: \'", ft_strlen("ft_ssl: Error: \'"));
	write(1, s, ft_strlen(s));
	write(1, "\' is an invalid command.\n\n", ft_strlen("\' is an invalid command.\n\n"));
	write(1, "Message Digest commands:\n", ft_strlen("Message Digest commands:\n"));
	while (mdoptions[i] != NULL)
	{
		write(1, mdoptions[i], ft_strlen(mdoptions[i]));
		write(1, "\n", 1);
	}
	return (0);
}

int				parse_params(int argc, char **argv, t_ssl *data)
{
	int			i;

	i = 0;
	while (mdoptions[i] != NULL)
	{
		if (ft_strcmp(mdoptions[i], argv[1]) == 0)
			return (parse_md_arg(argv, argc, data, mdfunc[i]);
		i++;
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_ssl		data;
	int			len;

	if (argc < 1)
	{
		write(1, USAGE, ft_strlen(USAGE));
		return (0);
	}
	if (parse_params(argc, argv, &data) == 0)
		error_option(argv[1]);
	return (0);
}