/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_flag.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 17:07:57 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 20:23:48 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_flag(char *str, t_flag *flag)
{
	int i;

	i = 0;
	str++;
	while (str[i])
	{
		if (str[i] == 'l')
			flag->l = 1;
		else if (str[i] == 'R')
			flag->R = 1;
		else if (str[i] == 'r')
			flag->r = 1;
		else if (str[i] == 'a')
			flag->a = 1;
		else if (str[i] == 't')
			flag->t = 1;
		i++;
	}
}
