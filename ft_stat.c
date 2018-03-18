#include "ft_ls.h"

void	ft_stat(char *file, struct stat *st, t_format *format)
{
	struct passwd	*pwd;
	struct group	*grp;
//	char		*time;

//	time = ft_memalloc(50);
	lstat(file, st);
	pwd = getpwuid(st->st_uid);
	grp = getgrgid(st->st_gid);
	ft_strcat(format->time, ctime(&st->st_mtime));
	format->time += 4;
	format->time[12] = '\0';



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
	format->pw_name = ft_memalloc(ft_strlen(pwd->pw_name));//attention au malloc
	format->gr_name = ft_memalloc(ft_strlen(grp->gr_name));//attention au malloc
//	format->time = ft_memalloc(ft_strlen(time));//attention au malloc
	ft_strcat(format->pw_name, pwd->pw_name);
	ft_strcat(format->gr_name, grp->gr_name);
	format->st_size = st->st_size;
//	ft_strcat(format->time, time);


/*	ft_strcat(buf, ((st->st_mode & S_IRUSR) ? "r" : "-"));
	ft_strcat(buf, ((st->st_mode & S_IWUSR) ? "w" : "-"));
	ft_strcat(buf, ((st->st_mode & S_IXUSR) ? "x" : "-"));
	ft_strcat(buf, ((st->st_mode & S_IRGRP) ? "r" : "-"));
	ft_strcat(buf, ((st->st_mode & S_IWGRP) ? "w" : "-"));
	ft_strcat(buf, ((st->st_mode & S_IXGRP) ? "x" : "-"));
	ft_strcat(buf, ((st->st_mode & S_IROTH) ? "r" : "-"));
	ft_strcat(buf, ((st->st_mode & S_IWOTH) ? "w" : "-"));
	ft_strcat(buf, ((st->st_mode & S_IXOTH) ? "x" : "-"));
	ft_strcat(buf, "  ");
	ft_strcat(buf, ft_itoa(st->st_nlink));
//	printf(" size >> %d", ft_strlen(ft_itoa(st->st_nlink)));
	ft_strcat(buf, "  ");
	ft_strcat(buf, pwd->pw_name);
	ft_strcat(buf, "  ");
	ft_strcat(buf, grp->gr_name);
	ft_strcat(buf, "  ");
	ft_strcat(buf, ft_itoa(st->st_size));
	ft_strcat(buf, "  ");
	ft_strcat(buf, time);
	ft_strcat(buf, "  ");
//	free(time-4);
//	ft_strcat(buf, "  ");
//	ft_strcat(buf, "  ");
//	printf("%s", buf);
//	printf(" %s", ctime(&st->st_mtime));
//	free(time);
//	printf("%-*s%*s%*s", (int)ft_strlen(buf) + 2, buf, (int)ft_strlen(ft_itoa(st->st_nlink)), ft_itoa(st->st_nlink), (int)ft_strlen(pwd->pw_name) + 2, pwd->pw_name);*/
}
