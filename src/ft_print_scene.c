/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:34:54 by alfux             #+#    #+#             */
/*   Updated: 2022/12/20 16:52:16 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

static void	ft_print_sphere(t_sph sph)
{
	printf("\t\tSphere\n\t\t\tdia: %f\n\t\t", sph.dia);
	printf("\tpos: (%f, %f, %f)\n", sph.pos.x, sph.pos.y, sph.pos.z);
	printf("\t\t\tcol: [%i, %i, %i]\n", sph.col.r, sph.col.g, sph.col.b);
}

static void	ft_print_plane(t_pla pla)
{
	printf("\t\tPlane\n\t\t\tpos: ");
	printf("(%f, %f, %f)\n\t\t\t", pla.pos.x, pla.pos.y, pla.pos.z);
	printf("dir: (%f, %f, %f)\n", pla.dir.x, pla.dir.y, pla.dir.z);
	printf("\t\t\tcol: [%i, %i, %i]\n", pla.col.r, pla.col.g, pla.col.b);
}

static void	ft_print_cylinder(t_cyl cyl)
{
	printf("\t\tCylinder\n\t\t\tpos: ");
	printf("(%f, %f, %f)\n\t\t\t", cyl.pos.x, cyl.pos.y, cyl.pos.z);
	printf("dir: (%f, %f, %f)\n", cyl.dir.x, cyl.dir.y, cyl.dir.z);
	printf("\t\t\tcol: [%i, %i, %i]\n", cyl.col.r, cyl.col.g, cyl.col.b);
	printf("\t\t\tdia: %f\n\t\t\thgt: %f\n", cyl.dia, cyl.hgt);
}

static void	ft_print_obj(t_obj *obj)
{
	if (!obj)
		return ;
	if (obj->type == 'S')
		ft_print_sphere(*(t_sph *)obj->obj);
	else if (obj->type == 'P')
		ft_print_plane(*(t_pla *)obj->obj);
	else if (obj->type == 'C')
		ft_print_cylinder(*(t_cyl *)obj->obj);
}

void	ft_print_scene(t_scn scn)
{
	printf("\tcam\n\t\tpov: (%.1f, %.1f, %.1f)\n", scn.cam->pov.x,
		scn.cam->pov.y, scn.cam->pov.z);
	printf("\t\tdir: (%f, %f, %f)\n", scn.cam->dir.x, scn.cam->dir.y,
		scn.cam->dir.z);
	printf("\t\tver: (%f, %f, %f)\n", scn.cam->ver.x, scn.cam->ver.y,
		scn.cam->ver.z);
	printf("\t\thor: (%f, %f, %f)\n\t\tfov: %f\n", scn.cam->hor.x,
		scn.cam->hor.y, scn.cam->hor.z, scn.cam->fov);
	printf("\tamb\n\t\trat: %f\n\t\tcol: [%i, %i, %i]\n", scn.amb.rat,
		scn.amb.col.r, scn.amb.col.g, scn.amb.col.b);
	while (scn.lig)
	{
		printf("\tlights\n\t\tpos: (%f, %f, %f)\n\t\trat: %f\n",
			((t_lig *)scn.lig->obj)->pos.x, ((t_lig *)scn.lig->obj)->pos.y,
			((t_lig *)scn.lig->obj)->pos.z, ((t_lig *)scn.lig->obj)->rat);
		printf("\t\tcol: [%i, %i, %i]\n", ((t_lig *)scn.lig->obj)->col.r,
			((t_lig *)scn.lig->obj)->col.g, ((t_lig *)scn.lig->obj)->col.b);
		scn.lig = scn.lig->next;
	}
	printf("\tObjects\n");
	while (scn.obj)
	{
		ft_print_obj(scn.obj);
		scn.obj = scn.obj->next;
	}
}
