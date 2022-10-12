
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*to_del;
	t_list	*curr_lst;

	if (!lst)
		return ;
	to_del = *lst;
	while (to_del)
	{
		curr_lst = to_del->next;
		ft_lstdelone(to_del, del);
		to_del = curr_lst;
	}
	*lst = to_del;
}
