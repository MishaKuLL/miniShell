
#ifndef FT_ZALLOC_H
# define FT_ZALLOC_H

# include "../libft/libft.h"

typedef struct s_heap	t_heap;

struct					s_heap
{
	void	**mem;
	size_t	count;
	void	*shell;	
};

void	*ft_zalloc(size_t size);
void	ft_free(void);
void	alloc_error(int size);

t_heap					g_heap;

#endif