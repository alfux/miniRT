/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:42:50 by alfux             #+#    #+#             */
/*   Updated: 2022/11/30 18:32:27 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

void	ft_objdelone(t_obj *obj, void (*del)(void *))
{
	if (obj && del)
		(*del)(obj->content);
	if (obj)
		free(obj);
}
