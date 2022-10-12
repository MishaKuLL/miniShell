
#include "libft.h"

void	ft_putnbr_fd_p(long long n, int fd, int *len)
{
	if (n < 0)
	{
		ft_putchar_fd_p('-', fd);
		n = n * (-1);
		*len += 1;
	}
	if (n >= 10)
		ft_putnbr_fd_p(n / 10, fd, len);
	ft_putchar_fd_p('0' + (n % 10), fd);
	*len += 1;
}
