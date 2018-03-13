#include "ft_ls.h"

int		ft_new_elem_front_list(t_liste **liste, char *str)
{
	t_liste	*new;

	new = malloc(sizeof(t_liste));
	if (!new)
		return (-1);
	new->str = malloc(sizeof(ft_strlen(str)));
	if (!new->str)
		return (-1);
	ft_strcat(new->str, str);
	new->next = *liste;
	*liste = new;
	return (0);
}
