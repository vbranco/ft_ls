/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fileinfoprint.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/05 16:12:27 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/07 18:31:39 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static int	test(t_fileinfo *file)
{
	if (file->amode == 'd')
	{
		if (file->mode[7] == 'w')
		{
			if (file->mode[8] == 't' || file->mode[8] == 'T')
				return (10);
			else
				return (11);
		}
		else
			return (1);
	}
	else if (file->amode == '-')
	{
		if (file->mode[2] == 's')
			return (8);
		else if (file->mode[2] == 'S')
			return (9);
		else if (file->mode[2] != '-' || file->mode[5] != '-' || file->mode[8] != '-')
			return (5);
	}
	return (0);
}

static void	color(t_fileinfo *file)
{
	if (test(file) == 1)
		printf("%s%s%s", TCYAN, file->name, TSTOP);
	else if (file->amode == 'l')
		printf("%s%s%s", TMAGENTA, file->name, TSTOP);
	else if (file->amode == 's')
		printf("%s%s%s", TGREEN, file->name, TSTOP);
	else if (file->amode == 'p')
		printf("%s%s%s", TYELLOW, file->name, TSTOP);
	else if (file->amode == 'b')
		printf("%s%s%s%s", TBLUE, BCYAN, file->name, TSTOP);
	else if (file->amode == 'c')
		printf("%s%s%s%s", TBLUE, BYELLOW, file->name, TSTOP);
	else if (test(file) == 5)
		printf("%s%s%s", TRED, file->name, TSTOP);
	else if (test(file) == 8)
		printf("%s%s%s%s", TBLACK, BRED, file->name, TSTOP);
	else if (test(file) == 9)
		printf("%s%s%s%s", TBLACK, BCYAN, file->name, TSTOP);
	else if (test(file) == 10)
		printf("%s%s%s%s", TBLACK, BGREEN, file->name, TSTOP);
	else if (test(file) == 11)
		printf("%s%s%s%s", TBLACK, BYELLOW, file->name, TSTOP);
	else
		printf("%s", file->name);
}

static void	printl(t_fileinfo *file, t_space *sp, t_flag flag)
{
	printf("%c%s %*i %-*s  %-*s  ", file->amode, file->mode, sp->size_nlink,
	file->st.st_nlink, sp->size_pname, file->pw_name, sp->size_gname, file->gr_name);
	if (file->amode == 'b' || file->amode == 'c')
		printf(" %*i, %*i ", sp->size_madev, file->maj, sp->size_midev, file->min);
	else
	{
		if (sp->size_midev != 0 || sp->size_madev != 0)
			printf("%*lli ", (sp->size_madev + sp->size_midev + sp->size_stsize+2),
			file->st.st_size);
		else
			printf("%*lli ", (sp->size_stsize), file->st.st_size);
	}
	printf("%s ", file->time);
	if (flag.l == 1)
		color(file);
	else
		printf("%s", file->name);
	if (file->amode == 'l')
	{
		printf(" -> %s\n", file->link);
	}
	else
		printf("\n");
}

static int	ft_total(t_fileinfo *file)
{
	int		total;

	total = 0;
	while (file)
	{
		total += file->total;
		file = file->next;
	}
	return (total);
}

void		ft_fileinfoprint(t_fileinfo *file, t_flag flag, t_space *sp)
{
	if (!file)
		return ;
	if (file->other)
	{
		printf("\n");//pas encore au point
		printf("%s:\n", file->path);//pas encore au point
		if (flag.l > 0)
		{
			printf("total %i\n", ft_total(file->other));
		}
		ft_fileinfoprint(file->other, flag, sp);
		printf("\n");//pas encore au point
	}
	if (flag.l > 0)
		printl(file, sp, flag);
	else
	{
		if (flag.l == -1)
			color(file);
		else
			printf("%s", file->name);
		printf("\n");
	}
	if (file->next)
		ft_fileinfoprint(file->next, flag, sp);
}
