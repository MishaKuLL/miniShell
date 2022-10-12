
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == NULL && src == NULL && n)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*((unsigned char *) dst) = *((unsigned const char *)src);
		++i;
		++dst;
		++src;
	}
	return (dst - i);
}
