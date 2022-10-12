
#include "libft.h"

int	ft_putstr_fd_p(char *s, int fd)
{
	int	strlen;

	if (s == NULL)
	{
		ft_putstr_fd_p("(null)", fd);
		return (6);
	}
	strlen = ft_strlen(s);
	while (*s)
	{
		ft_putchar_fd_p(*s, fd);
		++s;
	}
	return (strlen);
}
