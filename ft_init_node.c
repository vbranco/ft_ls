/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_node.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/28 18:13:43 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/28 17:47:11 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_node	*ft_init_node(void)
{
	t_node	*node;

	node = NULL;
	node = malloc(sizeof(t_node));
	node->content = NULL;
	node->content_size = 0;
	node->next = NULL;
	return (node);
}
