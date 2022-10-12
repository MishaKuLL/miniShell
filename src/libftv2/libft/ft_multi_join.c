
#include "libft.h"

char	*muljoin(size_t amount, va_list *args)
{
	char	*to_join;
	char	*str;
	size_t	i;

	i = 0;
	str = va_arg(*args, char *);
	while (++i < amount)
	{
		to_join = va_arg(*args, char *);
		str = ft_strjoin(str, to_join);
	}
	return (str);
}

char	*ft_multi_join(size_t	amount, ...)
{
	va_list	args;
	char	*ret;

	va_start(args, amount);
	ret = muljoin(amount, &args);
	va_end(args);
	return (ret);
}
