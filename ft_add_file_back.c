/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_add_file_back.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/30 16:09:15 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/30 16:54:56 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_add_file_back(t_fileinfo **file, t_fileinfo *novo)
{
	t_fileinfo	*tmp;

	tmp = *file;
	if (!tmp)
	{
		novo->next = *file;
		*file = novo;
	}
	else
	{
		novo->next = NULL;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = novo;
	}
}
