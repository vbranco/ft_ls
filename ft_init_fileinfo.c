/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_fileinfo.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/28 18:17:44 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/07 18:31:25 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_fileinfo	*ft_init_fileinfo(void)
{
	t_fileinfo	*fileinfo;

	fileinfo = NULL;
	fileinfo = malloc(sizeof(t_fileinfo));
	fileinfo->amode = 0;
	fileinfo->name = NULL;
	fileinfo->path = NULL;
	ft_memset(fileinfo->mode, '-', 10);
	fileinfo->mode[9] = ' ';
	fileinfo->mode[10] = '\0';
	fileinfo->pw_name = NULL;
	fileinfo->gr_name = NULL;
	fileinfo->time = NULL;
	ft_bzero(fileinfo->link, PATH_MAX);
	fileinfo->min = 0;
	fileinfo->maj = 0;
	fileinfo->total = 0;
	fileinfo->next = NULL;
	fileinfo->other = NULL;
	return (fileinfo);
}
