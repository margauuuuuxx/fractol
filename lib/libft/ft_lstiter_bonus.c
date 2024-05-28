/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:50:59 by marlonco          #+#    #+#             */
/*   Updated: 2024/04/11 12:30:37 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst)
	{
		(f)(lst->content);
		lst = lst->next;
	}
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
void	ft_test(void *)
{
	str[i] += 1;
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