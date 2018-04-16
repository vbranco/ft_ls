#include "ft_ls.h"

static int	ft_dir(t_fileinfo *new)
{
	if ((new->st.st_mode & S_IFMT) == S_IFDIR)
		return (1);
	return (0);
}

t_fileinfo	*ft_info(char *dir, char *name, t_space *sp)
{
	t_fileinfo	*new;
	char		*path;

	path = NULL;
	new = ft_init_fileinfo();
	if (dir == NULL)
		new->path = ft_strdup(name);
	else
	{
		path = ft_memalloc(ft_strlen(dir) + ft_strlen(name) + 2);
		ft_strcat(path, dir);
		ft_strcat(path, "/");
		ft_strcat(path, name);
		new->path = ft_strdup(path);
		free(path);
	}
	ft_stat(new, sp);
	return (new);
}

static void	ft_recursive(t_fileinfo *current, char *direct, t_flag *flag, t_space *sp)
{
	DIR				*dir;
	struct dirent	*pdir;
	t_fileinfo		*new;

	if ((dir = opendir(direct)) == NULL)
	{
		perror("ls problem in ft_recursive");
		return ;
	}
	while ((pdir = readdir(dir)) != NULL)
	{
		if (pdir->d_name[0] == '.' && !flag->a)
			continue ;
		new = ft_info(direct, pdir->d_name, sp);
		if (ft_dir(new) && flag->R)
			ft_recursive(new, new->path, flag, sp);
		ft_fileinfo_sort(&(current->other), new, flag);
//		ft_add_file_back(&(current->other), new);
	}
	closedir(dir);
}

static void	ft_is_dir(t_fileinfo *current, char *direct, t_flag *flag, t_space *sp)
{
	DIR				*dir;
	struct dirent	*pdir;
	t_fileinfo		*new;

	if ((dir = opendir(direct)) == NULL)
	{
		perror("ls problem sur ft_is_dir");
		return ;
	}
	while ((pdir = readdir(dir)) != NULL)
	{
		if (pdir->d_name[0] == '.' && !flag->a)
			continue ;
		new = ft_info(direct, pdir->d_name, sp);
//		printf("path : %s\n", new->path);
		if (ft_dir(new) && flag->R)
			ft_recursive(new, pdir->d_name, flag, sp);
		ft_fileinfo_sort(&(current->other), new, flag);
//		ft_add_file_back(&(current->other), new);
	}
	closedir(dir);
}

void		ft_ls(t_fileinfo **start, t_node **args, t_flag *flag, t_space *sp)
{
	t_node		*arg;
	t_fileinfo	*new;

	arg = *args;
	while (arg)
	{
		new = ft_info(NULL, arg->content, sp);
		if (ft_dir(new) == 1)
			ft_is_dir(new, arg->content, flag, sp);
		else
			ft_is_file(new, arg->content, flag, sp);
		arg = arg->next;
//		ft_fileinfo_sort(start, new, flag);
		ft_add_file_back(start, new);
	}
}
