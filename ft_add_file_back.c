#include "ft_ls.h"

void	ft_add_file_back(t_fileinfo **file, t_fileinfo *novo)
{
	t_fileinfo	*tmp;

	tmp = *file;
	if (!tmp)
	{
		novo->next = *file;
		*file = novo;
	}
	else
	{
		novo->next = NULL;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = novo;
	}
}
