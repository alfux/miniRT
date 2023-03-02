/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sellig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:51:13 by alfux             #+#    #+#             */
/*   Updated: 2023/03/02 16:28:16 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_obj	*ft_sellig(t_obj const *cur, t_obj const *lig)
{
	t_obj	*i;

	if (!cur)
		return ((t_obj *)lig);
	i = (t_obj *)lig;
	while (i && i != cur)
		i = i->next;
	if (!i || !i->next)
		return ((t_obj *)lig);
	return ((t_obj *)i->next);
}
