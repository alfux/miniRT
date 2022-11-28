/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:15:04 by alfux             #+#    #+#             */
/*   Updated: 2022/11/28 12:59:44 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINIRT_H
# define MINIRT_H
# include <stdio.h>
# include <sys/errno.h>
# include <mlx.h>
# include <libft.h>
# include <dataRT.h>

//Structure filling functions
t_win	ft_setwin(int width, int height, char *title, t_img *image_tab);
t_vec	ft_setvec(float x, float y, float z);
t_rgb	ft_setrgb(unsigned char r, unsigned char g, unsigned char b);
t_amb	ft_setamb(float rat, t_rgb col);
t_cam	ft_setcam(t_vec pov, t_vec n, unsigned char fov);
t_lig	ft_setlig(t_vec pos, float rat, t_rgb col);
t_sph	ft_setsph(float dia, t_vec pos, t_rgb col);
t_pla	ft_setpla(t_vec pos, t_vec n, t_rgb col);
t_cyl	ft_setcyl(t_vec pos, t_vec n, float dia, float hgt);

int		ft_exit_success(t_win *win);
int		ft_exit_failure(t_win *win);
int		ft_exit(t_win *win, int status);
int		ft_keyhook(int kid, t_win *win);

#endif
