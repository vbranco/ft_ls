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

static void		ft_work(char *directory, char *name, t_fileinfo **fileinfo, t_space *sp, t_flag *flag)
{
	t_fileinfo	*new;
	char		*path;

	path = ft_memalloc(ft_strlen(directory) + ft_strlen(name) + 2);
	ft_strcat(path, directory);
	ft_strcat(path, "/");
	ft_strcat(path, name);
	new = ft_init_fileinfo();
//	nom(new, name);
	if (ft_stat(path, new, sp) == 1)
		return ;
	ft_fileinfo_sort(fileinfo, new, flag);
	free(path);
}

t_fileinfo		*ft_add_dir_front(t_fileinfo **file, t_fileinfo *current, t_flag *flag, t_space *sp)
{
	t_fileinfo		*new;
	DIR				*dir;
	struct dirent	*pdir;

	errno = 0;
	new = ft_init_fileinfo();
	if ((dir = opendir(current->name)) == NULL)
		perror("opendir() error\n");
	while ((pdir = readdir(dir)) != NULL)
	{
//		printf("%s\n", current->name);
		if (flag->a == 0)
		{
			if (pdir->d_name[0] != '.')
				ft_work(current->name, pdir->d_name, &new, sp, flag);
		}
		else
			ft_work(current->name, pdir->d_name, &new, sp, flag);
	}
	closedir(dir);
	return (new);
}

static void		ft_job(char	*name, t_flag *flag, t_fileinfo **fileinfo, t_space *sp)
{
	t_fileinfo	*new;

	new = ft_init_fileinfo();
	ft_stat(name, new, sp);
	if ((new->st.st_mode & S_IFMT) == S_IFDIR)
	{
		ft_add_file_back(fileinfo, new);
		new->other = ft_add_dir_front(fileinfo, new, flag, sp);
	}
	else
	{
		ft_add_file_back(fileinfo, new);
	}
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
}
