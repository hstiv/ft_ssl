#include "ft_ssl.h"

static void			print_stdin(char *msg, t_ssl *data)
{
	if (data->params[0])
	{
		ft_putendl_fd(data->input_text, 1);
		ft_putendl_fd(msg, 1);
	}
	else
		ft_putendl_fd(msg, 1);
}

static void			print_output(char *msg, t_ssl *data)
{
	if (data->params[4])
		print_stdin(msg, data);
	else if (!data->params[1])
	{
		if (!data->params[2])
		{
			ft_putstr((data->func_index ? "SHA256" : "MD5"));
			ft_putstr((data->file_name ? " (" : " (\""));
			ft_putstr((data->file_name ? data->file_name : data->input_text));
			ft_putstr((data->file_name ? ") = " : "\") = "));
			ft_putendl(msg);
		}
		else
		{
			ft_putstr(msg);
			ft_putstr((data->file_name ? " " : " \""));
			ft_putstr((data->file_name ? data->file_name : data->input_text));
			ft_putendl((data->file_name ? "" : "\""));
		}
	}
	else
		ft_putendl_fd(msg, 1);
}

int					md_print(char *msg, t_ssl *data)
{
	if (msg == NULL)
	{
		ft_putendl_fd("Error: malloc() doesn't work!", 2);
		return (ssl_cleaner(data, EXIT_FAILURE));
	}
	print_output(msg, data);
	ft_strdel(&msg);
	(data->input_text) ? ft_strdel(&data->input_text) : 0;
	(data->file_name) ? ft_strdel(&data->file_name) : 0;
	return (EXIT_SUCCESS);
}

char				*md5_formatter(t_md5 *data)
{
	char			*s;
	int				i;
	char			*tmp;
	
	i = -1;
	if (!(s = ft_strnew(BLOCK_32)))
		return (NULL);
	while (++i < E)
	{
		if (!(tmp = str_filled(ft_itoa_base(REV_UINT32(data->a[i]), 16), 8, '0')))
			return (NULL);
		ft_memcpy(s + (i * 8), tmp, ft_strlen(tmp));
		ft_strdel(&tmp);
	}
	return (s);
}

char				*sha256_formatter(t_sha256 *data)
{
	int				i;
	char			*s;
	char			*tmp;
	
	i = -1;
	if (!(s = ft_strnew(BLOCK_64)))
		return (NULL);
	while (++i < I)
	{
		if (!(tmp = str_filled(ft_itoa_base(data->h[i], 16), 8, '0')))
			return (NULL);
		ft_memcpy(s + (i * 8), tmp, ft_strlen(tmp));
		ft_strdel(&tmp);
	}
	return (s);
}