/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fileinfo_sort.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/05 19:38:39 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/05 19:46:49 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_sort_r(t_flag *flag)
{
	if (flag->r == 0)
		return (1);
	else if (flag->r == 1)
		return (0);
	return (1);
}

static int	ft_sort_name(char *s1, char *s2, t_flag *flag)
{
	int		i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (!s1[i])
		return (ft_sort_r(flag));
	if (s1[i] < s2[i] && s1[i] && s2[i])
		return (ft_sort_r(flag));
	else
		return (!ft_sort_r(flag));
	return (0);
}

static int		ft_sort_time(t_fileinfo *file, t_fileinfo *novo, t_flag *flag)
{
	if (file->st.st_mtime < novo->st.st_mtime)
	{
		if (flag->r == 0)
			return (0);
		else if (flag->r == 1)
			return (1);
	}
	else if (file->st.st_mtime == novo->st.st_mtime)
	{
		return (ft_sort_name(file->name, novo->name, flag));
	}
	else
	{
		if (flag->r == 0)
			return (1);
		else if (flag->r == 1)
			return (0);
	}
	return (0);
}

static int	ft_sort(t_fileinfo *file, t_fileinfo *novo, t_flag *flag)
{
	if (flag->t == 0)
		return (ft_sort_name(file->name, novo->name, flag));
	else
		return (ft_sort_time(file, novo, flag));
}

void	ft_fileinfo_sort(t_fileinfo **file, t_fileinfo *novo, t_flag *flag)
{
	t_fileinfo	*tmp;
	t_fileinfo	*ll;

	tmp = NULL;
	ll = *file;
	while (ll && ft_sort(ll, novo, flag))
	{
		tmp = ll;
		ll = ll->next;
	}
	novo->next = ll;
	if (tmp)
		tmp->next = novo;
	else
		*file = novo;
}
