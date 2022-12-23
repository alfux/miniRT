/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:15:04 by alfux             #+#    #+#             */
/*   Updated: 2022/12/23 15:42:50 by efunes           ###   ########.fr       */
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
# include <fcntl.h>

//Structure filling
int			ft_pars(t_win *win, char *arg);
t_win		ft_setwin(int width, int height, char *title);
t_win		ft_tobase_cam(t_win win);
t_vec		ft_setvec(float x, float y, float z);
t_rgb		ft_setrgb(unsigned char r, unsigned char g, unsigned char b);
t_amb		ft_setamb(float rat, t_rgb col);
int			ft_pars_amb(t_amb *amb, char **str);
t_cam		ft_setcam(t_vec pov, t_vec dir, unsigned char fov);
int			ft_pars_cam(t_cam **cam, char **str);
t_lin		ft_setlin(t_vec pos, t_vec dir);
t_3x3		ft_set3x3(t_vec lft, t_vec mid, t_vec rgt);
t_2x3		ft_set2x3(t_vec top, t_vec bot);

//Object allocation
t_lig		*ft_newlig(t_vec pos, float rat, t_rgb col);
int			ft_pars_light(t_obj **lig, char **str);
t_sph		*ft_newsph(float dia, t_vec pos, t_rgb col);
t_pla		*ft_newpla(t_vec pos, t_vec dir, t_rgb col);
int			ft_pars_pla(t_obj **obj, char **str);
t_cyl		*ft_newcyl(t_vec pos, t_vec dir, t_vec dh, t_rgb col);
int			ft_pars_cyl(t_obj **lig, char **str);

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
t_2x3		ft_syssph(t_vec const *dir, t_vec const *pov, t_sph const *sph);
t_2x3		ft_syspla(t_vec const *dir, t_vec const *pov, t_pla const *pla);
t_2x3		ft_syscyl(t_vec const *dir, t_vec const *pov, t_cyl const *cyl);
int			ft_is_sol(t_2x3 const *itr);

//Other tools
int			ft_free(void *ptr);
uint32_t	ft_rgbtoi(t_rgb rgb);
void		ft_print_scene(t_scn scn);
void		ft_print_vect(t_vec v);
void		ft_print_inter_sph(t_vec ray, t_sph *sph, t_2x3 inter);
int			ft_pars_float(float *shr, char **str);
int			ft_rgb(t_rgb *rgb, char **str);
int			ft_coord(t_vec *vec, char **str);

//Memory free exits
int			ft_exit_success(t_win *win);
int			ft_exit_failure(t_win *win, char const *msg);
int			ft_exit(t_win *win, int status);

//Key hooks
int			ft_keyhook(int kid, t_win *win);

//Rendering
void		ft_render(t_win const *win);
uint32_t	ft_raytra(t_win const *win, t_vec const *ray, t_obj const *obj);
int			ft_deadzn(t_2x3 *i, t_vec const *p, float dz);
float		ft_shdsph(t_win const *win, t_sph const *s, t_vec const *p);
float		ft_shdcyl(t_win const *win, t_cyl const *c, t_vec const *p);
float		ft_shdpla(t_win const *win, t_pla const *pl, t_vec const *p);
t_rgb		ft_shades(t_win const *win, t_obj const *obj, t_vec const *vec,
				t_rgb const *rgb);
int			ft_clside(t_vec const *i, t_vec const *p, t_vec const *n,
				t_vec const *l);

#endif
