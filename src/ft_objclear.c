/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:52:57 by alfux             #+#    #+#             */
/*   Updated: 2023/03/08 15:33:29 by efunes           ###   ########.fr       */
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

static void	ft_camclr(t_cam **cam, void (*del)(void *))
{
	if (!cam || !*cam)
		return ;
	ft_camclr(&(**cam).next, del);
	(*del)(*cam);
	*cam = (t_cam *)0;
}

void	ft_camclear(t_cam **cam, void (*del)(void *))
{
	if (*cam)
		(*cam)->prev->next = (void *)0;
	ft_camclr(cam, del);
}
