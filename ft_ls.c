/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 16:15:07 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/28 17:47:02 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_error(t_fileinfo **novo, char *file, char *error)
{
//	char		err[PATH_MAX];
	char		err[10000];
	char		*name;

	name = NULL;
	if (ft_strcmp(error, "Permission denied") == 0)
	{
		if (*file == '/' && ft_strchr(++file, '/'))
			file--;
		name = ft_strdup(file);
	}
	else
		name = ft_strdup(file);
//	ft_bzero(err, PATH_MAX);
	ft_bzero(err, 10000);
	ft_strcat(err, "ls: ");
	ft_strcat(err, name);
	ft_strcat(err, ": ");
	ft_strcat(err, error);
	(*novo)->error = ft_strdup(err);
	if ((*novo)->name == NULL)
		(*novo)->name = ft_strdup(file);
	if (name != NULL)
		free(name);
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
//		if (path[ft_strlen(path)-1] != '/')
		ft_strcat(path, "/");
		ft_strcat(path, name);
		new->path = ft_strdup(path);
		free(path);
	}
	if (name[0] != '\0')
		ft_stat(new, sp);
	if (name[0] == '\0' && dir[0] == '\0')
		ft_error(&new, "fts_open", "No such file or directory");
	return (new);
}

static void	ft_recursive(t_fileinfo *current, t_flag *flag, t_space *sp)
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
		if (pdir->d_name[0] == '.' && !flag->a)
			continue ;
		if (flag->a)
		{
			if (pdir->d_name[0] == '.' && (pdir->d_name[1] == '.' || pdir->d_name[1] == '\0'))
				continue ;
		}
		new = ft_info(current->path, pdir->d_name, sp);
//		if (ft_dir(new) && flag->R)
		if (ft_dir(new) && flag->R && !(new->mode[0] == 'r' && new->mode[2] == '-'))
			ft_recursive(new, flag, sp);
		ft_fileinfo_sort(&(current->other), new, flag);
	}
	if (flag->a)
		ft_flag_a(current, current->path, flag, sp);
	if (new == NULL)
	{
		new = ft_info(current->path, "", sp);
		ft_fileinfo_sort(&(current->other), new, flag);
	}
	closedir(dir);
}

void		ft_flag_a(t_fileinfo *current, char *direct, t_flag *flag, t_space *sp)
{
	t_fileinfo	*new;

	new = ft_info(direct, ".", sp);
	ft_fileinfo_sort(&(current->other), new, flag);
	new = ft_info(direct, "..", sp);
	ft_fileinfo_sort(&(current->other), new, flag);
}

static int	ft_is_dir(t_fileinfo *current, char *direct, t_flag *flag, t_space *sp)
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
		return (0);
	}
	while ((pdir = readdir(dir)) != NULL)
	{
		if (pdir->d_name[0] == '.' && !flag->a)
			continue ;
		if (flag->a)
		{
			if (pdir->d_name[0] == '.' && (pdir->d_name[1] == '.' || pdir->d_name[1] == '\0'))
				continue ;
		}
		new = ft_info(direct, pdir->d_name, sp);
//		if (ft_dir(new) && flag->R)
		if (ft_dir(new) && flag->R && !(new->mode[0] == 'r' && new->mode[2] == '-'))
			ft_recursive(new, flag, sp);
		ft_fileinfo_sort(&(current->other), new, flag);
	}
	if (flag->a)
		ft_flag_a(current, direct, flag, sp);
	if (new == NULL)
	{
		new = ft_info(direct, "", sp);
		ft_fileinfo_sort(&(current->other), new, flag);
	}
	closedir(dir);
	return (1);
}

t_fileinfo	*ft_is_link(char *file)
{
	t_fileinfo	*new;

	new = ft_init_fileinfo();
	new->path = ft_strdup(file);
	stat(new->path, &(new->st));
	new->name = ft_strdup(file);
	ft_ugid(new);
	ft_amode(new);
	ft_rmode(new);
	return (new);
}

void		ft_ls(t_fileinfo **start, t_node **args, t_flag *flag, t_space *sp)
{
	t_node		*arg;
	t_fileinfo	*new;

	arg = *args;
//	while (arg)
	while (arg->next)
	{
		new = ft_info(NULL, arg->content, sp);
		if (S_ISLNK(new->st.st_mode) && !flag->l)
		{
			ft_fileinfo_dell(&new);
			new = ft_is_link(arg->content);
		}
		if (ft_dir(new) == 1 && !(new->mode[0] == 'r' && new->mode[2] == '-'))
			ft_is_dir(new, arg->content, flag, sp);
		ft_fileinfo_sort(start, new, flag);
		arg = arg->next;
	}
}
