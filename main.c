/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 17:07:23 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/30 16:54:31 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_etat_flag(t_flag *flag)
{
	ft_printf("l : %d\n", flag->l);
	ft_printf("R : %d\n", flag->R);
	ft_printf("G : %d\n", flag->G);
	ft_printf("g : %d\n", flag->g);
	ft_printf("r : %d\n", flag->r);
	ft_printf("a : %d\n", flag->a);
	ft_printf("t : %d\n", flag->t);
	ft_printf("f : %d\n", flag->f);
	ft_printf("i : %d\n", flag->i);
	ft_printf("o : %d\n", flag->o);
	ft_printf("un : %d\n", flag->un);
}

void	argsprint(t_node *node)
{
	while (node->next)
	{
		ft_printf("%s\n", node->content);
		node = node->next;
	}
}

int ft_flag_status(t_flag *flag)
{
	if (flag->l == 1)
		return (1);
	if (flag->R == 1)
		return (1);
	if (flag->G == 1)
		return (1);
	if (flag->g == 1)
		return (1);
	if (flag->r == 1)
		return (1);
	if (flag->a == 1)
		return (1);
	if (flag->t == 1)
		return (1);
	if (flag->f == 1)
		return (1);
	if (flag->o == 1)
		return (1);
	if (flag->i == 1)
		return (1);
	if (flag->un == 1)
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	t_flag		flag;
	t_fileinfo	*file;
	t_node		*args;
	t_space		sp;

	ft_init_space(&sp);
	args = ft_init_node();
	ft_init_flag(&flag);
	file = NULL;
	if (ft_flag(ac, av, &flag) != 0)
		return (1);
	if (ft_arg(av, &flag, &args))
	{
		ft_nodedell(&args);
		return (1);
	}
//	argsprint(args);
	ft_ls(&file, &args, &flag, &sp);
	ft_nodedell(&args);
	ft_fileinfoprint(file, &flag, &sp);
	ft_fileinfo_dell(&file);
//	sleep(1500);
//	ft_etat_flag(&flag);
	return (0);
}
