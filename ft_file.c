/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_file.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/20 18:52:29 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/24 18:24:57 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_cat(char *buf, t_fileinfo *fileinfo)
{
	char	s[2];
	char	*nlin;
	char	*siz;

	nlin = ft_itoa(fileinfo->nlink);
	siz = ft_itoa(fileinfo->st_size);
	s[0] = fileinfo->amode;
	s[1] = '\0';
	ft_strcat(buf, s);
	ft_strcat(buf, fileinfo->mode);
	ft_strcat(buf, "  ");
	ft_strcat(buf, nlin);
	ft_strcat(buf, "  ");
	ft_strcat(buf, fileinfo->pw_name);
	ft_strcat(buf, "  ");
	ft_strcat(buf, fileinfo->gr_name);
	ft_strcat(buf, "  ");
	ft_strcat(buf, siz);
	ft_strcat(buf, "  ");
	ft_strcat(buf, fileinfo->time);
	ft_strcat(buf, "  ");
	free(nlin);
	free(siz);
}

void	ft_file(char *name, t_flag *flag, t_fileinfo *fileinfo, t_node **node)
{
	char	*buf;

	if (flag->l == 1)
	{
		ft_init_fileinfo(fileinfo);
		ft_stat(name, fileinfo);
		buf = ft_memalloc(2 + 10 + 4 + ft_strlen(fileinfo->pw_name) + ft_strlen(fileinfo->gr_name) + 4 + ft_strlen(fileinfo->time));
		ft_cat(buf, fileinfo);
		ft_strcat(buf, name);
		ft_node_front_add(node, buf, ft_strlen(buf));
		free(buf);
		//		free(fileinfo->time);
		free(fileinfo->pw_name);
		free(fileinfo->gr_name);
	}
	else
		ft_node_front_add(node, name, ft_strlen(name));
}
