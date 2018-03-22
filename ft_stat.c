/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_stat.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/20 18:40:38 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/20 19:56:31 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_stat(char *file, struct stat *st, t_format *format)
{
	struct passwd	*pwd;
	struct group	*grp;

	lstat(file, st);
	pwd = getpwuid(st->st_uid);
	grp = getgrgid(st->st_gid);
	format->time = ft_memalloc(ft_strlen(ctime(&st->st_mtime)));
	ft_strcat(format->time, ctime(&st->st_mtime));
	format->time[16] = '\0';


	if (S_ISLNK(st->st_mode))
		format->mode =  'l';
	else if (S_ISREG(st->st_mode))
		format->mode =  '-';
	else if (S_ISCHR(st->st_mode))
		format->mode =  'c';
	else if (S_ISBLK(st->st_mode))
		format->mode =  'b';
	else if (S_ISFIFO(st->st_mode))
		format->mode =  'p';
	else if (S_ISSOCK(st->st_mode))
		format->mode =  's';
	else if (S_ISDIR(st->st_mode))
		format->mode =  'd';

	((st->st_mode & S_IRUSR) ? format->umode[0] = 'r' : 0);
	((st->st_mode & S_IWUSR) ? format->umode[1] = 'w' : 0);
	((st->st_mode & S_IXUSR) ? format->umode[2] = 'x' : 0);
	((st->st_mode & S_IRGRP) ? format->gmode[0] = 'r' : 0);
	((st->st_mode & S_IWGRP) ? format->gmode[1] = 'w' : 0);
	((st->st_mode & S_IXGRP) ? format->gmode[2] = 'x' : 0);
	((st->st_mode & S_IROTH) ? format->omode[0] = 'r' : 0);
	((st->st_mode & S_IWOTH) ? format->omode[1] = 'w' : 0);
	((st->st_mode & S_IXOTH) ? format->omode[2] = 'x' : 0);

	format->nlink = st->st_nlink;
	format->pw_name = ft_memalloc(ft_strlen(pwd->pw_name));
	format->gr_name = ft_memalloc(ft_strlen(grp->gr_name));
	ft_strcat(format->pw_name, pwd->pw_name);
	ft_strcat(format->gr_name, grp->gr_name);
	format->st_size = st->st_size;
}
