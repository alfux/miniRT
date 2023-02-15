/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:52:57 by alfux             #+#    #+#             */
/*   Updated: 2023/01/06 17:16:33 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	ft_objclear(t_obj **obj, void (*del)(void *))
{
	if (!obj || !*obj)
		return ;
	ft_objclear(&(**obj).next, del);
	if ((**obj).type == 'I')
		ft_objdelone(*obj, (void (*)(void *))(&ft_delimp));
	else
		ft_objdelone(*obj, del);
	*obj = (t_obj *)0;
}

void	ft_camclear(t_cam **cam, void (*del)(void *))
{
	if (!cam || !*cam)
		return ;
	if (((*cam)->prev))
		((*cam)->prev)->next = NULL;
	ft_camclear(&(**cam).next, del);
	(*del)(*cam);
	*cam = (t_cam *)0;
}
