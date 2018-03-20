/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dir.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/20 17:11:48 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/20 19:56:43 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_open_dir(char *str, t_flag *flag, t_format *format, t_node **node)
{
	DIR				*dir;
	struct dirent	*pdir;

	if (opendir(str) != NULL)
	{
		dir = opendir(str);
		while ((pdir = readdir(dir)) != NULL)
		{
			if (flag->a == 1)
			{
				ft_file(pdir->d_name, flag, format, node);
			}
	//		else if (flag->l == 1)
	//		{
//			faire un espece while qui choisi la bonne fonction en rapport avec les flags.
//			}
			else
			{
				if (pdir->d_name[0] != '.')
					ft_file(pdir->d_name, flag, format, node);
			}
		}
		closedir(dir);
	}
	else
	{
		perror("impossible d'ouvrir le dossier!!!");
	}
}

void	ft_dir(char *str, t_flag *flag, t_node **node)
{
	t_format	format;

	ft_init_format(&format);
	ft_open_dir(str, flag, &format, node);
}
