/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 17:07:23 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/07 18:31:34 by vbranco     ###    #+. /#+    ###.fr     */
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

void	ft_fileinfodell(t_fileinfo **file)
{
	t_fileinfo	*tmp;

	while (*file)
	{
		tmp = *file;
		if ((*file)->other)
			ft_fileinfodell(&(*file)->other);
		(*file)->amode = 0;
		free((*file)->name);
		free((*file)->path);
		free((*file)->pw_name);
		free((*file)->gr_name);
		free((*file)->time);
		free(*file);
		*file = tmp->next;
	}
	*file = NULL;
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
	ft_args(av, &flag, &args);
//	argsprint(args);
	ft_ls(&flag, &file, &args, &sp);
//	argsprint(args);
	ft_nodedell(&args);
	ft_fileinfoprint(file, flag, &sp);
	ft_fileinfodell(&file);
//	sleep(1500);
//	ft_etat_flag(&flag);
	return (0);
}
