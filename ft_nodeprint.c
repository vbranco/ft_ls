/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_nodeprint.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/24 10:49:51 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/24 18:24:54 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_nodeprint(t_node *node)
{
	while (node)
	{
//		if (node->other)
//		{
//			while(
//		}
		printf("%s\n", node->content);
		node = node->next;
	}
}
