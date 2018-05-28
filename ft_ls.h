/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 17:07:30 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/28 17:44:43 by vbranco     ###    #+. /#+    ###.fr     */
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

# define FLAGS		"lGRgratfoi1\0"
# define SIX_MONTHS ((365/2) * 86400)

typedef struct			s_flag
{
	short int			l;
	short int			gr;
	short int			gg;
	short int			g;
	short int			r;
	short int			a;
	short int			t;
	short int			f;
	short int			o;
	short int			i;
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
	short int			stat_error;
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

/*
**	Flags >> ft_flag.c && main.c
*/
int						ft_flag(int ac, char **av, t_flag *flag);
int						ft_flag_status(t_flag *flag);

/*
**	Infos stat >> ft_stat.c + ft_stat2.c
*/
int						ft_stat(t_fileinfo *fileinfo, t_space *sp);

/*
**	Infos stat >> ft_stat.c + ft_stat2.c
*/
void					ft_amode(t_fileinfo *fileinfo);
void					ft_rmode(t_fileinfo *fileinfo);
char					*ft_time(char *time);

/*
**	Infos pour affichage Long + infos generales
*/
void					ft_ls(t_fileinfo **start, t_node **args,
		t_flag *flag, t_space *sp);
void					ft_ugid(t_fileinfo *file);
t_fileinfo				*ft_info(char *dir, char *name, t_space *sp);
int						ft_dir(t_fileinfo *novo);

/*
**	Gestion arguments
*/
int						ft_count_args(int ac, char **av);
int						ft_arg(char **av, t_flag *flag, t_node **node);

/*
**	Recursive + quelques gestions particulieres >> ft_dir.c
*/
void					ft_is_dir(t_fileinfo *current, char *direct,
		t_flag *flag, t_space *sp);
void					ft_recursive(t_fileinfo *current, t_flag *flag,
		t_space *sp);

/*
**	Gestion flag->a >> ft_flag_a.c
*/
void					ft_flag_a(t_fileinfo *current, char *direct,
		t_flag *flag, t_space *sp);

/*
**	Colors and long >> ft_color_and_long.c
*/
void					color(t_fileinfo *file);
void					printl(t_fileinfo *file, t_space *sp, t_flag *flag);
int						ft_total(t_fileinfo *file);

/*
**	Initialise structures >> ft_initialise.c
*/
t_node					*ft_init_node(void);
t_fileinfo				*ft_init_fileinfo();
void					ft_init_flag(t_flag *flag);
void					ft_init_space(t_space *sp);

/*
**	Listes dellect >> ft_list_dell.c
*/
void					ft_nodedell(t_node **node);
void					ft_fileinfo_dell(t_fileinfo **file);

/*
**	Listes affichage >> ft_fileinfoprint.c
*/
void					ft_fileinfoprint(t_fileinfo *file, t_flag *flag,
		t_space *sp);
void					ft_pdir(t_fileinfo *file, t_flag *flag, t_space *sp);
void					ft_file_other(t_fileinfo *file, t_flag *flag,
		t_space *sp);
void					ft_file_no_other(t_fileinfo *file, t_flag *flag);

/*
**	Decoupage affichage >> ft_display_dir.c
*/
void					ft_display_dir(t_fileinfo *file, t_flag *flag,
		t_space *sp);

/*
**	Gestion des affichages en generale
*/
char					*ft_name(char *str);
void					ft_error(t_fileinfo **novo, char *file, char *error);

/*
**	Ajout element dans la liste
*/
void					ft_fileinfo_sort(t_fileinfo **file, t_fileinfo *novo,
		t_flag *flag);
void					ft_add_file_back(t_fileinfo **file, t_fileinfo *novo);

/*
**	Gestion param recus >> ft_add_node.c
*/
void					ft_node_back_add(t_node **node, void *content,
		size_t content_size);
void					ft_node_front_add(t_node **node, void *content,
		size_t content_size);
void					ft_node_sort_add(t_node **node, void *content,
		size_t content_size);

#endif
