/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_args.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/28 18:01:34 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/28 18:23:26 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void            ft_args(char **av, t_flag *flag, t_node **node)
{
	int     i;

	i = 1;
	if (flag->ac == 1)
		ft_node_front_add(node, ".", 1);
	else
	{
		if (ft_flag_status(flag) == 0)
		{
			while (i < flag->ac)
			{
				ft_node_front_add(node, av[i], ft_strlen(av[i]));
				i++;
			}
		}
		else
		{
			i = ft_count_args(flag->ac, av);
			while (i < flag->ac)
			{
				ft_node_front_add(node, av[i], ft_strlen(av[i]));
				i++;
			}

		}
	}
}
