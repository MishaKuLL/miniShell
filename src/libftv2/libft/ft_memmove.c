
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst == NULL && src == NULL && len)
		return (NULL);
	if (dst < src)
		dst = ft_memcpy(dst, src, len);
	else
	{
		while (len-- > 0)
			*((char *)dst + len) = *((const char *)src + len);
	}
	return (dst);
}
