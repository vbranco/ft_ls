/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_file.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/20 18:52:29 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/20 19:56:46 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_file(char *str, t_flag *flag, t_format *format, t_node **node)
{
	struct stat st;

	ft_stat(str, &st, format);
	ft_node_back_add(node, str, ft_strlen(str));
}
