
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		ret;
	size_t	i;

	i = 1;
	ret = 0;
	if (n == 0)
		return (0);
	while (*((unsigned char *)s1) && *((unsigned char *)s2) && i < n)
	{
		if (*((unsigned char *)s1) == *((unsigned char *)s2))
		{
			++i;
			++s1;
			++s2;
		}
		else
			break ;
	}	
	ret = *((unsigned char *)s1) - *((unsigned char *)s2);
	return (ret);
}
