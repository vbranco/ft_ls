/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/20 16:39:39 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/07 18:31:33 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"
/*
static void		ft_add_file_front(t_fileinfo **fileinfo, t_fileinfo *new)
{
	new->next = *fileinfo;
	*fileinfo = new;
}

static void		ft_add_file_back(t_fileinfo **fileinfo, t_fileinfo *new)
{
	t_fileinfo	*tmp;

	tmp = *fileinfo;
	if (!tmp)
	{
		new->next = *fileinfo;
		*fileinfo = new;
	}
	else
	{
		new->next = NULL;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

static void		ft_path()
{
}

static void		ft_work(t_fileinfo *current, char *name, t_fileinfo **fileinfo, t_space *sp, t_flag *flag)
{
	t_fileinfo	*new;
	char		*path;

	path = ft_memalloc(ft_strlen(current->path) + ft_strlen(name) + 2);
	ft_strcat(path, current->path);
	ft_strcat(path, "/");
	ft_strcat(path, name);
	new = ft_init_fileinfo();
	new->path = ft_strdup(path);
	if (ft_stat(new, sp) == 1)
		return ;
//	ft_fileinfo_sort(fileinfo, new, flag);
	free(path);
}

void		ft_recursive(t_fileinfo **base, t_fileinfo *current, t_flag *flag, t_space *sp)
{
	t_fileinfo		*new;
	DIR				*dir;
	struct dirent	*pdir;

	ft_work(
	if ((dir = opendir(
}

void		ft_add_dir_front(t_fileinfo **base, t_fileinfo *current, t_flag *flag, t_space *sp)
{
	t_fileinfo		*new;
	DIR				*dir;
	struct dirent	*pdir;
	struct stat		ST;

	errno = 0;
	new = ft_init_fileinfo();
	if ((dir = opendir(current->path)) == NULL)
	{
		perror("ls: t");
		return (NULL);
	}
	while ((pdir = readdir(dir)) != NULL)
	{
		if (flag->a == 0)
		{
			if (pdir->d_name[0] != '.')
				ft_work(current, pdir->d_name, &new, sp, flag);
		}
		else
			ft_work(current, pdir->d_name, &new, sp, flag);

essai pour la recursive---------------------------------------------

		if (new->amode == 'd' && flag->R == 1)
		{
			ft_recursive(&(new->other), current, flag, sp);
//			ft_add_dir_front(base, new, flag, sp);
		}
		ft_add_file_back(base, new);

essai pour la recursive---------------------------------------------

	}
	closedir(dir);
	return (new);
}

static void		ft_job(char	*name, t_flag *flag, t_fileinfo **fileinfo, t_space *sp)
{
	t_fileinfo	*new;

	new = ft_init_fileinfo();
	if (lstat(name, &(new->st)) != 0)
	{
		write(1, "ls: ", 4);
		perror(name);
		return ;
	}
	else
		new->path = ft_strdup(name);


	if ((new->st.st_mode & S_IFMT) == S_IFDIR)
		ft_add_dir_front(&(new->other), new, flag, sp);
	else
		ft_stat(new, sp);
	ft_add_file_back(fileinfo, new);
	//penser a free new!!
}

void			ft_ls(t_flag *flag, t_fileinfo **file, t_node **arg, t_space *sp)
{
	t_node		*args;

	args = *arg;
	while (args)
	{
		ft_job(args->content, flag, file, sp);
		args = args->next;
	}
}*/
