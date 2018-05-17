/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_initialise.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/15 11:36:38 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/17 17:42:06 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_fileinfo		*ft_init_fileinfo(void)
{
	t_fileinfo	*fileinfo;

	fileinfo = NULL;
	fileinfo = malloc(sizeof(t_fileinfo));
	fileinfo->amode = 0;
	fileinfo->name = NULL;
	fileinfo->path = NULL;
	ft_memset(fileinfo->mode, '-', 10);
	fileinfo->mode[9] = ' ';
	fileinfo->mode[10] = '\0';
	fileinfo->pw_name = NULL;
	fileinfo->gr_name = NULL;
	fileinfo->time = NULL;
	ft_bzero(fileinfo->link, PATH_MAX);
	fileinfo->min = 0;
	fileinfo->maj = 0;
	fileinfo->total = 0;
	fileinfo->error = NULL;
	fileinfo->next = NULL;
	fileinfo->other = NULL;
	return (fileinfo);
}

void			ft_init_flag(t_flag *flag)
{
	flag->l = 0;
	flag->gr = 0;
	flag->gg = 0;
	flag->g = 0;
	flag->r = 0;
	flag->a = 0;
	flag->t = 0;
	flag->f = 0;
	flag->o = 0;
	flag->i = 0;
	flag->un = 0;
	flag->ac = 0;
	flag->total = 0;
	flag->out = 0;
}

t_node			*ft_init_node(void)
{
	t_node		*node;

	node = NULL;
	node = malloc(sizeof(t_node));
	node->content = NULL;
	node->content_size = 0;
	node->next = NULL;
	return (node);
}

void			ft_init_space(t_space *sp)
{
	sp->size_nlink = 0;
	sp->size_pname = 0;
	sp->size_gname = 0;
	sp->size_stsize = 0;
	sp->size_madev = 0;
	sp->size_midev = 0;
}
