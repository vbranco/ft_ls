#include "ft_ls.h"

void	ft_node_back_add(t_node **node, void *content, size_t content_size)
{
	t_node	*tmp;
	t_node	*new;

	tmp = NULL;
	if (!(new = (t_node*)malloc(sizeof(t_node))))
		return ;
	if (!(new->content = ft_memalloc(content_size)))
		return ;
	tmp = *node;
	if (!tmp)
	{
		new->next = *node;
		*node = new;
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
