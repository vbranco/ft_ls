#include "libft.h"

void	ft_listdell(t_list *liste)
{
	while (liste->next)
	{
		free(liste->content);
		liste->content_size = 0;
		free(liste);
		liste = liste->next;
	}
	liste = NULL;
}
