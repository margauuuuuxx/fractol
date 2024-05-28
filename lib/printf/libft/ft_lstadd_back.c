/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:58:01 by marlonco          #+#    #+#             */
/*   Updated: 2024/04/10 16:16:16 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = *lst;
	new->next = NULL;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

void	ft_print_list(t_list **lst)
{
	t_list	*current;

	current = lst[0];
	while (current != NULL)
	{
		printf("%s\n", (current->content));
		current = current->next;
	}
}
/*
int	main(void)
{
	t_list	**lst;
	t_list	*new;

	lst = NULL;
	new = NULL;
	lst = malloc(sizeof(t_list));
	new = malloc(sizeof(t_list));
	lst[0] = malloc(sizeof(char));
	lst[1] = malloc(sizeof(char));
	lst[0]->content = "0";
	lst[0]->next = lst[1];
	lst[1]->content = "1";
	lst[1]->next = NULL;
	new->content = "new";
	printf("Initial list:\n");
	ft_print_list(lst);
	printf("-------------\n");
	ft_lstadd_back(lst, new);
	ft_print_list(lst);
	return (0);
}
*/