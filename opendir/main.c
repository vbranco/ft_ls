# include "../libft/libft.h"
# include <sys/stat.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>

typedef struct		s_file
{
	struct stat		st;
	char			*name;
	struct s_file	*next;
}					t_file;

void	add(t_file **file, t_file *new)
{
	new->next = *file;
	*file = new;
}

void	print(t_file *file)
{
	while (file)
	{
		printf("%s  ", file->name);
		printf("%d  ", file->st.st_uid);
		printf("%d\n", file->st.st_gid);
		file = file->next;
	}
}

t_file	*init_file()
{
	t_file	*new;

	new = malloc(sizeof(t_file));
	new->name = NULL;
	new->next = NULL;
	return (new);
}

void	ft_stat(char *file, t_file *new)
{
	errno = 0;
	if (lstat(file, &new->st) != 0)
	{
		perror(file);
		return ;
	}
	new->name = ft_strdup(file);
}

void	work(char *name, t_file **file)
{
	t_file	*new;

	new = init_file();
	ft_stat(name, new);
	add(file, new);
}

int		main(int ac, char **av)
{
	t_file			*file;
	DIR				*dir;
	struct dirent	*pdir;

	file = init_file();
	file = NULL;
	dir = opendir(av[1]);
	while ((pdir = readdir(dir)) != NULL)
	{
		t_file *new;
		new = init_file();
		errno = 0;
		lstat(pdir->d_name, &new->st);
/*		if (lstat(pdir->d_name, &new->st) != 0)
		{
			perror(pdir->d_name);
			return (0);
		}
*/		new->name = ft_strdup(pdir->d_name);
		add(&file, new);
//		work(pdir->d_name, &file);
//		printf("%s\n", pdir->d_name);
	}
	closedir(dir);
	print(file);
	return (0);
}
