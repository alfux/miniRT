/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:12:34 by alfux             #+#    #+#             */
/*   Updated: 2022/12/23 16:45:22 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#define RESOLUTION 1280

int	main(int argc, char **argv)
{
	t_win	window;

	(void)argc;
	window = ft_setwin(RESOLUTION, (RESOLUTION * 9) / 16, "miniRT");
	if (ft_pars(&window, argv[1]))//
		return (1); // destroy_img // destroy_windows // free memory struct win
		// OU
			// ft_bzero(&win, sizeof(t_win));
			// ft_pars
			// ft_setwin // sans bzero
	*window.scn.cam = ft_setcam(window.scn.cam->pov, window.scn.cam->dir, window.scn.cam->fov);
	(void)mlx_hook(window.wid, 17, 0L, &ft_exit_success, &window);
	(void)mlx_hook(window.wid, 2, 0L, &ft_keyhook, &window);
	ft_print_scene(window.scn);
	ft_render(&window);
	(void)mlx_loop(window.cid);
	return (0);
}
