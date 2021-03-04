#include "ft_ssl.h"

int				no_file_err(t_ssl *data, char *func_name)
{
	ft_putstr("ft_ssl: ");
	ft_putstr(func_name);
	ft_putstr(": ");
	ft_putstr(data->file_name);
	ft_putendl_fd(": No such file or directory", 2);
	return (ssl_cleaner(data, EXIT_FAILURE));
}

int				ssl_cleaner(t_ssl *data, int exit_result)
{
	(data->file_name != NULL) ? ft_strdel(&data->file_name) : 0;
	(data->input_text != NULL) ? ft_strdel(&data->input_text) : 0;
	return (exit_result);
}

int				error_option(char *s, t_ssl *data)
{
	int			i;

	i = 0;
	ft_putstr_fd(ERR_1_1, 2);
	ft_putstr_fd(s, 2);
	ft_putendl_fd(ERR_1_2, 2);
	ft_putendl_fd(ERR_2, 2);
	while (mdcmds[i] != NULL)
		ft_putendl_fd(mdcmds[i++], 2);
	ft_putendl_fd("", 2);
	ft_putendl_fd(ERR_3, 2);
	i = 0;
	while (cpcmds[i] != NULL)
		ft_putendl_fd(cpcmds[i++], 2);
	return (ssl_cleaner(data, EXIT_FAILURE));
}