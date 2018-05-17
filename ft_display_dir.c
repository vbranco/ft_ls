/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_display_dir.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/17 16:39:34 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/17 16:39:50 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_display_dir(t_fileinfo *file, t_flag *flag, t_space *sp)
{
	while (file)
	{
		if (file->other)
			ft_file_other(file, flag, sp);
		else
			ft_file_no_other(file, flag, sp);
		file = file->next;
	}
}
