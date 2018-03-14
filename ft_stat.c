#include "ft_ls.h"

void	ft_stat(char *buf, char *file, struct stat *st)
{
	struct passwd	*pwd;
	struct group	*grp;
	char		*time;

	time = ft_memalloc(50);
	pwd = getpwuid(st->st_uid);
	grp = getgrgid(st->st_gid);
	stat(file, st);
	ft_strcat(time, ctime(&st->st_mtime));
	time += 4;
	time[12] = '\0';
	ft_strcat(buf, ((S_ISDIR(st->st_mode)) ? "d" : "-"));
	ft_strcat(buf, ((st->st_mode & S_IRUSR) ? "r" : "-"));
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
	ft_strcat(buf, "  ");
	ft_strcat(buf, pwd->pw_name);
	ft_strcat(buf, "  ");
	ft_strcat(buf, grp->gr_name);
	ft_strcat(buf, "  ");
	ft_strcat(buf, ft_itoa(st->st_size));
	ft_strcat(buf, "  ");
	ft_strcat(buf, time);
	ft_strcat(buf, "  ");
//	ft_strcat(buf, "  ");
//	ft_strcat(buf, "  ");
//	printf("%s", buf);
//	printf(" %s", ctime(&st->st_mtime));
//	free(time);
//	printf("%-*s%*s%*s", (int)ft_strlen(buf) + 2, buf, (int)ft_strlen(ft_itoa(st->st_nlink)), ft_itoa(st->st_nlink), (int)ft_strlen(pwd->pw_name) + 2, pwd->pw_name);
}
