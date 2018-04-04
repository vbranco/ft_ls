/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_stat.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/20 18:40:38 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/28 20:05:48 by vbranco     ###    #+. /#+    ###.fr     */
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

static void	ft_file_name(char *str, t_fileinfo *tmp)
{
	tmp->name = ft_strdup(str);
}

int		ft_stat(char *file, t_fileinfo *fileinfo)
{
	struct passwd	*pwd;
	struct group	*grp;

	errno = 0;
	if (lstat(file, &(fileinfo->st)) != 0)
	{
		perror(file);
		return (1);
	}
	pwd = getpwuid(fileinfo->st.st_uid);
	grp = getgrgid(fileinfo->st.st_gid);
	fileinfo->time = fileinfo->st.st_mtime;
	ft_amode(fileinfo);
	ft_rmode(fileinfo);
	fileinfo->pw_name = ft_strdup(pwd->pw_name);
	fileinfo->gr_name = ft_strdup(grp->gr_name);
	fileinfo->st_size = fileinfo->st.st_size;
	ft_file_name(file, fileinfo);
	return (0);
}
