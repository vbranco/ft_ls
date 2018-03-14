/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 17:07:30 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 20:06:27 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <sys/stat.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct		s_flag
{
	int		l;
	int		R;
	int		r;
	int		a;
	int		t;
}			t_flag;

void			ft_init_flag(t_flag *flag);
void			ft_flag(char *str, t_flag *flag);
void			ft_stat(char *buf, char *file, struct stat *st);
int				ft_no_flag(t_flag *flag);
void			ft_lstprint(t_list *liste);

#endif
