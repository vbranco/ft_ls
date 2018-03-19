/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 17:07:23 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/19 20:00:34 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_etat_flag(t_flag *flag)
{
	printf("l : %d\n", flag->l);
	printf("R : %d\n", flag->R);
	printf("r : %d\n", flag->r);
	printf("a : %d\n", flag->a);
	printf("t : %d\n", flag->t);
}
/*
void		ft_flag_al(t_node **node, t_flag *flag, char *buf, char *content, size_t content_size)
{
	if (flag->a == 0)
	{
		if (content[0] != '.')
			ft_node_back_add(node, ft_strcat(buf, content), content_size);
	}
	else
		ft_node_back_add(node, ft_strcat(buf, content), content_size);
}

void		ft_buf(char *buf, t_format *format)
{
	ft_strcat(buf, format->umode);
	ft_strcat(buf, format->gmode);
	ft_strcat(buf, format->omode);
}

void		ft_dir(char *av, DIR *dir, struct dirent *pdir, t_flag *flag, t_node **node, int ac, t_format *format)
{
	char		*buf;
	struct stat	st;

	if (opendir(av) != NULL && (flag->l == 1 || flag->a == 1))
	{
		dir = opendir(av);
		if (ac > 3)
		{
			ft_dir_name(node, av);
		}
		while ((pdir = readdir(dir)) != NULL)
		{
			buf = ft_memalloc(200);
			ft_stat(pdir->d_name, &st, format);
			ft_buf(buf, format);
			ft_flag_al(node, flag, buf, pdir->d_name, (ft_strlen(buf) + ft_strlen(pdir->d_name)));
//			if (pdir->d_name[0] != '.')
//				ft_list_back_add(liste, ft_strcat(buf, pdir->d_name), (ft_strlen(buf) + ft_strlen(pdir->d_name)));
			free(buf);
		}
		closedir(dir);
	}
	else
	{
		buf = ft_memalloc(20);
		ft_stat(av, &st, format);
		ft_node_back_add(node, ft_strcat(buf, pdir->d_name), (ft_strlen(buf) + ft_strlen(pdir->d_name)));
		free(buf);
		return ;
	}
}

int					main(int ac, char **av)
{
	int				i;
	t_flag			flag;
	struct dirent	*pdir;
	DIR				*dir;
	t_node			*node;
	t_format		format;

	i = 1;
	ft_init_node(&node);
	ft_init_flag(&flag);
	ft_init_format(&format);
	if (ac == 1)
		ft_no_flag(".", dir, pdir, &node, ac);
	else
	{
		if (av[1][0] == '-')
		{
			ft_flag(av[1], &flag);
			i = 2;
		}
		if (ft_flag_status(&flag) == 0)//pas de flag mais plusieurs arguments
		{
			while (i < ac)
			{
				ft_no_flag(av[i], dir, pdir, &node, ac);
				if (i < ac - 1)
					ft_node_back_add(&node, "\0", 2);
				i++;
			}
		}
		else//avec des flags
		{
			if (ac == 2)
			{
				ft_dir(".", dir, pdir, &flag, &node, ac, &format);
			}
			else
			{
				while (i < ac)
				{
					ft_dir(av[i], dir, pdir, &flag, &node, ac, &format);
//					if (i < ac - 1)   ca segfault!! why??
//						ft_list_back_add(&liste, "\0", 2);
					i++;
				}
			}
		}
	}
	ft_nodeprint(node);
	ft_nodedell(node);
	return (0);
}
*/
int			main(int ac, char **av)
{
	t_flag	*flag;

//	if (ac == 1)
//		ft_no_flag(".");
//	else
		ft_flag(ac, av, flag);
		ft_etat_flag(flag);
//		ft_ls(ac, av, &flag);
	return (0);
}
