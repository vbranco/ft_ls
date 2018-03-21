#include "ft_ls.h"

void	ft_nodeprint(t_node *node)
{
	while (node)
	{
//		if (node->other)
		printf("%s\n", node->content);
		node = node->next;
	}
}
