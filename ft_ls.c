/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/20 16:39:39 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/28 20:05:58 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_add_file_front(t_fileinfo **fileinfo, t_fileinfo *new)
{
	new->next = *fileinfo;
	*fileinfo = new;
}

void	ft_work(char *name, t_fileinfo **novo)
{
	t_fileinfo	*new;

	ft_init_fileinfo(new);
	ft_stat(name, new);
//	ft_add_file_front(novo, new);
}

t_fileinfo		*ft_add_dir_front(t_fileinfo **fileinfo, t_fileinfo *new)
{
	t_fileinfo	*novo;
	DIR			*dir;
	struct dirent	*pdir;

	ft_init_fileinfo(novo);
	pdir = malloc(sizeof(struct dirent));
	dir = opendir(new->name);
	while ((pdir = readdir(dir)) != NULL)
	{
		ft_work(pdir->d_name, &novo);
	}
	closedir(dir);
	free(pdir);
//	ft_add_file_front(fileinfo, new);
	return (novo);
}


static void		ft_job(char	*name, t_flag *flag, t_fileinfo **fileinfo)
{
	t_fileinfo	*new;

	new = malloc(sizeof(t_fileinfo));
	ft_init_fileinfo(new);
	ft_stat(name, new);
	if ((new->st.st_mode & S_IFMT) == S_IFDIR)
	{
//		ft_add_file_front(fileinfo, new);
		new->other = ft_add_dir_front(fileinfo, new);
	}
	else
	{
		ft_add_file_front(fileinfo, new);
	}
}

void			ft_ls(t_flag *flag, t_fileinfo **file, t_node **arg)
{
	t_node			*args;

	args = *arg;
	while (args)
	{
		ft_job(args->content, flag, file);
		args = args->next;
	}
}
