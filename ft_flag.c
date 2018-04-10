/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_flag.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 17:07:57 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/20 19:46:04 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_usage(char c)
{
	printf("ft_ls: illegal option -- %c\n", c);
	printf("usage: ./ft_ls [-GRalrt] [file ...]\n");
}

static void	ft_rec(char *str, t_flag *flag)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'l')
			flag->l += 2;
		else if (str[i] == 'G')
			flag->l -= 1;
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

static int	test_flag(char *str)
{
	int		i;

	i = 0;
	while (str[i++])
	{
		if (ft_strchr(FLAGS, str[i]) == 0)
			return (str[i]);
	}
	return (0);
}

int			ft_flag(int ac, char **av, t_flag *flag)
{
	int		i;
	char	c;

	c = '\0';
	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-')
		{
			c = test_flag(av[i]);
			if (c != 0)
			{
				ft_usage(c);
				return (1);
			}
			else
				ft_rec(av[i], flag);
		}
		i++;
	}
	flag->ac = ac;
	return (0);
}
