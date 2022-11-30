/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:52:57 by alfux             #+#    #+#             */
/*   Updated: 2022/11/30 14:06:26 by alfux            ###   ########.fr       */
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
