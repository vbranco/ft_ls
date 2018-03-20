/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_format.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/20 19:24:38 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/20 19:56:44 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_init_format(t_format *format)
{
	format->mode = '\0';
	format->umode[3] = '\0';
	format->gmode[3] = '\0';
	format->omode[3] = '\0';
	ft_memset(format->umode, '-', 3);
	ft_memset(format->gmode, '-', 3);
	ft_memset(format->omode, '-', 3);
	format->nlink = 0;
	ft_memset(format->pw_name, '\0', 100);
	ft_memset(format->gr_name, '\0', 100);
	format->st_size = 0;
	ft_memset(format->time, '\0', 100);
}
