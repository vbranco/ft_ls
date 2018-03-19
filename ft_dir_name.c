#include "ft_ls.h"

void    ft_dir_name(t_node **node, char *str)
{
	char    *tmp;

	tmp = ft_memalloc(ft_strlen(str) + 2);
	ft_strcat(tmp, str);
	ft_strcat(tmp, ":");
	ft_node_back_add(node, tmp, ft_strlen(tmp));
	free(tmp);
}
