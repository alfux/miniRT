/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:45:34 by alfux             #+#    #+#             */
/*   Updated: 2023/01/05 16:04:29 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	ft_lstrem(t_list **lst, t_list *rem)
{
	if (!lst || !*lst || !rem)
		return ;
	while (*lst)
	{
		if (*lst == rem)
		{
			*lst = rem->next;
			ft_lstdelone(rem, &free);
			return ;
		}
		lst = &(*lst)->next;
	}
}
