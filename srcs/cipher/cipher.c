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

static int		read_args(char *argv, t_ssl *data, int func_index)
{
	int			fd;
	
	data->file_name = ft_strdup(argv);
	if ((fd = open(argv, O_RDONLY)) != -1)
		data->input_text = get_text(fd);
	close(fd);
	if (!data->input_text)
	{
		no_file_err(data, cpcmds[func_index]);
		(data->file_name) ? ft_strdel(&data->file_name) : 0;
		return (EXIT_SUCCESS);
	}
	return (cpfunc[func_index](data->input_text, data->params));
}

static void		set_options(t_ssl *data, char c)
{
	char		ca;

	ca = ft_tolower(c) - 'a';
	if (ca >= 0 && ca <= 25)
		data->params[ca] = 1;
	data->params[STDIN_MODE] = 0;
}

int				stdin_handler(t_ssl *data, int func_index, int arg_count)
{
	if (!data->params[BASH_MODE] && (data->input_text = get_text(0)) != NULL)
	{
		data->file_name = ft_strtrim(data->input_text);
		data->params[STDIN_MODE] = 1;
		if (cpfunc[func_index](data->input_text, data->params) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		data->params[STDIN_MODE] = 0;
	}
	return (EXIT_SUCCESS);
}

int             parse_md_arg(int argc, char **argv, t_ssl *data, int func_index)
{
	int			i;
	int			j;

	i = 2;
	data->func_index = func_index;
	while (i < argc && argv && argv[i] && argv[i][0] == '-')
	{
		j = 1;
		while (argv[i][j] != '\0')
		{
			if (ft_strchr(CPPARAMS, argv[i][j]) == NULL)
				return (ssl_cleaner(data, EXIT_FAILURE)); /* EXIT_FAILURE */
			set_options(data, argv[i][j]);
			j++;
		}
		i++;
	}
	stdin_handler(data, func_index, argc - i);
	while (i < argc)
		if (read_args(argv[i++], data, func_index) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}