/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_file.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/20 18:52:29 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/24 18:24:57 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_fileinfo	*ft_file(char *name, t_flag *flag, t_fileinfo **fileinfo)
{
	t_fileinfo	*new;

	new = malloc(sizeof(struct s_fileinfo));
	ft_init_fileinfo(new);
	new->name =	ft_memalloc(ft_strlen(name));
	ft_strcpy(new->name, name);
//	if (flag->l == 1)
//	{
		ft_stat(name, new);
//		free((*fileinfo)->pw_name);
//		free((*fileinfo)->gr_name);
//	}
	return (new);
//	else
//		ft_node_front_add(node, name, ft_strlen(name));
}
