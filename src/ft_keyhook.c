/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:17:07 by alfux             #+#    #+#             */
/*   Updated: 2022/11/25 22:21:52 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

int	ft_keyhook(int kid, t_win *win)
{
	printf("Keycode: %i\n", kid);
	if (kid == K_ESCAPE)
		return (ft_exit(win, 0));
	return (0);
}
