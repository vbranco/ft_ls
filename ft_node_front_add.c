#include "ft_ls.h"

void	ft_node_front_add(t_node **node, void *content, size_t content_size)
{
	t_node	*new;

	if (!(new = (t_node*)malloc(sizeof(t_node))))
		return ;
	if (!(new->content = ft_memalloc(content_size)))
		return ;
	ft_memcpy(new->content, content, content_size);
	new->content_size = content_size;
	new->next = *node;
	*node = new;
}
