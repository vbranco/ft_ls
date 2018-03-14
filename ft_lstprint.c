#include "ft_ls.h"

void	ft_lstprint(t_list *liste)
{
	while (liste)
	{
		printf("%s\n", liste->content);
		liste = liste->next;
	}
}
