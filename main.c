/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 17:07:23 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 20:06:29 by vbranco     ###    #+. /#+    ###.fr     */
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

void		ft_dir(char *av, DIR *dir, struct dirent *pdir, t_flag *flag, t_list **liste, int ac)
{
	char		*buf;
	struct stat	st;
	int		i;

	i = 2;
	if (opendir(av) != NULL && flag->l == 1)
	{
		dir = opendir(av);
		if (ac > 3)
		{
			if (i < ac - 1 && i > 1)
				ft_list_back_add(liste, "\0", 2);
			ft_dir_name(liste, av);
		}
		while ((pdir = readdir(dir)) != NULL)
		{
			buf = ft_memalloc(20);
			ft_stat(buf, pdir->d_name, &st);
			ft_list_back_add(liste, ft_strcat(buf, pdir->d_name), (ft_strlen(buf) + ft_strlen(pdir->d_name)));
			free(buf);
			i++;
		}
		closedir(dir);
	}
	else
	{
		buf = ft_memalloc(20);
		ft_stat(buf, av, &st);
		ft_list_back_add(liste, ft_strcat(buf, pdir->d_name), (ft_strlen(buf) + ft_strlen(pdir->d_name)));
		free(buf);
		return ;
	}
}

void	ft_list(char *av, DIR *dir, struct dirent *pdir, t_list **liste, int ac)
{
	dir = opendir(av);
	if (ac > 2)
		ft_dir_name(liste, av);
	while ((pdir = readdir(dir)) != NULL)
	{
		if (pdir->d_name[0] != '.')
		{
			ft_list_back_add(liste, pdir->d_name, ft_strlen(pdir->d_name));
		}
	}
	closedir(dir);
}

void	ft_freelst(t_list *liste)
{
	while (liste->next)
	{
		free(liste->content);
		free(liste);
		liste = liste->next;
	}
}

int					main(int ac, char **av)
{
	int				i;
	t_flag			flag;
	struct dirent	*pdir;
	DIR				*dir;
	t_list			*liste;

	i = 1;
	ft_init_flag(&flag);
	ft_init_list(&liste);
	if (ac == 1)
		ft_list(".", dir, pdir, &liste, ac);
	else
	{
		if (av[1][0] == '-')
		{
			ft_flag(av[1], &flag);
			i = 2;
		}
		if (ft_no_flag(&flag) == 0)//pas de flag mais plusieurs arguments
		{
			while (i < ac)
			{
				ft_list(av[i], dir, pdir, &liste, ac);
				if (i < ac - 1)
					ft_list_back_add(&liste, "\0", 2);
				i++;
			}
		}
		else//avec des flags
		{
			if (ac == 2)
			{
				ft_dir(".", dir, pdir, &flag, &liste, ac);
			}
			else
			{
				while (i < ac)
				{
					ft_dir(av[i], dir, pdir, &flag, &liste, ac);
//					if (i < ac - 1)
//						ft_list_front_add(&liste, "\0", 1);
			/*		if (flag.R == 1)
					{
						ft_recursive(&liste);
					}
			*/		i++;
				}
			}
		}
	}
	ft_lstprint(liste);
	ft_listdell(liste);
	return (0);
}
