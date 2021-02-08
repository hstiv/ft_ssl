#include "ft_ssl.h"

static int		print_md(char *msg, t_ssl *data)
{
	if (msg == NULL)
	{
		ft_putstr("Error: malloc() doesn't work!\n");
		return (EXIT_FAILURE);
	}
	ft_putstr(msg);
	ft_putstr("\n");
	free(msg);
	return (EXIT_SUCCESS);
}

static char		*get_text(int fd)
{
	char		*line;
	char		*s;
	char		*tmp;

	get_next_line(fd, &s);
	line = NULL;
	while (get_next_line(fd, &line) || line)
	{
		tmp = s;
		s = ft_strjoin(s, line);
		ft_memdel((void **)&tmp);
		ft_memdel((void **)&line);
	}
	return (s);
}

static int		read_args(char *argv, t_ssl *data, int func_index)
{
	int			fd;
	
	data->file_name = ft_strdup(argv);
	if ((fd = open(argv, O_RDONLY)) != -1)
	{
		data->input_text = get_text(fd);
		close(fd);
	}
	else
		data->input_text = ft_strdup(argv);
	if (print_md(mdfunc[func_index](data->input_text), data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_memdel((void **)&data->input_text);
	ft_memdel((void **)&data->file_name);
	return (EXIT_SUCCESS);
}

static void		set_opt(t_ssl *data, char c)
{
	if (c == 'p')
		data->params[0] == 1;
	else if (c == 'q')
		data->params[1] == 1;
	else if (c == 'r')
		data->params[2] == 1;
	else if (c == 's')
		data->params[3] == 1;
}

int             parse_md_arg(int argc, char **argv, t_ssl *data, int func_index)
{
	int			i;

	printf("Checkpint #1\n");
	i = 2;
    data->params = (int *)malloc(sizeof(int) * 5);
	while (i < argc && argv && argv[i] && argv[i][0] == '-')
	{
		argv[i] += 1;
		while (*argv[i] != '\0')
		{
			if (ft_strchr(MDPARAMS, *argv[i]) == NULL)
				return (EXIT_FAILURE);
			set_opt(data, *argv[i]);
			argv[i]++;
		}
		i++;
	}
	printf("Checkpint #2\n");
	data->input_text = get_text(1);
	print_md(mdfunc[func_index](data->input_text), data);
	while (i < argc)
		if (read_args(argv[i], data, func_index) == -1)
			return (EXIT_FAILURE);
	ft_memdel((void **)&data->params);
	return (EXIT_SUCCESS);
}