/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_fileinfo.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/28 18:17:44 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/28 18:23:07 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_fileinfo	*ft_init_fileinfo(void)
{
	t_fileinfo	*fileinfo;

	fileinfo = malloc(sizeof(t_fileinfo));
	fileinfo->amode = 0;
	fileinfo->name = NULL;
	ft_memset(fileinfo->mode, '-', 10);
	fileinfo->mode[9] = '\0';
	fileinfo->nlink = 0;
	fileinfo->pw_name = NULL;
	fileinfo->gr_name = NULL;
	fileinfo->st_size = 0;
	fileinfo->time = 0;
	fileinfo->next = NULL;
	fileinfo->other = NULL;
	return (fileinfo);
}
