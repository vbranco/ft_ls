#include "libft.h"

void	ft_list_front_add(t_list **liste, void *content, size_t content_size)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return ;
	if (!(new->content = ft_memalloc(content_size)))
		return ;
	ft_memcpy(new->content, content, content_size);
	new->content_size = content_size;
	new->next = *liste;
	*liste = new;
}
