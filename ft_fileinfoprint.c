/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fileinfoprint.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/05 16:12:27 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/05 19:47:05 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void	printl(t_fileinfo *file)
{
		printf("%s ", file->name);
		printf("%s ", file->pw_name);
		printf(" %i, ", major(file->st.st_rdev));
		printf("%i \n", minor(file->st.st_rdev));
}

void		ft_fileinfoprint(t_fileinfo *file, t_flag flag)
{
	unsigned int	total;

	total = 0;
	while (file)
	{
		if (file->other != NULL)
		{
//			printf("other existe\n");
			ft_fileinfoprint(file->other, flag);
			if (!file)
				return ;
		}
//		total += file->total;
//		printf("%u\n", total);
		if (flag.l == 1)
			printl(file);
		else
			printf("%s\n", file->name);
		file = file->next;
	}
}
