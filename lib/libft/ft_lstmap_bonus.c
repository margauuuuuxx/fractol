/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:54:58 by marlonco          #+#    #+#             */
/*   Updated: 2024/04/17 09:27:45 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*new;
	void	*last_lst_content;

	if (!f || !del || !lst)
		return (NULL);
	result = NULL;
	while (lst)
	{
		last_lst_content = f(lst->content);
		new = ft_lstnew(last_lst_content);
		if (!(new))
		{
			del(last_lst_content);
			ft_lstclear(&result, (*del));
			return (NULL);
		}
		ft_lstadd_back(&result, new);
		lst = lst->next;
	}
	return (result);
}
