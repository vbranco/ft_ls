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

//	printf("ls prb sur ft_recursive || dir >> %s\n", current->path);
	if ((dir = opendir(current->path)) == NULL)
	{
		printf("ls prb sur ft_recursive || dir >> %s\n", current->path);
//		perror("ls problem in ft_recursive");
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

	if ((dir = opendir(direct)) == NULL)
	{
		perror("ls problem sur ft_is_dir");
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
			if (ft_is_dir(new, arg->content, flag, sp))
				ft_fileinfo_sort(start, new, flag);
		}
		arg = arg->next;
	}
}
