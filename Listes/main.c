/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/12 18:32:34 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 20:05:42 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "list.h"

void	nouveau_element_debut(t_list **liste, char *str)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		exit(printf("malloc failed\n"));
	new->str = malloc(sizeof(strlen(str)));
	strcat(new->str, str);
	new->next = *liste;
	*liste = new;
}

void	initialisation(t_list *list)
{
//	list->nb = 9;
	list->next = NULL;
}

void	afficher(t_list *liste)
{
	t_list	*tmp;

	tmp = liste;
	while (tmp)
	{
		printf("%s\n", tmp->str);
		tmp = tmp->next;
	}
}

void	del(t_list *liste)
{
	while(liste->next)
	{
		free(liste->str);
		free(liste);
		liste = liste->next;
	}
}

int		main(void)
{
	t_list	*liste;
	t_list	*tmp;

	initialisation(liste);
	nouveau_element_debut(&liste, "bonjour");
	nouveau_element_debut(&liste, "les");
	nouveau_element_debut(&liste, "amis");
	nouveau_element_debut(&liste, "?");
	afficher(liste);
	del(liste);
	return (0);
}
