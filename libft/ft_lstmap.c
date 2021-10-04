/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalman <mbalman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 18:30:02 by mbalman           #+#    #+#             */
/*   Updated: 2021/04/27 19:12:17 by mbalman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list 	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*p;

	new = NULL;
	while (lst && f)
	{
		p = ft_lstnew(f(lst->content));
		if (!p)
		{
			ft_lstclear(&new, del);
			break ;
		}
		ft_lstadd_back(&new, p);
		lst = lst->next;
	}
	return (new);
}
