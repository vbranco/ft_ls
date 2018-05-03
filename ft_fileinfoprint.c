/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fileinfoprint.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/05 16:12:27 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/24 17:15:08 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_display(t_fileinfo *file, t_flag *flag, t_space *sp)
{
	if (file->error != NULL)
	{
		ft_putendl_fd(file->error, 2);
		if (file->amode != 'd' && !flag->R)
			flag->out--;
	}
	else
	{
		if (file->name != NULL)
		{
			if (flag->l || flag->o || flag->g)
			{
				printl(file, sp, flag);
			}
			else
			{
				if (flag->i)
					printf("%*llu ", 8, file->st.st_ino);
				if (flag->G == 1)
					color(file);
				else
					printf("%s", file->name);
				printf("\n");
			}
		}
		flag->out = 1;
	}
}

void		ft_pdir(t_fileinfo *file, t_flag *flag, t_space *sp)
{
	t_fileinfo	*tmp;

	tmp = file;
	flag->out = 1;
	if ((flag->l || flag->o || flag->g) && file->error == NULL && file->name != NULL)
		printf("total %i\n", ft_total(file));
	while (file)
	{
		ft_display(file, flag, sp);
		file = file->next;
	}
	file = tmp;
	if (flag->R)
		ft_display_dir(file, flag, sp);

}

void	ft_display_dir(t_fileinfo *file, t_flag *flag, t_space *sp)
{
	while (file)
	{
		if (file->other)
		{
			if (flag->out > 0)
				printf("\n%s:\n", file->path);
			else
			{
				if (ft_flag_status(flag) == 0 && flag->ac > 2)
					printf("%s:\n", file->path);
				if (ft_flag_status(flag) != 0)
				{
					if (flag->ac - flag->total > 1)
						printf("%s:\n", file->path);
				}
			}
			ft_pdir(file->other, flag, sp);
		}
		else
		{
			if (file->amode == 'd' && file->mode[2] == '-' && file->mode[0] == 'r')
			{
				if (!flag->out)
				{
					if ((ft_flag_status(flag) != 0 && flag->ac - 1 > flag->total) || (ft_flag_status(flag) == 0 && flag->ac > flag->total + 2))
					{
						flag->out = 1;
						printf("%s:\n", file->name);
					}
				}
				else
				{
					flag->out = 1;
					printf("\n%s:\n", file->name);
				}
			}
		}
		file = file->next;
	}
}

void		ft_fileinfoprint(t_fileinfo *file, t_flag *flag, t_space *sp)
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
