#include "ft_ls.h"

void	ft_no_flag(char *av, DIR *dir, struct dirent *pdir, t_node **node, int ac)
{
	dir = opendir(av);
	if (ac > 2)
		ft_dir_name(node, av);
	while ((pdir = readdir(dir)) != NULL)
	{
		if (pdir->d_name[0] != '.')
		{
			ft_node_back_add(node, pdir->d_name, ft_strlen(pdir->d_name));
		}
	}
	closedir(dir);
}
