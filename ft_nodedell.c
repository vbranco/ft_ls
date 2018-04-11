#include "ft_ls.h"

void	ft_nodedell(t_node **node)
{
	t_node	*tmp;

	while (*node)
	{
		tmp = *node;
		free((*node)->content);
		(*node)->content_size = 0;
		free(*node);
		(*node) = tmp->next;
	}
	*node = NULL;
}
