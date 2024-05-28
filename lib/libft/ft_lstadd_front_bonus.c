/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:17:47 by marlonco          #+#    #+#             */
/*   Updated: 2024/04/10 16:16:44 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = (*lst);
	(*lst) = new;
}
/*
void	ft_print_list(t_list **lst)
{
	t_list	*current;

	current = lst[0];
	while (current != NULL)
	{
		printf("%s\n",(current->content));
		current = current->next;
	}
}
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
	lst[0]->content = "1";
	lst[0]->next = lst[1];
	lst[1]->content = "2";
	lst[1]->next = NULL;
	new->content = "new";
	printf("Initial list: ");
	ft_print_list(lst);
	printf("x\n");
	ft_lstadd_front(lst, new);
	ft_print_list(lst);
	return (0);
}
*/