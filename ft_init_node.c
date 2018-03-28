/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_node.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/28 18:13:43 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/28 18:23:09 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_init_node(t_node *node)
{
	node = malloc(sizeof(t_node));
	node->content = NULL;
	node->content_size = 0;
	node->next = NULL;
}
