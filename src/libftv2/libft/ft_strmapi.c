
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*ret;
	unsigned int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	ret = ft_strdup(s);
	if (ret == NULL)
		return (NULL);
	while (ret[i])
	{
		ret[i] = (*f)(i, s[i]);
		++i;
	}
	return (ret);
}
