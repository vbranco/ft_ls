/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 16:15:07 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 20:01:21 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_error(t_fileinfo **novo, char *file, char *error)
{
	char		err[PATH_MAX];

	ft_bzero(err, PATH_MAX);
	ft_strcat(err, "ls: ");
	ft_strcat(err, file);
	ft_strcat(err, ": ");
	ft_strcat(err, error);
	(*novo)->error = ft_strdup(err);
	(*novo)->name = ft_strdup(file);
}

static int	ft_dir(t_fileinfo *new)
{
	if ((new->st.st_mode & S_IFMT) == S_IFDIR)
		return (1);
	return (0);
}

t_fileinfo	*ft_info(char *dir, char *name, t_space *sp)
{
	t_fileinfo	*new;
	char		*path;

	path = NULL;
	new = ft_init_fileinfo();
	if (dir == NULL)
		new->path = ft_strdup(name);
	else
	{
		path = ft_memalloc(ft_strlen(dir) + ft_strlen(name) + 2);
		ft_strcat(path, dir);
		ft_strcat(path, "/");
		ft_strcat(path, name);
		new->path = ft_strdup(path);
		free(path);
	}
	ft_stat(new, sp);
	return (new);
}

static void	ft_recursive(t_fileinfo *current, t_flag *flag, t_space *sp)
{
	DIR				*dir;
	struct dirent	*pdir;
	t_fileinfo		*new;

	errno = 0;
	if ((dir = opendir(current->path)) == NULL)
	{
		new = ft_info(current->path, pdir->d_name, sp);
		ft_error(&new, current->path, strerror(errno));
		ft_fileinfo_sort(&(current->other), new, flag);
		return ;
	}
	while ((pdir = readdir(dir)) != NULL)
	{
		if (pdir->d_name[0] == '.' && !flag->a)
			continue ;
		new = ft_info(current->path, pdir->d_name, sp);
		if (ft_dir(new) && flag->R)
			ft_recursive(new, flag, sp);
		ft_fileinfo_sort(&(current->other), new, flag);
	}
	closedir(dir);
}

static int	ft_is_dir(t_fileinfo *current, char *direct, t_flag *flag, t_space *sp)
{
	DIR				*dir;
	struct dirent	*pdir;
	t_fileinfo		*new;

	errno = 0;
	if ((dir = opendir(direct)) == NULL)
	{
		new = ft_info(NULL, direct, sp);
		ft_error(&new, direct, strerror(errno));
		ft_fileinfo_sort(&(current->other), new, flag);
		return (0);
	}
	while ((pdir = readdir(dir)) != NULL)
	{
		if (pdir->d_name[0] == '.' && !flag->a)
			continue ;
		new = ft_info(direct, pdir->d_name, sp);
		if (ft_dir(new) && flag->R)
			ft_recursive(new, flag, sp);
		ft_fileinfo_sort(&(current->other), new, flag);
	}
	closedir(dir);
	return (1);
}

void		ft_ls(t_fileinfo **start, t_node **args, t_flag *flag, t_space *sp)
{
	t_node		*arg;
	t_fileinfo	*new;

	arg = *args;
	while (arg)
	{
		new = ft_info(NULL, arg->content, sp);
		if (ft_dir(new) == 1)
		{
			ft_is_dir(new, arg->content, flag, sp);
		}
		ft_fileinfo_sort(start, new, flag);
		arg = arg->next;
	}
}
