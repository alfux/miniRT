/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:12:34 by alfux             #+#    #+#             */
/*   Updated: 2023/02/04 12:27:54 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	main(int argc, char **argv)
{
	t_win	window;
	t_sph	*sph;
//	t_imp	*imp;
//	t_obj	*tmp;

	(void)argc;
	window = ft_setwin(RESOLUTION, (RESOLUTION * 9) / 16, "miniRT");
	if (argc < 2 || ft_pars(&window, argv[1]))
		return (ft_exit(&window, 1));
	ft_setcam(window.scn.cam);
	sph = (t_sph *)window.scn.obj->obj;
	sph->spc.siz = 0.1;
	sph->spc.har = 2;
	sph->bas.top = ft_nrmlze(ft_setvec(1, 0, 0));
	sph->bas.bot = ft_nrmlze(ft_setvec(0, 1, 1));
	sph->bas.mid = ft_nrmlze(ft_provec(sph->bas.bot, sph->bas.top));
	sph->co2 = ft_setrgb(0, 0, 0);
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
