#include "ft_ssl.h"

static const char	*g_opt[5] = {
	"MD5",
	"SHA256",
	"SHA224",
	"SHA512",
	NULL
};

static void	print_stdin(char *msg, t_ssl *data)
{
	if (data->params[_P])
		mprintf("%s\n%s\n", data->file_name, msg);
	else
		ft_putendl_fd(msg, 1);
}

static void	print_output(char *msg, t_ssl *data)
{
	if (data->params[STDIN_MODE])
		print_stdin(msg, data);
	else if (!data->params[_Q])
	{
		if (!data->params[_R])
		{
			ft_putstr((g_opt[data->func_index]));
			if (data->file_name)
				mprintf(" (%s) = ", data->file_name);
			else
				mprintf(" (\"%s\") = ", data->input_text);
			ft_putendl(msg);
		}
		else
		{
			ft_putstr(msg);
			if (data->file_name)
				mprintf(" %s\n", data->file_name);
			else
				mprintf(" \"%s\"\n", data->input_text);
		}
	}
	else
		ft_putendl_fd(msg, 1);
}

int	md_print(char *msg, t_ssl *data)
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
	if (data->input_text)
		ft_strdel(&data->input_text);
	if (data->file_name)
		ft_strdel(&data->file_name);
	while (++i < 5)
		data->params[i] = 0;
	return (EXIT_SUCCESS);
}
