/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_flag_status.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/20 16:38:25 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/20 19:05:43 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_flag_status(t_flag *flag)
{
	if (flag->l == 1)
		return (1);
	if (flag->R == 1)
		return (1);
	if (flag->r == 1)
		return (1);
	if (flag->a == 1)
		return (1);
	if (flag->t == 1)
		return (1);
	return (0);
}
