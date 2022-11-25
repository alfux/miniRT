/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:12:34 by alfux             #+#    #+#             */
/*   Updated: 2022/11/25 22:45:31 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

int	main(void)
{
	t_win	win;
	t_img	scr[2];
	size_t	i;
	size_t	j;

	win = ft_init_win(600, 590, "miniRT", scr);
	scr[1].iid = (void *)0;
	scr[0].iid = mlx_new_image(win.cid, 600, 590);
	scr[0].iad = mlx_get_data_addr(scr[0].iid, &scr[0].bpp, &scr[0].opl,
			&scr[0].end);
	i = -1;
	while (++i < 590)
	{
		j = -1;
		while (++j < 600)
			*(unsigned int *)(scr->iad + i * scr->opl + j * (scr->bpp / 8))
				= (i + j) * ((i + j) % 2) + (i + j) * 256 * ((i + j + 1) % 2);
	}
	mlx_hook(win.wid, 17, 0L, &ft_exit_success, &win);
	mlx_hook(win.wid, 2, 0L, &ft_keyhook, &win);
	mlx_put_image_to_window(win.cid, win.wid, win.img[0].iid, 0, 0);
	mlx_loop(win.cid);
	return (0);
}
