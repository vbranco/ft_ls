/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 17:07:23 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/24 18:25:01 by vbranco     ###    #+. /#+    ###.fr     */
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

int		main(int ac, char **av)
{
	t_flag		flag;
	t_fileinfo	*file;
	t_node		*args;

	file = malloc(sizeof(struct s_fileinfo));
	ft_init_node(&args);
	ft_init_flag(&flag);
	ft_init_fileinfo(file);
	ft_flag(ac, av, &flag);
	ft_args(av, &flag, &args);
	ft_ls(&flag, &file, &args);
	ft_nodeprint(file);
//	ft_nodedell(node);
	//	ft_etat_flag(&flag);
	return (0);
}
