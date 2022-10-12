
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	if (lst->data)
		(*del)(lst->data);
	free(lst);
	lst = NULL;
}
