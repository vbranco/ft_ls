#include "ft_ls.h"

int     ft_count_args(int ac, char **av)
{
	int             i;
	int             z;

	i = 1;
	z = 0;
	while (i < ac)
	{
		if (av[i][0] == '-')
		{
//			if (av[i][1] == '-')
				z++;
		}
		i++;
	}
	return (z + 1);
}
