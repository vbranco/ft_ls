/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fileinfo_sort.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/05 19:38:39 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/25 16:31:29 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

//------------  GROS PROB sur le ./ft_ls ./ .  --------------//



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
	if (!s1[i] || (ft_strcmp(s2, "..") != 0 && ft_strcmp(s2, ".") != 0))
//	if (!s1[i])
	{
//		printf("if et !s1 || s1 >> %s\n", s1);
//		printf("if et !s1 || s2 >> %s\n", s2);
		return (ft_sort_r(flag));
	}
	if (s1[i] < s2[i] && s1[i] && s2[i])
	{
//		printf("if || s1 >> %s\n", s1);
//		printf("if || s2 >> %s\n", s2);
		return (ft_sort_r(flag));
	}
	else
	{
//		printf("else || s1 >> %s\n", s1);
//		printf("else || s2 >> %s\n", s2);
		return (!ft_sort_r(flag));
	}
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
	t_flag	fl;

	ft_init_flag(&fl);
	if ((file->name == NULL) || (novo->name == NULL))
		return (0);
	if (file->error != NULL || novo->error != NULL)
	{
		if (file->error == NULL)
			return (0);
		else if (novo->error == NULL)
			return (1);
		else
			return (ft_sort_name(file->name, novo->name, &fl));
	}
	else
	{
		if (flag->t == 0)
			return (ft_sort_name(file->name, novo->name, flag));
		else
			return (ft_sort_time(file, novo, flag));
	}
}

void	ft_fileinfo_sort(t_fileinfo **file, t_fileinfo *next, t_flag *flag)
{
	t_fileinfo	*tmp;
	t_fileinfo	*ll;

	tmp = NULL;
	ll = *file;
	while (ll && ft_sort(ll, next, flag))
	{
		tmp = ll;
		ll = ll->next;
	}
	next->next = ll;
	if (tmp)
		tmp->next = next;
	else
		*file = next;
}
