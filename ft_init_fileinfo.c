#include "ft_ls.h"

void	ft_init_fileinfo(t_fileinfo *fileinfo)
{
	fileinfo->amode = 0;
	fileinfo->name = NULL;
	ft_memset(fileinfo->mode, '-', 10);
	fileinfo->mode[9] = '\0';
	fileinfo->nlink = 0;
	fileinfo->pw_name = NULL;
	fileinfo->gr_name = NULL;
	fileinfo->st_size = 0;
	ft_memset(fileinfo->time, '\0', 50);
	fileinfo->next = NULL;
	fileinfo->other = NULL;
}
