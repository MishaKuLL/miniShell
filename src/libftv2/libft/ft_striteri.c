
#include "libft.h"

char	*ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		(*f)(i, &s[i]);
		++i;
	}
	return (s);
}
