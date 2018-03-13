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

void		ft_dir(char *av, DIR *dir, struct dirent *pdir, t_flag *flag)
{
	char		*buf;
	struct stat	st;

	if (opendir(av) != NULL && flag->l == 1)
	{
		dir = opendir(av);
		while ((pdir = readdir(dir)) != NULL)
		{
			buf = ft_memalloc(20);
			ft_stat(buf, pdir->d_name, &st);
			free(buf);
			printf("  %s\n", pdir->d_name);
		}
		closedir(dir);
	}
	else
	{
		buf = ft_memalloc(20);
		ft_stat(buf, av, &st);
		free(buf);
		printf("  %s\n", av);
		return ;
	}
}

void	ft_list(char *av, DIR *dir, struct dirent *pdir)
{
	dir = opendir(av);
	while ((pdir = readdir(dir)) != NULL)
	{
		if (pdir->d_name[0] != '.')
				printf("%s	", pdir->d_name);
	}
	printf("\n");
}

int					main(int ac, char **av)
{
	int				i;
	t_flag			flag;
	struct dirent	*pdir;
	DIR				*dir;

	i = 1;
	ft_init_flag(&flag);
	if (ac == 1)
		ft_list(".", dir, pdir);
	else
	{
		if (av[1][0] == '-')
			ft_flag(av[1], &flag);
		if (ft_no_flag(&flag) == 0)
		{
			while (i < ac)
			{
				ft_list(av[i], dir, pdir);
				i++;
			}
		}
		else
		{
			while (i < ac)
			{
				ft_dir(av[i], dir, pdir, &flag);
				i++;
			}
		}
	}
	return (0);
}
