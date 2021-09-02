#include "ft_ssl.h"

static void	print_in_file(char *result)
{
	int		fd;

	fd = open(g_ssl->output_file_path, O_RDWR | O_CREAT);
	if (fd == -1)
		exit (EXIT_FAILURE);
	ft_putstr_fd(result, fd);
	close(fd);
}

void	base64_print()
{
	char	*text;
	char	*result;

	if (g_ssl->input_file_text == NULL)
		text = get_text(0);
	else
		text = g_ssl->input_file_text;
	if (text == NULL)
		exit (EXIT_FAILURE);
	result = base64(text);
	if (g_ssl->params[O])
		print_in_file(result);
	else
		mprintf("%s\n", result);
}
