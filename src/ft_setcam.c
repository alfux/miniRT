/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setcam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:42:47 by alfux             #+#    #+#             */
/*   Updated: 2022/12/23 09:22:23 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static int	ft_sign(float x)
{
	if (x >= 0)
		return (1);
	else
		return (-1);
}

t_cam	ft_setcam(t_vec pov, t_vec dir, unsigned char fov)
{
	t_cam	set;
	float	norm;

	if (dir.x != 0 || dir.z != 0)
	{
		norm = ft_norm(dir);
		set.dir = ft_setvec(dir.x / norm, dir.y / norm, dir.z / norm);
		norm = sqrt(set.dir.x * set.dir.x + set.dir.z * set.dir.z);
		set.hor = ft_setvec(set.dir.z / norm, 0, ((-1) * set.dir.x) / norm);
		set.ver = ft_setvec(((-1) * set.dir.x * set.dir.y) / norm, norm,
				((-1) * set.dir.y * set.dir.z) / norm);
	}
	else if (dir.y != 0)
	{
		set.dir = ft_setvec(0, ft_sign(dir.y), 0);
		set.ver = ft_setvec(0, 0, 1);
		set.hor = ft_setvec(ft_sign((-1) * dir.y), 0, 0);
	}
	else
		ft_bzero(&set, sizeof (t_cam));
	set.pov = pov;
	set.fov = (fov * 2 * M_PI) / 360;
	return (set);
}

//static int	ft_valid_cam(t_cam *new, char **str)
//{
//	size_t	i;
//
//	i = 0;
//	if (ft_coord(new->pov, str))
//		return (4);
//	if (ft_coord(new->dir, str))
//		return (4);
//	if (new->dir.x < -1 || new->dir.x > 1 || new->dir.y < -1 || new->dir.y > 1
//		|| new->dir.z < -1 || new->dir.z > 1)
//		return (7);
//	while ((*str)[i] && ft_isdigit((*str)[i]))
//		i++;
//	new->fov = ft_atoi(*str);
//	if (!i || ((*str)[i] && !ft_isspace((*str)[i])) || new->fov > 180)
//		return (8);
//	*str += i;
//	while (**str && ft_isspace(**str))
//		(*str)++;
//	if (**str)
//		return (9);
//	return (0);
//}
//
//int	ft_pars_cam(t_cam **cam, char **str)
//{
//	t_cam	*new;
//	t_cam	*tmp;
//	int		err;
//
//	new = malloc(sizeof(t_cam));
//	if (!new)
//		return (6);
//	err = ft_valid_cam(new, str);
//	if (err)
//	{
//		free(new);
//		return (err);
//	}
//	new->next = NULL;
//	new->prev = NULL;
//	if (!(*cam))
//		*cam = new;
//	if ((*cam)->next)
//		tmp = (*cam)->next;
//	else
//		tmp = *cam;
//	(*cam)->next = new;
//	new->next = tmp;
//	new->prev = *cam;
//	return (0);
//}
