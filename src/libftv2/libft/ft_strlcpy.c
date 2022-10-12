
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;

	len_src = ft_strlen(src);
	if (len_src == 0 || dstsize == 0)
	{
		if (dstsize != 0)
			*dst = '\0';
		return (len_src);
	}
	if (dstsize > len_src + 1)
		ft_memcpy(dst, src, len_src + 1);
	else
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (len_src);
}
