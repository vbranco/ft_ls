/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 17:07:23 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/23 15:06:53 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_etat_flag(t_flag *flag)
{
	printf("l : %d\n", flag->l);
	printf("R : %d\n", flag->R);
	printf("r : %d\n", flag->r);
	printf("a : %d\n", flag->a);
	printf("t : %d\n", flag->t);
}

void	argsprint(t_node *node)
{
	while (node)
	{
		printf("%s\n", node->content);
		node = node->next;
	}
}

int		main(int ac, char **av)
{
	t_flag		flag;
	t_fileinfo	*file;
	t_node		*args;
	t_space		sp;

	ft_init_space(&sp);
	ft_init_node(args);
	ft_init_flag(&flag);
	file = ft_init_fileinfo();
	file = NULL;
	if (ft_flag(ac, av, &flag) != 0)
		return (1);
//	printf("%i\n", flag.ac);
	if (ft_args(av, &flag, &args))
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
