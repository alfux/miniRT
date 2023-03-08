/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setcam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:42:47 by alfux             #+#    #+#             */
/*   Updated: 2023/03/08 15:43:21 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static int	ft_sign(double x)
{
	if (x >= 0)
		return (1);
	else
		return (-1);
}

void	ft_setcam(t_cam *cam)
{
	double	norm;

	if (cam->dir.x != 0 || cam->dir.z != 0)
	{
		cam->dir = ft_nrmlze(cam->dir);
		norm = sqrt(cam->dir.x * cam->dir.x + cam->dir.z * cam->dir.z);
		cam->hor = ft_setvec(cam->dir.z / norm, 0, ((-1) * cam->dir.x) / norm);
		cam->ver = ft_setvec(((-1) * cam->dir.x * cam->dir.y) / norm, norm,
				((-1) * cam->dir.y * cam->dir.z) / norm);
	}
	else if (cam->dir.y != 0)
	{
		cam->dir = ft_setvec(0, ft_sign(cam->dir.y), 0);
		cam->ver = ft_setvec(0, 0, 1);
		cam->hor = ft_setvec(ft_sign((-1) * cam->dir.y), 0, 0);
	}
	else
		ft_bzero(&cam->dir, sizeof (t_cam));
	cam->fov = (cam->fov * 2 * M_PI) / 360;
}

static int	ft_valid_cam(t_cam *new, char **str)
{
	size_t	i;

	i = 0;
	if (ft_coord(&new->pov, str))
		return (4);
	if (ft_coord(&new->dir, str))
		return (4);
	if (new->dir.x < -1 || new->dir.x > 1 || new->dir.y < -1 || new->dir.y > 1
		|| new->dir.z < -1 || new->dir.z > 1)
		return (9);
	while ((*str)[i] && ft_isdigit((*str)[i]))
		i++;
	new->fov = ft_atoi(*str);
	if (!i || ((*str)[i] && !ft_isspace((*str)[i]))
		|| new->fov > 180 || new->fov < 0)
		return (8);
	*str += i;
	while (**str && ft_isspace(**str))
		(*str)++;
	if (**str)
		return (9);
	return (0);
}

int	ft_pars_cam(t_cam **cam, char *str)
{
	t_cam	*new;
	t_cam	*tmp;
	int		err;

	new = ft_calloc(1, sizeof(t_cam));
	if (!new)
		return (6);
	err = ft_valid_cam(new, &str);
	if (err)
	{
		free(new);
		return (err);
	}
	new->next = new;
	new->prev = new;
	if (!(*cam))
		*cam = new;
	tmp = (*cam)->next;
	(*cam)->next = new;
	new->next = tmp;
	new->prev = *cam;
	if ((*cam)->prev == (*cam))
		(*cam)->prev = new;
	ft_setcam(new);
	return (0);
}
