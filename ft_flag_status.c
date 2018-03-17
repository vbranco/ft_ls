#include "ft_ls.h"

int	ft_flag_status(t_flag *flag)
{
	if (flag->l == 1)
		return (1);
	if (flag->R == 1)
		return (1);
	if (flag->r == 1)
		return (1);
	if (flag->a == 1)
		return (1);
	if (flag->t == 1)
		return (1);
	return (0);
}
