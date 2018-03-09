/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 17:07:23 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 20:23:42 by vbranco     ###    #+. /#+    ###.fr     */
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
//		printf("c'est un dossier");
		dir = opendir(av);
		while ((pdir = readdir(dir)) != NULL)
		{
//			ft_init_stat(&st);
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
//	ft_stat(pdir->d_name);
//	ft_dir(pdir->d_name, dir, pdir);
//	while ((pdir = readdir(dir)) != NULL)
//		ft_dir(pdir->d_name, dir, pdir);
/*	while ((pdir = readdir(dir)) != NULL)
	{
		printf("[%s]\n", pdir->d_name);
	}
	*/
}
int		main(int ac, char **av)
{
	int		i;
	t_flag		flag;
//	struct stat	stat;
	struct dirent	*pdir;
	DIR		*dir;

	i = 1;
	ft_init(&flag);
	while (i < ac)
	{
		if (ft_strchr(av[i], '-') != 0 && av[i][1] != '\0')
			ft_flag(av[i], &flag);
		ft_dir(av[i], dir, pdir, &flag);
		i++;
	}
//	ft_etat_flag(&flag);
//	ft_dir(av[1], dir, pdir);
	return (0);
}
