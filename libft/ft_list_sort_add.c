#include "libft.h"

static int	ft_sort(char *s1, char *s2)
{
	if (s1[0] < s2[0])
		return (1);
	return (0);
}

void	ft_list_sort_add(t_list **liste, void *content, size_t content_size)
{
	t_list  *new;
	t_list  *tmp = NULL;
	t_list  *ll;

	ll = *liste;
	if (!(new = malloc(sizeof(t_list))))
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
		*liste = new;
}
