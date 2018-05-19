/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 17:07:23 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/19 14:03:48 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_flag_status(t_flag *flag)
{
	if (flag->l == 1)
		return (1);
	if (flag->gr == 1)
		return (1);
	if (flag->gg == 1)
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
	ft_ls(&file, &args, &flag, &sp);
	ft_nodedell(&args);
	ft_fileinfoprint(file, &flag, &sp);
	ft_fileinfo_dell(&file);
	return (0);
}
