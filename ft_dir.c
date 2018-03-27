/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dir.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/20 17:11:48 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/24 18:24:58 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void			ft_open_dir(char *str, t_flag *flag, t_fileinfo **fileinfo)
{
	DIR				*dir;
	struct dirent	*pdir;
	t_fileinfo		*tmp;

	tmp = *fileinfo;
	errno = 0;
	pdir = malloc(sizeof(struct dirent));
	dir = opendir(str);
	while ((pdir = readdir(dir)) != NULL)
	{
		if (flag->a == 1)
			tmp->next = ft_file(pdir->d_name, flag, fileinfo);
		else
		{
			if (pdir->d_name[0] != '.' || flag->l == 1)
				tmp->next = ft_file(pdir->d_name, flag, fileinfo);
		}
	}
	closedir(dir);
	free(pdir);
}

void	ft_dir(char *str, t_flag *flag, t_fileinfo **fileinfo)
{
	ft_open_dir(str, flag, fileinfo);
}
