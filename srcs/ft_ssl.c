#include "ft_ssl.h"

int				get_text(int argc, char argv, t_ssl *data)
{
	
}

static t_ssl	parse_arguments(int argc, char **argv, t_ssl *data)
{
	int			i;

	i = 2;
	while (i < argc && argv[i][0] == '-' && argv[i][2] == '\0')
	{
		if (ft_strchr(PARAMS, argv[i][1]) == NULL)
			return (NULL);
		if (argv[i][1] == 'p')
			data->param_options[0] == 1;
		else if (argv[i][1] == 'q')
			data->param_options[1] == 1;
		else if (argv[i][1] == 'r')
			data->param_options[2] == 1;
		else if (argv[i][1] == 's')
			data->param_options[3] == 1;
	}
	if (get_text(i, argv, data) == 0)
		return (NULL); 
	return (data);
}

int				main(int argc, char **argv)
{
	t_ssl		data;
	int			len;

	if (argc < 1)
		return (0);
	len = ft_strlen2(options);
	while (--len)
		if (ft_strcmp(options[len], argv[1]) == 0)
			return (func[len](parse_arguments(argc, argv, data)));
	write(1, USAGE, ft_strlen(USAGE));
	return (0);
}