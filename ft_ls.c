/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/20 16:39:39 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/21 19:59:15 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_count_args(int ac, char **av)
{
	int		i;
	int		z;

	i = 1;
	z = 0;
	while (i < ac)
	{
		if (av[i][0] == '-')
			z++;
		i++;
	}
	return (z + 1);
}

void		ft_ls(char **av, t_flag *flag, t_node **node)
{
	int		i;

	i = 1;
	if (flag->ac == 1)
		ft_dir(".", flag, node);
	else
	{
		if (ft_flag_status(flag) == 0)
		{
			while (i < flag->ac)
			{
				ft_dir(av[i], flag, node);
				i++;
			}
		}
		else
		{
			i = ft_count_args(flag->ac, av);
			while (i < flag->ac)
			{
				ft_dir(av[i], flag, node);
				i++;
			}
		}
	}
}
