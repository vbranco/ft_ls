/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 16:15:07 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/15 11:29:48 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_error(t_fileinfo **novo, char *file, char *error)
{
	char		err[PATH_MAX];
	char		*name;

	name = NULL;
	if (ft_strcmp(error, "Permission denied") == 0)
	{
		if (*file == '/' && ft_strchr(++file, '/'))
			file--;
		name = ft_strdup(file);
	}
	else
		name = ft_strdup(file);
	ft_bzero(err, PATH_MAX);
	ft_strcat(err, "ls: ");
	ft_strcat(err, name);
	ft_strcat(err, ": ");
	ft_strcat(err, error);
	(*novo)->error = ft_strdup(err);
	if ((*novo)->name == NULL)
		(*novo)->name = ft_strdup(file);
	if (name != NULL)
		free(name);
}

int				ft_dir(t_fileinfo *new)
{
	if (((new->st.st_mode & S_IFMT) == S_IFDIR) && !(new->mode[0] == 'r'
				&& new->mode[2] == '-'))
		return (1);
	return (0);
}

t_fileinfo		*ft_info(char *dir, char *name, t_space *sp)
{
	t_fileinfo	*new;

	if (!(new = ft_init_fileinfo()))
		return (NULL);
	if (dir == NULL)
		new->path = ft_strdup(name);
	else
	{
		new->path = ft_strdup(dir);
		if (ft_strcmp(dir, "/"))
			new->path = ft_realloc(new->path, "/");
		new->path = ft_realloc(new->path, name);
	}
	if (name[0] != '\0')
		ft_stat(new, sp);
	if (name[0] == '\0' && dir[0] == '\0')
		ft_error(&new, "fts_open", "No such file or directory");
	return (new);
}

t_fileinfo		*ft_is_link(char *file)
{
	t_fileinfo	*new;

	new = ft_init_fileinfo();
	new->path = ft_strdup(file);
	stat(new->path, &(new->st));
	new->name = ft_strdup(file);
	ft_ugid(new);
	ft_amode(new);
	ft_rmode(new);
	return (new);
}

void			ft_ls(t_fileinfo **start, t_node **args, t_flag *flag,
		t_space *sp)
{
	t_node		*arg;
	t_fileinfo	*new;

	arg = *args;
	while (arg->next)
	{
		new = ft_info(NULL, arg->content, sp);
		if (S_ISLNK(new->st.st_mode) && !flag->l)
		{
			ft_fileinfo_dell(&new);
			new = ft_is_link(arg->content);
		}
		if (ft_dir(new))
			ft_is_dir(new, arg->content, flag, sp);
		if (flag->t || new->error != NULL)
			ft_fileinfo_sort(start, new, flag);
		else
			ft_add_file_back(start, new);
		arg = arg->next;
	}
}
