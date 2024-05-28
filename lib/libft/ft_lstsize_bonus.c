/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:28:48 by marlonco          #+#    #+#             */
/*   Updated: 2024/04/10 16:19:29 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*current;

	i = 0;
	current = lst;
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
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
	lst2->content = "2";
	lst2->next = NULL;
	ft_print_list(lst0);
	printf("Size: %d", ft_lstsize(lst0));
	return (0);
}
*/