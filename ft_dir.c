#include "ft_ls.h"

int		ft_test(t_flag *flag, char *name)
{
	if (!flag->a)
	{
		if (name[0] == '.')
			return (1);
	}
	else if (flag->a)
	{
		if (name[0] == '.' && (name[1] == '.' || name[1] == '\0'))
			return (1);
	}
	return (0);
}

void	ft_new_null(t_fileinfo *current, t_flag *flag, t_space *sp)
{
	t_fileinfo	*new;

	new = ft_info(current->path, "", sp);
	ft_fileinfo_sort(&(current->other), new, flag);
}

void	ft_is_dir(t_fileinfo *current, char *direct, t_flag *flag, t_space *sp)
{
	DIR				*dir;
	struct dirent	*pdir;
	t_fileinfo		*new;

	errno = 0;
	new = NULL;
	if (!(dir = opendir(direct)))
	{
		new = ft_info(NULL, direct, sp);
		if (new->error == NULL)
			ft_error(&new, direct, strerror(errno));
		ft_fileinfo_sort(&(current->other), new, flag);
		return ;
	}
	while ((pdir = readdir(dir)) != NULL)
	{
		if (ft_test(flag, pdir->d_name))
			continue ;
		new = ft_info(direct, pdir->d_name, sp);
		((ft_dir(new) && flag->R)) ? ft_recursive(new, flag, sp) : 0;
		ft_fileinfo_sort(&(current->other), new, flag);
	}
	((flag->a)) ? ft_flag_a(current, direct, flag, sp) : 0;
	((new == NULL)) ? ft_new_null(current, flag, sp) : 0;
	closedir(dir);
}

void	ft_recursive(t_fileinfo *current, t_flag *flag, t_space *sp)
{
	DIR				*dir;
	struct dirent	*pdir;
	t_fileinfo		*new;

	errno = 0;
	new = NULL;
	if (!(dir = opendir(current->path)))
	{
		new = ft_info(current->path, pdir->d_name, sp);
		if (new->error == NULL)
			ft_error(&new, current->name, strerror(errno));
		ft_fileinfo_sort(&(current->other), new, flag);
		return ;
	}
	while ((pdir = readdir(dir)) != NULL)
	{
		if (ft_test(flag, pdir->d_name))
			continue ;
		new = ft_info(current->path, pdir->d_name, sp);
		((ft_dir(new) && flag->R)) ? ft_recursive(new, flag, sp) : 0;
		ft_fileinfo_sort(&(current->other), new, flag);
	}
	((flag->a)) ? ft_flag_a(current, current->path, flag, sp) : 0;
	((new == NULL)) ? ft_new_null(current, flag, sp) : 0;
	closedir(dir);
}

void	ft_flag_a(t_fileinfo *current, char *direct, t_flag *flag, t_space *sp)
{
	t_fileinfo	*new;

	new = ft_info(direct, ".", sp);
	ft_fileinfo_sort(&(current->other), new, flag);
	new = ft_info(direct, "..", sp);
	ft_fileinfo_sort(&(current->other), new, flag);
}
