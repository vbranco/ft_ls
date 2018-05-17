/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dir.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/30 16:07:19 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/17 17:40:48 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static int			ft_test(t_flag *flag, char *name)
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

static void			ft_new_null(t_fileinfo *current, t_flag *flag, t_space *sp)
{
	t_fileinfo		*new;

	new = ft_info(current->path, "", sp);
	if (flag->f)
		ft_add_file_back(&(current->other), new);
	else
		ft_fileinfo_sort(&(current->other), new, flag);
}

static void			ft_flag_f(t_fileinfo *current, t_fileinfo *new,
		t_flag *flag)
{
	if (flag->f)
		ft_add_file_back(&(current->other), new);
	else
		ft_fileinfo_sort(&(current->other), new, flag);
}

void				ft_is_dir(t_fileinfo *current, char *direct, t_flag *flag,
		t_space *sp)
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
		ft_flag_f(current, new, flag);
		return ;
	}
	while ((pdir = readdir(dir)) != NULL)
	{
		if (ft_test(flag, pdir->d_name))
			continue ;
		new = ft_info(direct, pdir->d_name, sp);
		((ft_dir(new) && flag->gr)) ? ft_recursive(new, flag, sp) : 0;
		ft_flag_f(current, new, flag);
	}
	((flag->a)) ? ft_flag_a(current, direct, flag, sp) : 0;
	((new == NULL)) ? ft_new_null(current, flag, sp) : 0;
	closedir(dir);
}

void				ft_recursive(t_fileinfo *current, t_flag *flag, t_space *sp)
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
		ft_flag_f(current, new, flag);
		return ;
	}
	while ((pdir = readdir(dir)) != NULL)
	{
		if (ft_test(flag, pdir->d_name))
			continue ;
		new = ft_info(current->path, pdir->d_name, sp);
		((ft_dir(new) && flag->gr)) ? ft_recursive(new, flag, sp) : 0;
		ft_flag_f(current, new, flag);
	}
	((flag->a)) ? ft_flag_a(current, current->path, flag, sp) : 0;
	((new == NULL)) ? ft_new_null(current, flag, sp) : 0;
	closedir(dir);
}
