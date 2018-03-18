#include "ft_ls.h"

void	ft_no_flag(char *av, DIR *dir, struct dirent *pdir, t_list **liste, int ac)
{
	dir = opendir(av);
	if (ac > 2)
		ft_dir_name(liste, av);
	while ((pdir = readdir(dir)) != NULL)
	{
		if (pdir->d_name[0] != '.')
		{
			ft_list_back_add(liste, pdir->d_name, ft_strlen(pdir->d_name));
		}
	}
	closedir(dir);
}
