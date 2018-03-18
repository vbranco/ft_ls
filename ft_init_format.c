#include "ft_ls.h"

void	ft_init_format(t_format *format)
{
	format->mode = '\0';
	format->umode[3] = '\0';
	format->gmode[3] = '\0';
	format->omode[3] = '\0';
	ft_memset(format->umode, '-', 3);
	ft_memset(format->gmode, '-', 3);
	ft_memset(format->omode, '-', 3);
	format->nlink = 0;
	format->pw_name = NULL;
	format->gr_name = NULL;
	format->st_size = 0;
	ft_memset(format->time, '\0', 100);
}
