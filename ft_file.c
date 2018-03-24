/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_file.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/20 18:52:29 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/24 18:24:57 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_file(char *str, t_flag *flag, t_format *format, t_node **node)
{
	struct stat	st;
	char		*buf;

	if (flag->l == 1)
	{
		ft_init_format(format);
		ft_stat(str, &st, format);
		buf = ft_memalloc(1 + 4 + 4 + 4 + 4 + ft_strlen(format->pw_name) + ft_strlen(format->gr_name) + 4 + ft_strlen(format->time));
		char s[2];
		s[0] = format->amode;
		s[1] = '\0';
		ft_strcat(buf, s);
//		ft_strcat(buf, format->mode);
		ft_strcat(buf, format->mode);
		ft_strcat(buf, "  ");
		ft_strcat(buf, ft_itoa(format->nlink));
		ft_strcat(buf, "  ");
		ft_strcat(buf, format->pw_name);
		ft_strcat(buf, "  ");
		ft_strcat(buf, format->gr_name);
		ft_strcat(buf, "  ");
		ft_strcat(buf, ft_itoa(format->st_size));
		ft_strcat(buf, "  ");
		ft_strcat(buf, format->time);
		ft_strcat(buf, "  ");
		ft_strcat(buf, str);
		ft_node_front_add(node, buf, ft_strlen(buf));
		free(buf);
		free(format->time);
		free(format->pw_name);
		free(format->gr_name);
	}
	else
		ft_node_front_add(node, str, ft_strlen(str));
}
