#include "ft_ls.h"

static int	ft_sort(char *s1, char *s2)
{
	int		i;

	i = 0;
//	if (s1[i] == '.')
//		i++;
//	else if (s1[i] < s2[i])
	if (s1[i] < s2[i])
		return (1);
	return (0);
}

void	ft_node_sort_add(t_node **node, void *content, size_t content_size)
{
	t_node  *new;
	t_node  *tmp = NULL;
	t_node  *ll;

	ll = *node;
	if (!(new = (t_node*)malloc(sizeof(t_node))))
		return ;
	if (!(new->content = ft_memalloc(content_size)))
		return ;
	while (ll && ft_sort(ll->content, content))
	{
		tmp = ll;
		ll = ll->next;
	}
	ft_memcpy(new->content, content, content_size);
	new->content_size = content_size;
	new->next = ll;
	if (tmp)
		tmp->next = new;
	else
		*node = new;
}
