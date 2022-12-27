/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:52:57 by alfux             #+#    #+#             */
/*   Updated: 2022/12/27 16:30:39 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	ft_objclear(t_obj **obj, void (*del)(void *))
{
	if (!obj || !*obj)
		return ;
	ft_objclear(&(**obj).next, del);
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
