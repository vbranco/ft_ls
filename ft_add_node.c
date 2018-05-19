/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_node_sort_add.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/07 12:10:18 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/19 11:49:26 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_test(char *s1, char *s2)
{
	int			i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (s1[i] < s2[i])
		return (1);
	return (0);
}

static int		ft_sort(char *s1, char *s2)
{
	int			i;
	struct stat	st2;
	struct stat st1;

	i = 0;
	if (!s1 || !s2)
		return (0);
	stat(s1, &st1);
	stat(s2, &st2);
	if (((st2.st_mode & S_IFMT) == S_IFDIR) && ((st1.st_mode & S_IFMT) !=
				S_IFDIR))
		return (1);
	else if (((st2.st_mode & S_IFMT) == S_IFDIR) && ((st1.st_mode & S_IFMT) ==
				S_IFDIR))
		return (ft_test(s1, s2));
	else if (((st2.st_mode & S_IFMT) != S_IFDIR) && ((st1.st_mode & S_IFMT) ==
				S_IFDIR))
		return (0);
	else
		return (ft_test(s1, s2));
	return (0);
}

void			ft_node_sort_add(t_node **node, void *content,
		size_t content_size)
{
	t_node		*new;
	t_node		*tmp;
	t_node		*ll;

	tmp = NULL;
	ll = *node;
	if (!(new = (t_node*)malloc(sizeof(t_node))))
		return ;
	if (!(new->content = ft_memalloc(content_size)))
		return ;
	while (ll && ft_sort(ll->content, content))
	{
		tmp = ll;
		ll = ll->next;
	}
	ft_memcpy(new->content, content, content_size);
	new->content_size = content_size;
	new->next = ll;
	if (tmp)
		tmp->next = new;
	else
		*node = new;
}

void			ft_node_back_add(t_node **node, void *content,
		size_t content_size)
{
	t_node		*tmp;
	t_node		*new;

	tmp = NULL;
	if (!(new = (t_node*)malloc(sizeof(t_node))))
		return ;
	if (!(new->content = ft_memalloc(content_size)))
		return ;
	tmp = *node;
	if (!tmp)
	{
		new->next = *node;
		*node = new;
	}
	else
	{
		new->next = NULL;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	ft_memcpy(new->content, content, content_size);
	new->content_size = content_size;
}

void			ft_node_front_add(t_node **node, void *content,
		size_t content_size)
{
	t_node		*new;

	if (!(new = (t_node*)malloc(sizeof(t_node))))
		return ;
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		if (!(new->content = ft_memalloc(content_size)))
			return ;
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->next = *node;
	*node = new;
}
