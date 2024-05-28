/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:34:42 by marlonco          #+#    #+#             */
/*   Updated: 2024/04/16 16:31:01 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
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
	t_list	*last;

	lst0 = malloc(sizeof(t_list));
	lst1 = malloc(sizeof(t_list));
	lst2 = malloc(sizeof(t_list));
	last = malloc(sizeof(t_list));
	if (lst0 == NULL || lst1 == NULL || lst2 == NULL || last == NULL)
		return (NULL);
	lst0->content = "0";
	lst0->next = lst1;
	lst1->content = "1";
	lst1->next = lst2;
	lst2->content = "8";
	lst2->next = NULL;
	last = ft_lstlast(lst0);
	ft_print_list(last);
	return (0);
}
*/