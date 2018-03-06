#include "ft_ls.h"

void		ft_etat_flag(t_flag *flag)
{
	printf("l : %d\n", flag->l);
	printf("R : %d\n", flag->R);
	printf("r : %d\n", flag->r);
	printf("a : %d\n", flag->a);
	printf("t : %d\n", flag->t);
}

static void	ft_flag(char *str, t_flag *flag)
{
	int	i;

	i = 0;
	str++;
	while (str[i])
	{
		if (str[i] == 'l')
			flag->l = 1;
		else if (str[i] == 'R')
			flag->R = 1;
		else if (str[i] == 'r')
			flag->r = 1;
		else if (str[i] == 'a')
			flag->a = 1;
		else if (str[i] == 't')
			flag->t = 1;
		i++;
	}
}

int		main(int ac, char **av)
{
	int	i;
	t_flag	flag;

	i = 1;
	ft_init(&flag);
	while (i < ac)
	{
		if (ft_strchr(av[i], '-') != 0 && av[i][1] != '\0')
			ft_flag(av[i], &flag);
		i++;
	}
	ft_etat_flag(&flag);
	return (0);
}
