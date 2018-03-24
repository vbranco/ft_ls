/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_format.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/20 19:24:38 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/24 16:24:14 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_init_format(t_format *format)
{
	format->amode = '\0';
	ft_memset(format->mode, '-', 10);
	format->mode[9] = '\0';
	format->nlink = 0;
	format->pw_name = NULL;
	format->gr_name = NULL;
//	ft_memset(format->pw_name, '\0', 100);
//	ft_memset(format->gr_name, '\0', 100);
	format->st_size = 0;
//	ft_memset(format->time, '\0', 100);
	format->time = NULL;
}
