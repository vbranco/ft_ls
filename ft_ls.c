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

void			ft_ls(t_flag *flag, t_fileinfo **file, t_node **arg)
{
//	t_fileinfo		*file;
	t_node			*args;

	args = *arg;
	if (flag->ac == 1)
		ft_dir(args->content, flag, file);
	else
	{
		while (args)
		{
			if (opendir(args->content) != NULL)
				ft_dir(args->content, flag, file);
			else
				ft_file(args->content, flag, file);
			args = args->next;
		}
	}
}
