/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:40:56 by csaunier          #+#    #+#             */
/*   Updated: 2023/03/28 17:41:52 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*new;
	t_list	*tmp;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	ptr = lst;
	new = ft_lstnew((*f)(ptr->content));
	if (!new)
		return (NULL);
	ptr = ptr->next;
	while (ptr)
	{
		tmp = ft_lstnew((*f)(ptr->content));
		if (!tmp)
			ft_lstclear(&new, del);
		ft_lstadd_back(&new, tmp);
		ptr = ptr->next;
	}
	return (new);
}
