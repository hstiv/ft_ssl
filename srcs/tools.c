#include "ft_ssl.h"

char	*get_text(int fd)
{
	char		*s;
	char		buff[3];
	char		*tmp;
	int			input_size;

	s = ft_strdup("");
	if (s == NULL)
		fman("Memory allocation error", EXIT_FAILURE);
	input_size = 0;
	while (read(fd, buff, 1) > 0)
	{
		tmp = s;
		buff[1] = '\0';
		s = ft_strjoin(s, buff);
		if (s == NULL)
			fman("Memory allocation error", EXIT_FAILURE);
		ft_strdel(&tmp);
		input_size++;
	}
	if (input_size == 0)
		ft_strdel(&s);
	return (s);
}

char	*ft_strtolower(char *str)
{
	int		i;
	char	*s;

	s = ft_strnew(ft_strlen(str));
	if (s == NULL)
		fman("Memory allocation error", EXIT_FAILURE);
	i = 0;
	while (str[i] != '\0')
	{
		s[i] = ft_tolower(str[i]);
		i++;
	}
	return(s);
}
