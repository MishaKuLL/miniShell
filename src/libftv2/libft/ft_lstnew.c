
#include "libft.h"

t_list	*ft_lstnew(void *data)
{
	t_list	*new;

	new = ft_zalloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}
