/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:15:04 by alfux             #+#    #+#             */
/*   Updated: 2022/12/09 11:53:34 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINIRT_H
# define MINIRT_H
# include <stdio.h>
# include <sys/errno.h>
# include <mlx.h>
# include <libft.h>
# include <dataRT.h>
# include <math.h>

//Structure filling
t_win		ft_setwin(int width, int height, char *title);
t_win		ft_tobase_cam(t_win win);
t_vec		ft_setvec(float x, float y, float z);
t_rgb		ft_setrgb(unsigned char r, unsigned char g, unsigned char b);
t_amb		ft_setamb(float rat, t_rgb col);
t_cam		ft_setcam(t_vec pov, t_vec dir, unsigned char fov);
t_lin		ft_setlin(t_vec pos, t_vec dir);
t_3x3		ft_set3x3(t_vec lft, t_vec mid, t_vec rgt);
t_2x3		ft_set2x3(t_vec top, t_vec bot);

//Object allocation
t_lig		*ft_newlig(t_vec pos, float rat, t_rgb col);
t_sph		*ft_newsph(float dia, t_vec pos, t_rgb col);
t_pla		*ft_newpla(t_vec pos, t_vec dir, t_rgb col);
t_cyl		*ft_newcyl(t_vec pos, t_vec dir, t_vec dh, t_rgb col);

//Object list manipulation
t_obj		*ft_objnew(char type, void *obj);
void		ft_objadd(t_obj **obj, t_obj *add);
void		ft_objdelone(t_obj *obj, void (*del)(void *));
void		ft_objclear(t_obj **obj, void (*del)(void *));

//Math tools
float		ft_scalar(t_vec u, t_vec v);
float		ft_distce(t_vec a, t_vec b);
float		ft_norm(t_vec u);
float		ft_det3x3(t_3x3 m);
t_3x3		ft_invmat(t_3x3 m);
t_vec		ft_nrmlze(t_vec v);
t_vec		ft_multlv(float l, t_vec v);
t_vec		ft_multmv(t_3x3 m, t_vec v);
t_vec		ft_sum_uv(t_vec u, t_vec v);
t_vec		ft_dif_uv(t_vec u, t_vec v);
t_vec		ft_polyd2(t_vec coef);
t_2x3		ft_sysres(t_vec const *dir, t_vec const *pov, t_obj const *obj);

//Other tools
int			ft_free(void *ptr);
uint32_t	ft_rgbtoi(t_rgb rgb);
void		ft_print_scene(t_scn scn);
void		ft_print_vect(t_vec v);
void		ft_print_inter_sph(t_vec ray, t_sph *sph, t_2x3 inter);

//Memory free exits
int			ft_exit_success(t_win *win);
int			ft_exit_failure(t_win *win, char const *msg);
int			ft_exit(t_win *win, int status);

//Key hooks
int			ft_keyhook(int kid, t_win *win);

//Rendering
void		ft_render(t_win const *win);
uint32_t	ft_raytra(t_win const *win, t_vec const ray, t_obj const *obj);
t_rgb		ft_shades(t_win const *win, t_obj const *obj, t_vec const *vec,
				t_rgb const *rgb);

#endif
