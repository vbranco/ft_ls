/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_stat.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/20 18:40:38 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/24 18:24:52 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_amode(t_fileinfo *fileinfo)
{
	if (S_ISLNK(fileinfo->st.st_mode))
		fileinfo->amode =  'l';
	else if (S_ISREG(fileinfo->st.st_mode))
		fileinfo->amode =  '-';
	else if (S_ISCHR(fileinfo->st.st_mode))
		fileinfo->amode =  'c';
	else if (S_ISBLK(fileinfo->st.st_mode))
		fileinfo->amode =  'b';
	else if (S_ISFIFO(fileinfo->st.st_mode))
		fileinfo->amode =  'p';
	else if (S_ISSOCK(fileinfo->st.st_mode))
		fileinfo->amode =  's';
	else if (S_ISDIR(fileinfo->st.st_mode))
		fileinfo->amode =  'd';
}

static void	ft_rmode(t_fileinfo *fileinfo)
{
	((fileinfo->st.st_mode & S_IRUSR) ? fileinfo->mode[0] = 'r' : 0);
	((fileinfo->st.st_mode & S_IWUSR) ? fileinfo->mode[1] = 'w' : 0);
	((fileinfo->st.st_mode & S_IXUSR) ? fileinfo->mode[2] = 'x' : 0);
	((fileinfo->st.st_mode & S_IRGRP) ? fileinfo->mode[3] = 'r' : 0);
	((fileinfo->st.st_mode & S_IWGRP) ? fileinfo->mode[4] = 'w' : 0);
	((fileinfo->st.st_mode & S_IXGRP) ? fileinfo->mode[5] = 'x' : 0);
	((fileinfo->st.st_mode & S_IROTH) ? fileinfo->mode[6] = 'r' : 0);
	((fileinfo->st.st_mode & S_IWOTH) ? fileinfo->mode[7] = 'w' : 0);
	((fileinfo->st.st_mode & S_IXOTH) ? fileinfo->mode[8] = 'x' : 0);
	fileinfo->nlink = fileinfo->st.st_nlink;
}

void	ft_stat(char *file, t_fileinfo *fileinfo)
{
	struct passwd	*pwd;
	struct group	*grp;
	t_fileinfo		*tmp;

	tmp = fileinfo;
	errno = 0;
	if (lstat(file, &tmp->st) != 0)
	{
		perror(file);
		return ;
	}
	pwd = getpwuid(tmp->st.st_uid);
	grp = getgrgid(tmp->st.st_gid);
	ft_strcat(tmp->time, ctime(&tmp->st.st_mtime));
	tmp->time[16] = '\0';
	ft_amode(tmp);
	ft_rmode(tmp);
	tmp->pw_name = ft_memalloc(ft_strlen(pwd->pw_name));
	tmp->gr_name = ft_memalloc(ft_strlen(grp->gr_name));
	ft_strcat(tmp->pw_name, pwd->pw_name);
	ft_strcat(tmp->gr_name, grp->gr_name);
	tmp->st_size = tmp->st.st_size;
}
