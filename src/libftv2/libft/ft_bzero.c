
#include "libft.h"

void	*ft_bzero(void *b, size_t n)
{
	size_t					i;
	unsigned char			*ret;

	ret = (unsigned char *) b;
	i = 0;
	while (i < n)
	{
		*ret = 0;
		++i;
		++ret;
	}
	return (ret - i);
}
