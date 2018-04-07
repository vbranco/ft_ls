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
	printf("%c", file->amode);
	printf("%s  ", file->mode);
	printf("%*i ", sp->size_nlink, file->st.st_nlink);
	printf("%-*s  ", sp->size_pname, file->pw_name);
	printf("%-*s  ", sp->size_gname, file->gr_name);
	if (file->amode == 'b' || file->amode == 'c')
	{
		printf(" %*i, ", sp->size_madev, file->maj);
		printf("%*i ", sp->size_midev, file->min);
	}
	else
		printf("%*lli ", sp->size_stsize, file->st.st_size);
//	printf(">>>%s<<<", ctime(&file->st.st_mtime));
//	printf("time >> %ld<<", time(NULL));
//	printf("   time modif >>%li<<", file->st.st_mtime);
//	if (time(NULL) - file->st.st_mtime > 15778800)
//		printf(" plus de 6 mois");
//	else
	printf("%s ", file->time);
	printf("%s", file->name);
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
			//			printf("other existe\n");
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
