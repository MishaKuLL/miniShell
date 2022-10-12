
#include "libft.h"

int	ft_isalnum(int a)
{
	if (ft_isdigit(a) || ft_isalpha(a))
		return (1);
	else
		return (0);
}
