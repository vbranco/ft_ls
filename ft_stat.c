/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_stat.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/20 18:40:38 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/07 18:31:31 by vbranco     ###    #+. /#+    ###.fr     */
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
	fileinfo->total = fileinfo->st.st_blocks;//pas encore au point
}

static void ft_acl(t_fileinfo *fileinfo)
{
	acl_t		acl;
	acl_entry_t	dummy;
	ssize_t		xatrr;

	xatrr = 0;
	acl = NULL;
	acl = acl_get_link_np(fileinfo->name, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	xatrr = listxattr(fileinfo->name, NULL, 0, XATTR_NOFOLLOW);
	if (xatrr < 0)
		xatrr = 0;
	if (xatrr > 0)
		fileinfo->mode[9] = '@';
	else if (acl != NULL)
		fileinfo->mode[9] = '+';
}

static void	ft_rmode(t_fileinfo *fileinfo)
{
	((fileinfo->st.st_mode & S_IRUSR) ? fileinfo->mode[0] = 'r' : 0);
	((fileinfo->st.st_mode & S_IWUSR) ? fileinfo->mode[1] = 'w' : 0);
	if ((fileinfo->st.st_mode & S_ISUID) && !(fileinfo->st.st_mode & S_IXUSR))
		fileinfo->mode[2] = 'S';
	else if ((fileinfo->st.st_mode & S_ISUID) && (fileinfo->st.st_mode & S_IXUSR))
		fileinfo->mode[2] = 's';
	else if (fileinfo->st.st_mode & S_IXUSR)
		fileinfo->mode[2] = 'x';
	((fileinfo->st.st_mode & S_IRGRP) ? fileinfo->mode[3] = 'r' : 0);
	((fileinfo->st.st_mode & S_IWGRP) ? fileinfo->mode[4] = 'w' : 0);
	((fileinfo->st.st_mode & S_IXGRP) ? fileinfo->mode[5] = 'x' : 0);
	((fileinfo->st.st_mode & S_IROTH) ? fileinfo->mode[6] = 'r' : 0);
	((fileinfo->st.st_mode & S_IWOTH) ? fileinfo->mode[7] = 'w' : 0);
	if ((fileinfo->st.st_mode & S_ISVTX) && (fileinfo->st.st_mode & S_IXOTH))
		fileinfo->mode[8] = 't';
	else if ((fileinfo->st.st_mode & S_ISVTX) && !(fileinfo->st.st_mode & S_IXOTH))
		fileinfo->mode[8] = 'T';
	else if (fileinfo->st.st_mode & S_IXOTH)
		fileinfo->mode[8] = 'x';
}

static void	ft_file_display(char *str, t_fileinfo *tmp, t_space *sp)
{
	tmp->name = ft_strdup(str);
	if (tmp->amode == 'b' || tmp->amode == 'c')
	{
		tmp->maj = major(tmp->st.st_rdev);
		tmp->min = minor(tmp->st.st_rdev);
		if (ft_size_nb(tmp->maj) > sp->size_madev)
			sp->size_madev = ft_size_nb(tmp->maj);
		if (ft_size_nb(tmp->min) > sp->size_midev)
			sp->size_midev = ft_size_nb(tmp->min);
	}
	if (ft_size_nb(tmp->st.st_nlink) > sp->size_nlink)
		sp->size_nlink = ft_size_nb(tmp->st.st_nlink);
	if (ft_strlen(tmp->pw_name) > sp->size_pname)
		sp->size_pname = ft_strlen(tmp->pw_name);
	if (ft_strlen(tmp->gr_name) > sp->size_gname)
		sp->size_gname = ft_strlen(tmp->gr_name);
	if (ft_size_nb(tmp->st.st_size) > sp->size_stsize)
		sp->size_stsize = ft_size_nb(tmp->st.st_size);
}

char	*ft_time(char *time)
{
	char	*tmp;
	char	*year;
	char	*ret;

	tmp = ft_strsub(time, 4, 7);
	year = ft_strsub(time, 19, 5);
	ret = ft_memalloc(ft_strlen(tmp) + ft_strlen(year) + 1);
	ft_strcat(ret, tmp);
	ft_strcat(ret, year);
	free(tmp);
	free(year);
	return (ret);
}

int		ft_stat(char *file, t_fileinfo *fileinfo, t_space *sp)
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
	if (time(NULL) - fileinfo->st.st_mtime > 15778800 || time(NULL) < fileinfo->st.st_mtime)
		fileinfo->time = ft_time(ctime(&fileinfo->st.st_mtime));
	else
		fileinfo->time = ft_strsub(ctime(&fileinfo->st.st_mtime), 4, 12);
	ft_amode(fileinfo);
	ft_rmode(fileinfo);
	if (fileinfo->amode == 'l')
		readlink(file, fileinfo->link, PATH_MAX);
	fileinfo->pw_name = ft_strdup(pwd->pw_name);
	fileinfo->gr_name = ft_strdup(grp->gr_name);
	ft_file_display(file, fileinfo, sp);
	ft_acl(fileinfo);
	return (0);
}
