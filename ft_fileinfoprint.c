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

static void	printl(t_fileinfo *file, t_space *sp)
{
	printf("%c%s  %*i %-*s  %-*s  ", file->amode, file->mode, sp->size_nlink,
	file->st.st_nlink, sp->size_pname, file->pw_name, sp->size_gname, file->gr_name);
	if (file->amode == 'b' || file->amode == 'c')
		printf(" %*i, %*i ", sp->size_madev, file->maj, sp->size_midev, file->min);
	else
	{
		if (sp->size_midev != 0 || sp->size_madev != 0)
			printf("%*lli ", (sp->size_madev + sp->size_midev + sp->size_stsize-1),
			file->st.st_size);
		else
			printf("%*lli ", (sp->size_stsize), file->st.st_size);
	}
	printf("%s %s", file->time, file->name);
	if (file->amode == 'l')
	{
		printf(" -> %s\n", file->link);
	}
	else
		printf("\n");
}

void		ft_fileinfoprint(t_fileinfo *file, t_flag flag, t_space *sp)
{
	unsigned int	total;

	total = 0;
	while (file)
	{
		if (file->other)
		{
			ft_fileinfoprint(file->other, flag, sp);
		}
		if (!file)
			return ;
		if (flag.l == 1)
			printl(file, sp);
		else
			printf("%s\n", file->name);
		file = file->next;
	}
}
