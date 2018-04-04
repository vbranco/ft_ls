#include "ft_ls.h"

void	ft_fileinfoprint(t_fileinfo *file)
{
	while (file)
	{
		if (file->other != NULL)
		{
//			printf("other existe\n");
			ft_fileinfoprint(file->other);
			if (!file)
				return ;
		}
		printf("%s ", file->name);
		printf("%s\n", file->pw_name);
		file = file->next;
	}
}
