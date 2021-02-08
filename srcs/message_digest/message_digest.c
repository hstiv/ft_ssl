#include "ft_ssl.h"

static char		*get_text(int fd)
{
	char		*s;
	char		*prev;
	int			y;
	char		buff[BLOCK_512 + 1];
	char		*tmp;

	prev = NULL;
	s = NULL;
	while ((y = read(fd, buff, BLOCK_512)) > 0)
	{
		buff[y] = '\0';
		(prev != NULL) ? ft_strdel(&prev) : 0;
		prev = s;
		s = ft_strdup(buff);
	}
	if (prev != NULL)
	{
		tmp = s;
		s = ft_strjoin(prev + ft_strlen(s), s);
		ft_strdel(&tmp);
		ft_strdel(&prev);
	}
	return (s);
}

static int		read_args(char *argv, t_ssl *data, int func_index)
{
	int			fd;
	
	data->file_name = ft_strdup(argv);
	if ((fd = open(argv, O_RDONLY)) != -1)
		data->input_text = get_text(fd);
	else if (data->params[3])
	{
		data->input_text = ft_strdup(argv);
		(data->file_name) ? ft_strdel(&data->file_name) : 0;
		data->params[3] = 0;
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
	if (c == 'p')
		data->params[0] = 1;
	else if (c == 'q')
		data->params[1] = 1;
	else if (c == 'r')
		data->params[2] = 1;
	else if (c == 's')
		data->params[3] = 1;
}

int             parse_md_arg(int argc, char **argv, t_ssl *data, int func_index)
{
	int			i;

	i = 2;
    data->params = (int *)malloc(sizeof(int) * 5);
	data->func_index = func_index;
	while (i < argc && argv && argv[i] && argv[i][0] == '-')
	{
		argv[i] += 1;
		while (*argv[i] != '\0')
		{
			if (ft_strchr(MDPARAMS, *argv[i]) == NULL)
				return (ssl_cleaner(data, EXIT_FAILURE)); /* EXIT_FAILURE */
			set_options(data, *argv[i]);
			argv[i]++;
		}
		i++;
	}
	if ((data->input_text = get_text(0)) != NULL)
		md_print(mdfunc[func_index](data->input_text), data);
	data->params[0] = 0;
	while (i < argc)
		if (read_args(argv[i++], data, func_index) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}