/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:22:34 by alfux             #+#    #+#             */
/*   Updated: 2022/12/30 17:22:53 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	ft_lstadd_new(t_list **lst, void *content)
{
	t_list	*tmp;

	tmp = ft_lstnew(content);
	if (!tmp)
		return (1);
	ft_lstadd_back(lst, tmp);
	return (0);
}
