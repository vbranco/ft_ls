#include "ft_ls.h"

static int test(t_fileinfo *file)
{
	if (file->amode == 'd')
	{
		if (file->mode[7] == 'w')
		{
			if (file->mode[8] == 't' || file->mode[8] == 'T')
				return (10);
			else
				return (11);
		}
		else
			return (1);
	}
	else if (S_ISREG(file->st.st_mode))
	{
		if (file->mode[2] == 's')
			return (8);
		else if (file->mode[5] == 's')
			return (9);
		else if (file->mode[2] != 'x' && file->mode[5] != 'x' && file->mode[8] != 'x')
			return (0);
		else if (file->mode[2] != '-' || file->mode[5] != '-' || file->mode[8] != '-')
			return (5);
	}
	return (0);
}

void    color(t_fileinfo *file)
{
	if (test(file) == 1)
		printf("%s%s%s", TCYAN, file->name, TSTOP);
	else if (file->amode == 'l')
		printf("%s%s%s", TMAGENTA, file->name, TSTOP);
	else if (file->amode == 's')
		printf("%s%s%s", TGREEN, file->name, TSTOP);
	else if (file->amode == 'p')
		printf("%s%s%s", TYELLOW, file->name, TSTOP);
	else if (file->amode == 'b')
		printf("%s%s%s%s", TBLUE, BCYAN, file->name, TSTOP);
	else if (file->amode == 'c')
		printf("%s%s%s%s", TBLUE, BYELLOW, file->name, TSTOP);
	else if (test(file) == 5)
		printf("%s%s%s", TRED, file->name, TSTOP);
	else if (test(file) == 8)
		printf("%s%s%s%s", TBLACK, BRED, file->name, TSTOP);
	else if (test(file) == 9)
		printf("%s%s%s%s", TBLACK, BCYAN, file->name, TSTOP);
	else if (test(file) == 10)
		printf("%s%s%s%s", TBLACK, BGREEN, file->name, TSTOP);
	else if (test(file) == 11)
		printf("%s%s%s%s", TBLACK, BYELLOW, file->name, TSTOP);
	else
		printf("%s", file->name);
}

void	flag_o_g(t_fileinfo *file, t_space *sp, t_flag *flag)
{
	if (flag->l && !flag->o && !flag->g)
		printf("%-*s  %-*s  ", sp->size_pname, file->pw_name, sp->size_gname, file->gr_name);
	else
	{
		if (flag->o && !flag->g)
			printf("%-*s  ", sp->size_pname, file->pw_name);
		else if (!flag->o && flag->g)
			printf("%-*s  ", sp->size_gname, file->gr_name);
		else
			printf("  ");
	}
}

void    printl(t_fileinfo *file, t_space *sp, t_flag *flag)
{
	printf("%c%s %*i ", file->amode, file->mode, sp->size_nlink,
			file->st.st_nlink);
	flag_o_g(file, sp, flag);
	if (file->amode == 'b' || file->amode == 'c')
		printf(" %*i, %*i ", sp->size_madev, file->maj, sp->size_midev, file->min);
	else
	{
		if (sp->size_midev != 0 || sp->size_madev != 0)
			printf("%*lli ", (sp->size_madev + sp->size_midev + sp->size_stsize-1),
					file->st.st_size);
		else
			printf("%*lli ", (sp->size_stsize), file->st.st_size);
	}
	printf("%s ", file->time);
	if (flag->G == 1)
		color(file);
	else
		printf("%s", file->name);
	if (file->amode == 'l')
	{
		printf(" -> %s\n", file->link);
	}
	else
		printf("\n");
}

int ft_total(t_fileinfo *file)
{
	int     total;

	total = 0;
	while (file)
	{
		total += file->total;
		file = file->next;
	}
	return (total);
}
