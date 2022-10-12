
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = len;
	i = 0;
	while (i < len)
	{
		*((unsigned char *) b) = c;
		++i;
		++b;
	}
	return (b - i);
}
