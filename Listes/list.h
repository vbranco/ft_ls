/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   list.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/12 18:30:07 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 19:52:33 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct		s_list
{
	char			*str;
	struct s_list	*next;
}					t_list;

typedef struct		l_liste
{
	int		nb;
	struct l_liste	*next;
}			n_list;

#endif
