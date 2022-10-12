
#include "libft.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	sze;

	if (s == NULL)
		return (NULL);
	if ((size_t) start >= ft_strlen(s))
		return (ft_zalloc(sizeof(char)));
	sze = (size_t)ft_min(ft_strlen(s + start), len);
	ret = ft_zalloc((sze + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(ret, s + start, sze + 1);
	return (ret);
}
