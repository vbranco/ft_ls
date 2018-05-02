/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/02 12:11:18 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/02 12:11:23 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *s1, char *s2)
{
	char	*tmp;

	if (!s1 || !s2)
		return (NULL);
	tmp = ft_strjoin(s1, s2);
	free(s1);
	return (tmp);
}
