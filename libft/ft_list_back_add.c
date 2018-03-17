#include "libft.h"

void	ft_list_back_add(t_list **liste, void *content, size_t content_size)
{
	t_list	*tmp;
	t_list	*new;

	tmp = NULL;
	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return ;
	if (!(new->content = ft_memalloc(content_size)))
		return ;
	tmp = *liste;
	if (!tmp)
	{
		new->next = *liste;
		*liste = new;
	}
	else
	{
		new->next = NULL;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	ft_memcpy(new->content, content, content_size);
	new->content_size = content_size;
}
