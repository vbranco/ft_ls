#include "ft_ls.h"

void	ft_fileinfo_dell(t_fileinfo **file)
{
	t_fileinfo  *tmp;

	while (*file)
	{
		tmp = *file;
		if ((*file)->other)
			ft_fileinfo_dell(&(*file)->other);
		(*file)->amode = 0;
		free((*file)->name);
		free((*file)->path);
		free((*file)->pw_name);
		free((*file)->gr_name);
		free((*file)->time);
		if ((*file)->error != NULL)
			free((*file)->error);
		free(*file);
		*file = tmp->next;
	}
	*file = NULL;
}
