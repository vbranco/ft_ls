/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_space.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/07 17:18:26 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/07 18:31:28 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_init_space(t_space *sp)
{
	sp->size_nlink = 0;
	sp->size_pname = 0;
	sp->size_gname = 0;
	sp->size_stsize = 0;
	sp->size_madev = 0;
	sp->size_midev = 0;
	sp->size_time = 0;
}
