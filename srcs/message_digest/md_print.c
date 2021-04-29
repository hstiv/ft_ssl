#include "ft_ssl.h"

static const char	*g_opt[5] = {
	"MD5",
	"SHA256",
	"SHA224",
	"SHA512",
	NULL
};

static void			print_stdin(char *msg, t_ssl *data)
{
	if (data->params[_P])
	{
		ft_putendl_fd(data->file_name, 1);
		ft_putendl_fd(msg, 1);
	}
	else
		ft_putendl_fd(msg, 1);
}

static void			print_output(char *msg, t_ssl *data)
{
	if (data->params[STDIN_MODE])
		print_stdin(msg, data);
	else if (!data->params[_Q])
	{
		if (!data->params[_R])
		{
			ft_putstr((g_opt[data->func_index]));
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
	int				i;

	i = -1;
	if (msg == NULL)
	{
		ft_putendl_fd("Error: malloc() doesn't work!", 2);
		return (ssl_cleaner(data, EXIT_FAILURE));
	}
	print_output(msg, data);
	ft_strdel(&msg);
	(data->input_text) ? ft_strdel(&data->input_text) : 0;
	(data->file_name) ? ft_strdel(&data->file_name) : 0;
	while (++i < 5)
		data->params[i] = 0;
	return (EXIT_SUCCESS);
}
