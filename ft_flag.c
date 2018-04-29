/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_flag.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 17:07:57 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/23 13:33:50 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_usage(char c)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\n', 2);
	ft_putendl_fd("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]", 2);
//	printf("ls: illegal option -- %c\n", c);
//	printf("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n");
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
		else if (str[i] == '1')
			flag->un = 1;
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

static int	ft_test(char *s1, char *s2)
{
	if (ft_strcmp(s1, s2) == 0)
	{
		ft_usage('-');
		return (1);
	}
	return (0);
}

int			ft_flag(int ac, char **av, t_flag *flag)
{
	int		i;
	char	c;

	c = '\0';
	i = 0;
	flag->ac = ac;
	while (++i < ac)
	{
		if (av[i][0] == '-')
		{
			if (ft_strcmp(av[i], "--") == 0)
				return (0);
			if (ft_test(av[i], "---"))
				return (1);
			c = test_flag(av[i]);
			if (c != 0)
			{
				ft_usage(c);
				return (1);
			}
			else
				ft_rec(av[i], flag);
		}
	}
	return (0);
}
