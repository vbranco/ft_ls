/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_node_front_add.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/28 18:20:10 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/28 18:20:12 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_node_front_add(t_node **node, void *content, size_t content_size)
{
	t_node	*new;

	if (!(new = (t_node*)malloc(sizeof(t_node))))
		return ;
	if (!(new->content = ft_memalloc(content_size)))
		return ;
	ft_memcpy(new->content, content, content_size);
	new->content_size = content_size;
	new->next = *node;
	*node = new;
}
