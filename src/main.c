/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:12:34 by alfux             #+#    #+#             */
/*   Updated: 2023/02/13 19:46:54 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	main(int argc, char **argv)
{
	t_win	window;
	t_cyl	*pla;
//	t_imp	*imp;
//	t_obj	*tmp;

	(void)argc;
	window = ft_setwin(RESOLUTION, (RESOLUTION * 9) / 16, "miniRT");
	if (argc < 2 || ft_pars(&window, argv[1]))
		return (ft_exit(&window, 1));
	ft_setcam(window.scn.cam);
	pla = window.scn.obj->obj;
	pla->spc.siz = 0.1;
	pla->spc.har = 1;
	pla->bas = ft_set3x3(ft_setvec(0, 0, 1), ft_setvec(1, 0, 0), ft_setvec(0, 1, 0));
	pla->co2 = ft_setrgb(139, 108, 66);
//---------------TMP-FOR-TESTS-------------------------------------------------
//	imp = ft_getimp("models/tetrahedron.obj");
//	if (!imp)
//		ft_exit_failure(&window, "error: ");
//	imp->col = ft_setrgb(100, 100, 100);
//	tmp = ft_objnew('I', imp);
//	if (!tmp)
//	{
//		ft_delimp(imp);
//		ft_exit(&window, 1);
//	}
//	ft_objadd(&window.scn.obj, tmp);
//-----------------------------------------------------------------------------
	(void)mlx_hook(window.wid, 17, 0L, &ft_exit_success, &window);
	(void)mlx_hook(window.wid, 4, 1L << 2, &ft_mousehook, &window);
	(void)mlx_hook(window.wid, 2, 0L, &ft_keyhook, &window);
	ft_print_scene(window.scn);
	ft_render(&window);
	(void)mlx_loop(window.cid);
	return (0);
}
