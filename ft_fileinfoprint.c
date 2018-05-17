/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fileinfoprint.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/05 16:12:27 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/17 17:41:30 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_display(t_fileinfo *file, t_flag *flag, t_space *sp)
{
	if (file->error != NULL)
	{
		ft_putendl_fd(file->error, 2);
		if (file->amode != 'd' && !flag->gr)
			flag->out--;
	}
	else
	{
		if (file->name != NULL)
		{
			if (flag->l || flag->o || flag->g)
				printl(file, sp, flag);
			else
			{
				if (flag->i)
					ft_printf("%*llu ", 8, file->st.st_ino);
				if (flag->gg == 1)
					color(file);
				else
					ft_printf("%s", file->name);
				ft_printf("\n");
			}
		}
		flag->out = 1;
	}
}

void			ft_pdir(t_fileinfo *file, t_flag *flag, t_space *sp)
{
	t_fileinfo	*tmp;

	tmp = file;
	flag->out = 1;
	if ((flag->l || flag->o || flag->g) && file->error == NULL
			&& file->name != NULL)
		ft_printf("total %i\n", ft_total(file));
	while (file)
	{
		ft_display(file, flag, sp);
		file = file->next;
	}
	file = tmp;
	if (flag->gr)
		ft_display_dir(file, flag, sp);
}

void			ft_file_other(t_fileinfo *file, t_flag *flag, t_space *sp)
{
	if (flag->out > 0)
		ft_printf("\n%s:\n", file->path);
	else
	{
		if (ft_flag_status(flag) == 0 && flag->ac > 2)
			ft_printf("%s:\n", file->path);
		if (ft_flag_status(flag) != 0)
		{
			if (flag->ac - flag->total > 1)
				ft_printf("%s:\n", file->path);
		}
	}
	ft_pdir(file->other, flag, sp);
}

void			ft_file_no_other(t_fileinfo *file, t_flag *flag)
{
	if (file->amode == 'd' && file->mode[2] == '-' && file->mode[0] == 'r')
	{
		if (!flag->out)
		{
			if ((ft_flag_status(flag) != 0 && flag->ac - 1 > flag->total) ||
				(ft_flag_status(flag) == 0 && flag->ac > flag->total + 2))
			{
				flag->out = 1;
				ft_printf("%s:\n", file->name);
			}
		}
		else
		{
			flag->out = 1;
			ft_printf("\n%s:\n", file->name);
		}
	}
}

void			ft_fileinfoprint(t_fileinfo *file, t_flag *flag, t_space *sp)
{
	t_fileinfo	*tmp;
	short int	i;
	short int	d;

	i = 0;
	d = 0;
	tmp = file;
	while (tmp)
	{
		if (tmp->amode != 'd')
		{
			ft_display(tmp, flag, sp);
			i++;
		}
		if (tmp->amode == 'd')
			d++;
		tmp = tmp->next;
	}
	if (i > 0 && d > 0)
		flag->out++;
	ft_display_dir(file, flag, sp);
}
