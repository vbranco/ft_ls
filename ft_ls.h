#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
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

typedef struct		s_flag
{
	int		l;
	int		R;
	int		r;
	int		a;
	int		t;
}			t_flag;

void			ft_init(t_flag *flag);

#endif
