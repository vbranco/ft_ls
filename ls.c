#include "ft_ls.h"

static int	ft_file(t_fileinfo *new, char *name, t_flag *flag, t_space *sp)
{
	new->path = ft_strdup(name);
	if (ft_stat(new, sp))
		return (1);
	return (0);
}

static char	*ft_path(char *dir, char *file)
{
	char	*ret;

	ret = ft_memalloc(ft_strlen(dir) + ft_strlen(file) + 2);
	ft_strcat(ret, dir);
	ft_strcat(ret, "/");
	ft_strcat(ret, file);
	return (ret);
}
static int	ft_is_dir(t_fileinfo **current, char *name, t_flag *flag, t_space *sp)
{
	t_fileinfo		*new;
	DIR				*dir;
	struct dirent	*pdir;

	if ((dir = opendir(name)) == NULL )
	{
		perror("ls: error sur ft_is_dir");
		return (1);
	}
//	write(1, "ici\n", 4);
	printf("ici\n");
	while ((pdir = readdir(dir)) != NULL)
	{
//		if (pdir->d_name[0] == '.' && !flag->a)
//			continue ;
//		new->path = ft_path(name, pdir->d_name);
//		ft_stat(new, sp);
		printf("%s\n", pdir->d_name);
		ft_fileinfo_sort(current, new, flag);
	}
	closedir(dir);
	return (0);
}

static int	ft_dir(char *name)
{
	struct stat	st;

	if (stat(name, &st) != 0)
	{
		perror(name);
		return (-1);
	}
	if ((st.st_mode & S_IFMT) == S_IFDIR)
		return (1);
	return (0);
}

void		f_ls(t_fileinfo **start, t_node **args, t_flag *flag, t_space *sp)
{
	t_node		*arg;
	t_fileinfo	*new;

	arg = *args;
	new = ft_init_fileinfo();
	while (arg)
	{
		if (ft_dir(arg->content) == 1)
		{
			if (ft_is_dir(&(new->other), arg->content, flag, sp))
				return ;
		}
		else if ((ft_dir(arg->content)) == -1)
			return ;
		else
			if (ft_file(new, arg->content, flag, sp))
				return ;
		ft_add_file_back(start, new);
		arg = arg->next;
	}
}
