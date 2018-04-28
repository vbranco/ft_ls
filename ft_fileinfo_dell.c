/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fileinfo_dell.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/28 15:11:24 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/28 15:11:25 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_fileinfo_dell(t_fileinfo **file)
{
	t_fileinfo  *tmp;

	while (*file)
	{
		tmp = (*file)->next;
		if ((*file)->other)
			ft_fileinfo_dell(&((*file)->other));
		(*file)->amode = 0;
		free((*file)->name);
		free((*file)->path);
		if ((*file)->pw_name != NULL)
			free((*file)->pw_name);
		if ((*file)->gr_name != NULL)
			free((*file)->gr_name);
		free((*file)->time);
		if ((*file)->error != NULL)
			free((*file)->error);
		free(*file);
		*file = tmp;
	}
	*file = NULL;
}
