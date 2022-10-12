
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*a1;
	unsigned const char	*a2;

	a1 = (unsigned const char *) s1;
	a2 = (unsigned const char *) s2;
	while (n)
	{
		if (*a1 != *a2)
			return (*a1 - *a2);
		--n;
		++a1;
		++a2;
	}
	return (0);
}
