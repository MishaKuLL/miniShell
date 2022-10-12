
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ret;

	if (c == '\0')
		return (ft_strchr(s, c));
	ret = (NULL);
	while (*s)
	{
		if (*((unsigned char *)s) == (unsigned char)c)
			ret = s;
		++s;
	}
	return ((char *)ret);
}
