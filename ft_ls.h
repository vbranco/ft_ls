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

typedef struct		s_format
{
	char		mode;
	char		umode[4];
	char		gmode[4];
	char		omode[4];
	int		nlink;
	char		*pw_name;
	char		*gr_name;
	int		st_size;
	char		*time;
}			t_format;

void			ft_init_flag(t_flag *flag);
void			ft_init_format(t_format *format);
void			ft_flag(char *str, t_flag *flag);
void			ft_stat(char *file, struct stat *st, t_format *format);
int				ft_flag_status(t_flag *flag);
void			ft_lstprint(t_list *liste);
void			ft_dir_name(t_list **liste, char *str);
void			ft_no_flag(char *av, DIR *dir, struct dirent *pdir, t_list **liste, int ac);

#endif
