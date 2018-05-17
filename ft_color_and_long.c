/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_color_and_long.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/15 11:38:35 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/17 17:40:09 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static int	test(t_fileinfo *f)
{
	if (f->amode == 'd')
	{
		if (f->mode[7] == 'w')
		{
			if (f->mode[8] == 't' || f->mode[8] == 'T')
				return (10);
			else
				return (11);
		}
		else
			return (1);
	}
	else if (S_ISREG(f->st.st_mode))
	{
		if (f->mode[2] == 's')
			return (8);
		else if (f->mode[5] == 's')
			return (9);
		else if (f->mode[2] != 'x' && f->mode[5] != 'x' && f->mode[8] != 'x')
			return (0);
		else if (f->mode[2] != '-' || f->mode[5] != '-' ||
				f->mode[8] != '-')
			return (5);
	}
	return (0);
}

void		color(t_fileinfo *file)
{
	if (test(file) == 1)
		ft_printf("%s%s%s", TCYAN, file->name, TSTOP);
	else if (file->amode == 'l')
		ft_printf("%s%s%s", TMAGENTA, file->name, TSTOP);
	else if (file->amode == 's')
		ft_printf("%s%s%s", TGREEN, file->name, TSTOP);
	else if (file->amode == 'p')
		ft_printf("%s%s%s", TYELLOW, file->name, TSTOP);
	else if (file->amode == 'b')
		ft_printf("%s%s%s%s", TBLUE, BCYAN, file->name, TSTOP);
	else if (file->amode == 'c')
		ft_printf("%s%s%s%s", TBLUE, BYELLOW, file->name, TSTOP);
	else if (test(file) == 5)
		ft_printf("%s%s%s", TRED, file->name, TSTOP);
	else if (test(file) == 8)
		ft_printf("%s%s%s%s", TBLACK, BRED, file->name, TSTOP);
	else if (test(file) == 9)
		ft_printf("%s%s%s%s", TBLACK, BCYAN, file->name, TSTOP);
	else if (test(file) == 10)
		ft_printf("%s%s%s%s", TBLACK, BGREEN, file->name, TSTOP);
	else if (test(file) == 11)
		ft_printf("%s%s%s%s", TBLACK, BYELLOW, file->name, TSTOP);
	else
		ft_printf("%s", file->name);
}

void		flag_o_g(t_fileinfo *file, t_space *sp, t_flag *flag)
{
	if (flag->l && !flag->o && !flag->g)
		ft_printf("%-*s  %-*s  ", sp->size_pname, file->pw_name,
				sp->size_gname, file->gr_name);
	else
	{
		if (flag->o && !flag->g)
			ft_printf("%-*s  ", sp->size_pname, file->pw_name);
		else if (!flag->o && flag->g)
			ft_printf("%-*s  ", sp->size_gname, file->gr_name);
		else
			ft_printf("  ");
	}
}

void		printl(t_fileinfo *file, t_space *sp, t_flag *flag)
{
	((flag->i)) ? ft_printf("%llu ", file->st.st_ino) : 0;
	ft_printf("%c%s %*i ", file->amode, file->mode, sp->size_nlink,
			file->st.st_nlink);
	flag_o_g(file, sp, flag);
	if (file->amode == 'b' || file->amode == 'c')
		ft_printf(" %*i, %*i ", sp->size_madev, file->maj, sp->size_midev,
				file->min);
	else
	{
		if (sp->size_midev != 0 || sp->size_madev != 0)
			ft_printf("%*lli ", (sp->size_madev + sp->size_midev +
						sp->size_stsize - 1),
					file->st.st_size);
		else
			ft_printf("%*lli ", (sp->size_stsize), file->st.st_size);
	}
	ft_printf("%s ", file->time);
	if (flag->gg == 1)
		color(file);
	else
		ft_printf("%s", file->name);
	if (file->amode == 'l')
		ft_printf(" -> %s\n", file->link);
	else
		ft_printf("\n");
}

int			ft_total(t_fileinfo *file)
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
