#include "ft_ls.h"

void            ft_display_dir(t_fileinfo *file, t_flag *flag, t_space *sp)
{
	while (file)
	{
		if (file->other)
			ft_file_other(file, flag, sp);
		else
			ft_file_no_other(file, flag, sp);
		file = file->next;
	}
}
