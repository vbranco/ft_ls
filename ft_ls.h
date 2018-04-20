/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 17:07:30 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 20:01:25 by vbranco     ###    #+. /#+    ###.fr     */
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

# define PATH_MAX	 1024
# define TBLACK		"\e[30m"
# define TBLUE		"\e[34m"
# define TCYAN		"\e[1m\e[96m"
# define TRED		"\e[31m"
# define TMAGENTA	"\e[35m"
# define TGREEN		"\e[32m"
# define TYELLOW	"\e[33m"
# define BBLACK		"\e[40m"
# define BCYAN		"\e[46m"
# define BYELLOW	"\e[43m"
# define BRED		"\e[41m"
# define BGREEN		"\e[42m"
# define TSTOP		"\e[0m"

# define FLAGS		"lGRrat1-\0"

typedef struct			s_flag
{
	short int			l;
	short int			R;
	short int			r;
	short int			a;
	short int			t;
	short int			un;
	short int			ac;
	short int			total;
	short int			out;
}						t_flag;
/*
**flag l == -1 c'est G //flag l == 2 c'est l //flag l == 1 c'est lG
*/

typedef struct			s_fileinfo
{
	struct stat			st;
	char				*name;
	char				*path;
	char				amode;
	char				mode[11];
	char				*pw_name;
	char				*gr_name;
	char				link[PATH_MAX];
	char				*time;
	int					maj;
	int					min;
	unsigned int		total;
	char				*error;
	struct s_fileinfo	*next;
	struct s_fileinfo	*other;
}						t_fileinfo;

typedef struct			s_space
{
	short int			size_nlink;
	short int			size_pname;
	short int			size_gname;
	short int			size_stsize;
	short int			size_madev;
	short int			size_midev;
}						t_space;

typedef struct			s_node
{
	void				*content;
	size_t				content_size;
	struct s_node		*next;
}						t_node;

void					ft_init_flag(t_flag *flag);
t_fileinfo				*ft_init_fileinfo();
int						ft_flag(int ac, char **av, t_flag *flag);
int						ft_stat(t_fileinfo *fileinfo, t_space *sp);
int						ft_flag_status(t_flag *flag);
void					ft_ls(t_fileinfo **start, t_node **args, t_flag *flag, t_space *sp);
int						ft_count_args(int ac, char **av);
void					ft_args(char **av, t_flag *flag, t_node **node);
void					ft_init_space(t_space *sp);
//-----------------------------
void					ft_display_dir(t_fileinfo *file, t_flag *flag, t_space *sp);
void					ft_pdir(t_fileinfo *file, t_flag *flag, t_space *sp);
void					ft_error(t_fileinfo **novo, char *file, char *error);



/*
 **Listes
 */

void					ft_fileinfoprint(t_fileinfo *file, t_flag *flag, t_space *sp);
void					ft_fileinfo_sort(t_fileinfo **file, t_fileinfo *novo, t_flag *flag);
void					ft_add_file_back(t_fileinfo **file, t_fileinfo *novo);
void					ft_fileinfo_dell(t_fileinfo **file);



void					ft_init_node(t_node	*node);
void					ft_nodedell(t_node **node);
void					ft_node_back_add(t_node **node, void *content, size_t content_size);
void					ft_node_front_add(t_node **node, void *content, size_t content_size);
void					ft_node_sort_add(t_node **node, void *content, size_t content_size);

#endif
