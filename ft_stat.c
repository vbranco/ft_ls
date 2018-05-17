/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_stat.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/20 18:40:38 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/15 09:37:57 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void			ft_acl(t_fileinfo *fileinfo)
{
	acl_t			acl;
	acl_entry_t		dummy;
	ssize_t			xatrr;

	xatrr = 0;
	acl = NULL;
	acl = acl_get_link_np(fileinfo->path, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	xatrr = listxattr(fileinfo->path, NULL, 0, XATTR_NOFOLLOW);
	if (xatrr < 0)
		xatrr = 0;
	if (xatrr > 0)
	{
		fileinfo->mode[9] = '@';
		acl_free(acl);
	}
	else if (acl != NULL)
	{
		fileinfo->mode[9] = '+';
		acl_free(acl);
	}
}

char				*ft_name(char *str)
{
	int				i;
	int				s;
	char			*ret;

	if (!str)
		return (NULL);
	i = 0;
	s = 0;
	while (str[i])
	{
		if (str[i] == '/')
			s = i + 1;
		i++;
	}
	ret = ft_memalloc(i + 10);
	i = 0;
	while (str[s])
	{
		ret[i] = str[s];
		i++;
		s++;
	}
	return (ret);
}

static void			ft_file_display(char *str, t_fileinfo *tmp, t_space *sp)
{
	tmp->name = ft_name(str);
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

void				ft_ugid(t_fileinfo *file)
{
	struct passwd	*pwd;
	struct group	*grp;

	pwd = NULL;
	grp = NULL;
	if (!(pwd = getpwuid(file->st.st_uid)))
		file->pw_name = ft_strdup("owner");
	else
		file->pw_name = ft_strdup(pwd->pw_name);
	if (!(grp = getgrgid(file->st.st_gid)))
		file->gr_name = ft_strdup("group");
	else
		file->gr_name = ft_strdup(grp->gr_name);
}

int					ft_stat(t_fileinfo *fileinfo, t_space *sp)
{
	errno = 0;
	if (lstat(fileinfo->path, &(fileinfo->st)) != 0)
	{
		if (fileinfo->error == NULL)
			ft_error(&fileinfo, fileinfo->path, strerror(errno));
		return (1);
	}
	ft_ugid(fileinfo);
	if (time(NULL) - fileinfo->st.st_mtime > SIX_MONTHS ||
			time(NULL) < fileinfo->st.st_mtime)
		fileinfo->time = ft_time(ctime(&fileinfo->st.st_mtime), sp);
	else
		fileinfo->time = ft_strsub(ctime(&fileinfo->st.st_mtime), 4, 12);
	ft_amode(fileinfo);
	ft_rmode(fileinfo);
	if (fileinfo->amode == 'l')
		readlink(fileinfo->path, fileinfo->link, PATH_MAX);
	ft_file_display(fileinfo->path, fileinfo, sp);
	ft_acl(fileinfo);
	return (0);
}
