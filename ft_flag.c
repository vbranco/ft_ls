/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_flag.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 17:07:57 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/19 20:00:32 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_ret(char *str, t_flag *flag)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (av[i][z] == 'l')
			flag->l = 1;
		else if (av[i][z] == 'R')
			flag->R = 1;
		else if (av[i][z] == 'r')
			flag->r = 1;
		else if (av[i][z] == 'a')
			flag->a = 1;
		else if (av[i][z] == 't')
			flag->t = 1;
		i++;
	}
}

void		ft_flag(int ac, char **av, t_flag *flag)
{
	int		i;

	i = 2;
	while (i < ac)
	{
		if (av[i][0] == '-')
		{
			while (av[i][z])
			{
			}
		}
		i++;
	}
}
