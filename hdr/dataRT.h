/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dataRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:15:04 by alfux             #+#    #+#             */
/*   Updated: 2022/11/28 13:06:22 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef DATART_H
# define DATART_H

//Keycodes
# define K_ESCAPE 53

//Image data structure
struct					s_img
{
	void	*iid;
	char	*iad;
	int		bpp;
	int		opl;
	int		end;
};
typedef struct s_img	t_img;

//MLX session structure
struct					s_win
{
	void	*cid;
	void	*wid;
	t_img	*scr;
};
typedef struct s_win	t_win;

//Vetcor data structure
struct					s_vec
{
	float	x;
	float	y;
	float	z;
};
typedef struct s_vec	t_vec;

//Color data structure
struct					s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
};
typedef struct s_rgb	t_rgb;

//Ambiant light data structure
struct					s_amb
{
	float	rat;
	t_rgb	col;
};
typedef struct s_amb	t_amb;

//Camera data structure
struct					s_cam
{
	t_vec			pov;
	t_vec			n;
	unsigned char	fov;
};
typedef struct s_cam	t_cam;

//Light spot data structure
struct					s_lig
{
	t_vec	pos;
	float	rat;
	t_rgb	col;
};
typedef struct s_lig	t_lig;

//Sphere data structure
struct					s_sph
{
	float	dia;
	t_vec	pos;
	t_rgb	col;
};
typedef struct s_sph	t_sph;

//Plane data structre
struct					s_pla
{
	t_vec	pos;
	t_vec	n;
	t_rgb	col;
};
typedef struct s_pla	t_pla;

//Cylinder data structure
struct					s_cyl
{
	t_vec	pos;
	t_vec	n;
	float	dia;
	float	hgt;
	t_rgb	col;
};
typedef struct s_cyl	t_cyl;

//Straight line data structure
struct					s_lin
{
	t_vec	pos;
	t_vec	n;
};
typedef struct s_lin	t_lin;

#endif
