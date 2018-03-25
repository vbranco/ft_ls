/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/20 16:39:39 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/24 18:25:00 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_ls(t_flag *flag, t_node **node)
{
	t_node		*args;
	t_fileinfo	fileinfo;

	args = *node;
	if (flag->ac == 1)
		ft_dir(args->content, flag, &fileinfo,  node);
	else
	{
		while (args)
		{
			if (opendir(args->content) != NULL)
				ft_dir(args->content, flag, &fileinfo, node);
			else
				ft_file(args->content, flag, &fileinfo, node);
			args = args->next;
		}
	}
}
