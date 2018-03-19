#include "ft_ls.h"

void	ft_nodeprint(t_node *node)
{
	while (node)
	{
		printf("%s\n", node->content);
		node = node->next;
	}
}
