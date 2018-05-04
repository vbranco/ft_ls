#include "ft_ls.h"

void            ft_amode(t_fileinfo *fileinfo)
{
	if (S_ISLNK(fileinfo->st.st_mode))
		fileinfo->amode = 'l';
	else if (S_ISREG(fileinfo->st.st_mode))
		fileinfo->amode = '-';
	else if (S_ISCHR(fileinfo->st.st_mode))
		fileinfo->amode = 'c';
	else if (S_ISBLK(fileinfo->st.st_mode))
		fileinfo->amode = 'b';
	else if (S_ISFIFO(fileinfo->st.st_mode))
		fileinfo->amode = 'p';
	else if (S_ISSOCK(fileinfo->st.st_mode))
		fileinfo->amode = 's';
	else if (S_ISDIR(fileinfo->st.st_mode))
		fileinfo->amode = 'd';
	fileinfo->total = fileinfo->st.st_blocks;
}

void            ft_rmode(t_fileinfo *fileinfo)
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
	if ((fileinfo->st.st_mode & S_ISGID) && !(fileinfo->st.st_mode & S_IXGRP))
		fileinfo->mode[5] = 'S';
	else if ((fileinfo->st.st_mode & S_ISGID) && (fileinfo->st.st_mode & S_IXGRP))
		fileinfo->mode[5] = 's';
	else if (fileinfo->st.st_mode & S_IXGRP)
		fileinfo->mode[5] = 'x';
	((fileinfo->st.st_mode & S_IROTH) ? fileinfo->mode[6] = 'r' : 0);
	((fileinfo->st.st_mode & S_IWOTH) ? fileinfo->mode[7] = 'w' : 0);
	if ((fileinfo->st.st_mode & S_ISVTX) && (fileinfo->st.st_mode & S_IXOTH))
		fileinfo->mode[8] = 't';
	else if ((fileinfo->st.st_mode & S_ISVTX) && !(fileinfo->st.st_mode & S_IXOTH))
		fileinfo->mode[8] = 'T';
	else if (fileinfo->st.st_mode & S_IXOTH)
		fileinfo->mode[8] = 'x';
}

char        *ft_time(char *time, t_space *sp)
{
	char        *tmp;
	char        *year;
	char        *ret;
	int         len;
	short int   stop;

	len = ft_strlen(time) - 1;
	while (time[len] != ' ')
		len--;
	stop = len;
	while (time[stop] != '\n')
		stop++;
	tmp = ft_strsub(time, 4, 7);
	year = ft_strsub(time, len + 1, (stop - len - 1));
	ret = ft_memalloc(ft_strlen(tmp) + ft_strlen(year) + 1);
	ft_strcat(ret, tmp);
	ft_strcat(ret, year);
	free(tmp);
	free(year);
	return (ret);
}
