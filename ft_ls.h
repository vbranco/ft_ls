/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 17:07:30 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/07 18:31:30 by vbranco     ###    #+. /#+    ###.fr     */
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
# include <sys/acl.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>

# define PATH_MAX 1024

typedef struct			s_flag
{
	int					l;
	int					R;
	int					r;
	int					a;
	int					t;
	int					ac;
}						t_flag;

typedef struct			s_fileinfo
{
	struct stat			st;
	char				*name;
	char				amode;
	char				mode[11];
	char				*pw_name;
	char				*gr_name;
	char				link[PATH_MAX];
	char				*time;
	int					maj;
	int					min;
	unsigned int		total;
	struct s_fileinfo	*next;
	struct s_fileinfo	*other;
}						t_fileinfo;

typedef struct			s_space
{
	int					size_nlink;
	int					size_pname;
	int					size_gname;
	int					size_stsize;
	int					size_madev;
	int					size_midev;
}						t_space;

typedef struct			s_node
{
	void				*content;
	size_t				content_size;
	struct s_node		*next;
}						t_node;

void					ft_init_flag(t_flag *flag);
t_fileinfo				*ft_init_fileinfo();
void					ft_flag(int ac, char **av, t_flag *flag);
int						ft_stat(char *file, t_fileinfo *fileinfo, t_space *sp);
int						ft_flag_status(t_flag *flag);
void					ft_dir(char *str, t_flag *flag, t_fileinfo *fileinfo);
void					ft_ls(t_flag *flag, t_fileinfo **file, t_node **arg, t_space *sp);
int						ft_count_args(int ac, char **av);
void					ft_args(char **av, t_flag *flag, t_node **node);
void					ft_init_space(t_space *sp);

/*
 **Listes
 */

void					ft_fileinfoprint(t_fileinfo *file, t_flag flag, t_space *sp);
void					ft_fileinfo_sort(t_fileinfo **file, t_fileinfo *novo, t_flag *flag);
void					ft_init_node(t_node	*node);
void					ft_nodedell(t_node *node);
void					ft_node_back_add(t_node **node, void *content, size_t content_size);
void					ft_node_front_add(t_node **node, void *content, size_t content_size);
void					ft_node_sort_add(t_node **node, void *content, size_t content_size);

#endif
