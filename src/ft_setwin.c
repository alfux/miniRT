/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setwin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:23:07 by alfux             #+#    #+#             */
/*   Updated: 2022/11/28 13:01:01 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

t_win	ft_setwin(int width, int height, char *title, t_img *image_tab)
{
	t_win	win;

	win.cid = mlx_init();
	win.wid = mlx_new_window(win.cid, width, height, title);
	win.scr = image_tab;
	return (win);
}
