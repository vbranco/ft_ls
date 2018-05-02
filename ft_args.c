/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_args.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/28 18:01:34 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/02 12:10:56 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_empty_file(char **av, t_flag *flag)
{
	int		i;

	i = 1;
	while (i < flag->ac)
	{
		if (av[i][0] == '\0')
		{
			ft_putendl_fd("ls: fts_open: No such file or directory", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

void		ft_push_arg(t_node **node, t_flag *flag, char **av, int i)
{
	if (ft_flag_status(flag) == 0 && av[i][1] != '-')
	{
		while (i < flag->ac)
		{
			ft_node_sort_add(node, av[i], ft_strlen(av[i]));
			i++;
		}
	}
	else
	{
		i = ft_count_args(flag->ac, av);
		flag->total = i;
		if (flag->ac == i)
			ft_node_sort_add(node, ".", 1);
		else
		{
			while (i < flag->ac)
			{
				ft_node_sort_add(node, av[i], ft_strlen(av[i]));
				i++;
			}
		}
	}
}

int			ft_args(char **av, t_flag *flag, t_node **node)
{
	int		i;

	i = 1;
	if (ft_empty_file(av, flag))
		return (1);
	if (flag->ac == 1)
		ft_node_front_add(node, ".", 1);
	else
		ft_push_arg(node, flag, av, i);
	return (0);
}
