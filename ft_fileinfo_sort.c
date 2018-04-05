/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fileinfo_sort.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/05 19:38:39 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/05 19:46:49 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_r(t_fileinfo **file, t_fileinfo *new)
{
	t_fileinfo	*tmp;
	t_fileinfo	*swap;

	tmp = NULL;
	swap = *node;
	while (swap->next)
	{
		if (
	}
}

void	ft_fileinfo_sort(t_fileinfo **file, t_flag flag, t_fileinfo *new)
{
	if (flag.r == 1)
		sort_r(file, new);
	else if (flag.t == 1)
		sort_t(file, new);
	else
		add_back(file, new);
}
