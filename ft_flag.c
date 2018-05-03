/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_flag.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 17:07:57 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/30 16:54:27 by vbranco     ###    #+. /#+    ###.fr     */
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
}

static void	ft_rec(char *str, t_flag *flag)
{
	int		i;

	i = 0;
	while (str[i])
	{
		((str[i] == 'l')) ? flag->l = 1 : 0;
		((str[i] == 'G')) ? flag->G = 1 : 0;
		((str[i] == 'R')) ? flag->R = 1 : 0;
		((str[i] == 'g')) ? flag->g = 1 : 0;
		((str[i] == 'r')) ? flag->r = 1 : 0;
		((str[i] == 'a')) ? flag->a = 1 : 0;
		((str[i] == 't')) ? flag->t = 1 : 0;
		((str[i] == 'o')) ? flag->o = 1 : 0;
		((str[i] == 'i')) ? flag->i = 1 : 0;
		((str[i] == '1')) ? flag->un = 1 : 0;
		if (str[i] == 'f')
		{
			 flag->f = 1;
			 flag->a = 1;
		}
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
		if (av[i][0] != '-')
			break;
	}
	return (0);
}
