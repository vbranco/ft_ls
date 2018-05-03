#include "ft_ls.h"

static void    ft_push(t_fileinfo **file, t_fileinfo *new)
{
	new->next = *file;
	*file = new;
}
void    ft_flag_a(t_fileinfo *current, char *direct, t_flag *flag, t_space *sp)
{
	t_fileinfo  *new;

	if (flag->f)
	{
		new = ft_info(direct, "..", sp);
		ft_push(&(current->other), new);
		new = ft_info(direct, ".", sp);
		ft_push(&(current->other), new);
	}
	else
	{
		new = ft_info(direct, ".", sp);
		ft_fileinfo_sort(&(current->other), new, flag);
		new = ft_info(direct, "..", sp);
		ft_fileinfo_sort(&(current->other), new, flag);
	}
}
