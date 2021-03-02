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
	else if (data->params[_S])
	{
		data->input_text = ft_strdup(argv);
		(data->file_name) ? ft_strdel(&data->file_name) : 0;
		data->params[_S] = 0;
	}
	close(fd);
	if (!data->input_text)
	{
		no_file_err(data, mdoptions[func_index]);
		(data->file_name) ? ft_strdel(&data->file_name) : 0;
		return (EXIT_SUCCESS);
	}
	return (md_print(mdfunc[func_index](data->input_text), data));
}

static void		set_options(t_ssl *data, char c)
{
	if (c == 'p' || c == 'P')
		data->params[_P] = 1;
	else if (c == 'q' || c == 'Q')
		data->params[_Q] = 1;
	else if (c == 'r' || c == 'R')
		data->params[_R] = 1;
	else if (c == 's' || c == 'S')
		data->params[_S] = 1;
	data->params[STDIN_MODE] = 0;
}

int				stdin_handler(t_ssl *data, int func_index, int arg_count)
{
	if (!data->params[BASH_MODE] && (data->input_text = get_text(0)) != NULL
		&& (data->params[_P] || !arg_count))
	{
		data->file_name = ft_strtrim(data->input_text);
		data->params[STDIN_MODE] = 1;
		md_print(mdfunc[func_index](data->input_text), data);
		data->params[_P] = 0;
		data->params[STDIN_MODE] = 0;
	}
	else if (arg_count == 0)
	{
		md_print(mdfunc[func_index](""), data);
		data->params[_P] = 0;
		data->params[STDIN_MODE] = 0;
	}
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
			if (ft_strchr(MDPARAMS, argv[i][j]) == NULL)
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