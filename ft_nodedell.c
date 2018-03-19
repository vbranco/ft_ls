#include "ft_ls.h"

void	ft_nodedell(t_node *node)
{
	while (node->next)
	{
		free(node->content);
		node->content_size = 0;
		free(node);
		node = node->next;
	}
	node = NULL;
}
