#include "ft_ls.h"

void            ft_args(char **av, t_flag *flag, t_node **node)
{
	int     i;

	i = 1;
	if (flag->ac == 1)
		ft_node_front_add(node, ".", 1);
	else
	{
		if (ft_flag_status(flag) == 0)
		{
			while (i < flag->ac)
			{
				ft_node_sort_add(node, av[i], ft_strlen(av[i]));
				i++;
			}
		}
		else
		{
			i = ft_count_args(flag->ac, av);
			while (i < flag->ac)
			{
				ft_node_sort_add(node, av[i], ft_strlen(av[i]));
				i++;
			}

		}
	}
}
