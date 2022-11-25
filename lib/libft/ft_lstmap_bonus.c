/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:51:06 by afuchs            #+#    #+#             */
/*   Updated: 2022/03/02 15:36:14 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*buffer;

	if (!lst)
		return ((t_list *)0);
	buffer = ft_calloc(1, sizeof(t_list));
	if (!buffer)
		return ((t_list *)0);
	(*buffer).content = (*f)((*lst).content);
	if (!(*lst).next)
		(*buffer).next = (t_list *)0;
	else
	{
		(*buffer).next = ft_lstmap((*lst).next, f, del);
		if (!(*buffer).next)
			ft_lstclear(&buffer, del);
	}
	return (buffer);
}
