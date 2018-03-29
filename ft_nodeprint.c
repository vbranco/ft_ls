/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_nodeprint.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/24 10:49:51 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/28 20:06:03 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_nodeprint(t_fileinfo *file)
{
	while (file)
	{
		if (file->other != NULL)
		{
			printf("other existe\n");
//			ft_nodeprint(file->other);
//			if (!file)
//				return ;
		}
		printf("%s ", file->name);
		printf("%s\n", file->pw_name);
		file = file->next;
	}
}
