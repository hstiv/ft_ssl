#include "ft_ssl.h"

static void		print_md(uint32_t hash, t_ssl *data)
{
	if (hash == 0)
		return ;
}

static char		*get_text(fd)
{
	char		*line;
	char		*s;
	char		*tmp;

	get_next_line(fd, &s);
	ft_memdel(&line);
	while (get_next_line(fd, &line) || line)
	{
		tmp = s;
		s = ft_strjoin(s, line);
		ft_memdel(&tmp);
		ft_memdel(&line);
	}
	return (s);
}

static int		read_args(char argv, t_ssl *data, int (*f)(char *))
{
	char		*txt;
	int			fd;
	
	ft_memdel(&txt);
	fd = open(argv, O_RDONLY);
	txt = get_text(fd);
	close(fd);
	data->input_text = txt ? txt : argv;
	print_md((*f)(data->input_text), data);
	txt ? free(txt) : 0;
	return (1);
}

static void		set_opt(data, char c)
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

int             parse_md_arg(int argc, char **argv, t_ssl *data, int (*f)(char *))
{
	int			i;

	i = 2;
    data->params = (int *)malloc(sizeof(int) * 5);
	while (i < argc && argv && argv[i] && argv[i][0] == '-')
	{
		argv[i] += 1;
		while (*argv[i] != '\0')
		{
			if (ft_strchr(MDPARAMS, *argv[i]) == NULL)
				return (1);
			set_opt(data, *argv[i]);
			argv[i]++;
		}
		i++;
	}
	data->input_text = get_text(1);
	print_md((*f)(data->input_text), data);
	while (i < argc)
		read_args(argv[i], data, (*f));
	return (1);
}