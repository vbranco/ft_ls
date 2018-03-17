#include "ft_ls.h"

void    ft_dir_name(t_list **liste, char *str)
{
	char    *tmp;

	tmp = ft_memalloc(ft_strlen(str) + 2);
	ft_strcat(tmp, str);
	ft_strcat(tmp, ":");
	ft_list_back_add(liste, tmp, ft_strlen(tmp));
	free(tmp);
}
