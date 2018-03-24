/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 17:07:30 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/24 18:24:49 by vbranco     ###    #+. /#+    ###.fr     */
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
	int				l;
	int				R;
	int				r;
	int				a;
	int				t;
	int				ac;
}					t_flag;

typedef struct		s_format
{
	char			amode;
	char			mode[10];
	int				nlink;
	char			*pw_name;
	char			*gr_name;
	int				st_size;
	char			*time;
}					t_format;

typedef struct		s_node
{
	void			*content;
	size_t			content_size;
	struct s_node	*next;
	struct s_node	*other;
}					t_node;

void			ft_init_flag(t_flag *flag);
void			ft_init_format(t_format *format);
void			ft_flag(int ac, char **av, t_flag *flag);
void			ft_stat(char *file, struct stat *st, t_format *format);
int				ft_flag_status(t_flag *flag);
void			ft_file(char *str, t_flag *flag, t_format *format, t_node **node);
void			ft_dir(char *str, t_flag *flag, t_format *format, t_node **node);
void			ft_ls(t_flag *flag, t_node **node);
int			ft_count_args(int ac, char **av);
void			ft_args(char **av, t_flag *flag, t_node **node);

/*
**Listes
*/

void			ft_nodeprint(t_node *node);
void			ft_init_node(t_node	**node);
void			ft_nodedell(t_node *node);
void			ft_node_back_add(t_node **node, void *content, size_t content_size);
void			ft_node_front_add(t_node **node, void *content, size_t content_size);
void			ft_node_sort_add(t_node **node, void *content, size_t content_size);

#endif
