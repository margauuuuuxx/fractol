/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:05:01 by marlonco          #+#    #+#             */
/*   Updated: 2024/04/11 12:33:07 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
	lst = NULL;
}
/*
void	ft_print_list(t_list *lst)
{
	t_list	*current;

	current = lst;
	while (current != NULL)
	{
		printf("%s\n",(current->content));
		current = current->next;
	}
}
int	main(void)
{
	t_list	*lst0;
	t_list	*lst1;
	t_list	*lst2;

	lst0 = malloc(sizeof(t_list));
	lst1 = malloc(sizeof(t_list));
	lst2 = malloc(sizeof(t_list));
	if (lst0 == NULL || lst1 == NULL || lst2 == NULL)
		return (NULL);
	lst0->content = "0";
	lst0->next = lst1;
	lst1->content = "1";
	lst1->next = lst2;
	lst2->content = "8";
	lst2->next = NULL;
	printf("initial list: \n");
	ft_print_list(lst0);
	printf("\n");
	ft_lstdelone(lst0, (lst0->content));
	ft_print_list(lst0);
	return (0);
}
*/