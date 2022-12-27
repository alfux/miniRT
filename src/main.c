/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:12:34 by alfux             #+#    #+#             */
/*   Updated: 2022/12/27 15:56:07 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#define RESOLUTION 300

int	main(int argc, char **argv)
{
	t_win	window;

	(void)argc;
	window = ft_setwin(RESOLUTION, (RESOLUTION * 9) / 16, "miniRT");
	if (argc < 2 || ft_pars(&window, argv[1]))
		return (ft_exit(&window, 1));
	ft_setcam(window.scn.cam);
	(void)mlx_hook(window.wid, 17, 0L, &ft_exit_success, &window);
	(void)mlx_hook(window.wid, 4, 1L << 2, &ft_mousehook, &window);
	(void)mlx_hook(window.wid, 2, 0L, &ft_keyhook, &window);
	ft_print_scene(window.scn);
	ft_render(&window, HIGHRES);
	(void)mlx_loop(window.cid);
	return (0);
}
