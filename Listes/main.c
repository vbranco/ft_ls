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

void	nouveau_element_trie_nliste(n_list **nliste, int n)
{
	n_list	*new;
	n_list	*tmp = NULL;
	n_list	*ll;

	ll = *nliste;
	new = malloc(sizeof(n_list));
	if (!new)
		exit(1);
	while (ll && ll->nb < n)
	{
		tmp = ll;
		ll = ll->next;
	}
	new->nb = n;
	new->next = ll;
	if (tmp)
		tmp->next = new;
	else
		*nliste = new;
}

void	del_nliste(n_list *nlist)
{
	nlist = nlist->next;
	while (nlist)
	{
		free(nlist);
		nlist = nlist->next;
	}
}

void	initialisation_nliste(n_list *nliste)
{
	nliste->next = NULL;
}

void	afficher_nliste(n_list *nliste)
{
	while (nliste)
	{
		printf("%d\n", nliste->nb);
		nliste = nliste->next;
	}
}

void	sort(n_list **nliste)
{
	n_list	*tmp;

	tmp = *nliste;
}

int		main(void)
{
//	t_list	*liste;
	n_list *nliste;

//	initialisation(liste);
	initialisation_nliste(nliste);
	nouveau_element_trie_nliste(&nliste, 5);
	nouveau_element_trie_nliste(&nliste, 1);
	nouveau_element_trie_nliste(&nliste, 4);
	nouveau_element_trie_nliste(&nliste, 3);
	nouveau_element_trie_nliste(&nliste, 2);
/*	nouveau_element_debut(&liste, "bonjour");
	nouveau_element_debut(&liste, "les");
	nouveau_element_debut(&liste, "amis");
	nouveau_element_debut(&liste, "?");
	afficher(liste);
*/	afficher_nliste(nliste);
//	del(liste);
	sort(&nliste);
//	afficher_nliste(nliste);
//	del_nliste(nliste);
	return (0);
}
