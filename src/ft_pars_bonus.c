/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:31:16 by efunes            #+#    #+#             */
/*   Updated: 2023/03/01 16:09:07 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	ft_orthonormal_basis(t_3x3 *bas, char **str)
{
	if (ft_coord(&bas->top, str))
		return (1);
	if (ft_coord(&bas->mid, str))
		return (1);
	bas->mid = ft_dif_uv(bas->mid, ft_multlv(ft_scalar(bas->top, bas->mid)
				/ ft_norm(bas->top), ft_nrmlze(bas->top)));
	bas->top = ft_nrmlze(bas->top);
	bas->mid = ft_nrmlze(bas->mid);
	bas->bot = ft_provec(bas->top, bas->mid);
	*bas = ft_set3x3(bas->mid, bas->bot, bas->top);
	return (0);
}

int	ft_pars_color_disturb(t_dam *dam, char **str)
{
	if (ft_orthonormal_basis(&dam->bas, str))
		return (17);
	if (dam->bas.bot.x == 0 && dam->bas.bot.y == 0 && dam->bas.bot.z == 0)
		return (20);
	if (ft_pars_double(&dam->size, str))
		return (17);
	if (dam->size <= 0)
		return (17);
	dam->size = M_PI * dam->size;
	if (ft_rgb(&dam->col, str))
		return (17);
	return (0);
}

int	ft_pars_bumpmap(t_win *window, t_bmp *b, char **str)
{
	size_t	i;
	char	*name;

	if (ft_orthonormal_basis(&b->bas, str))
		return (18);
	if (b->bas.bot.x == 0 && b->bas.bot.y == 0 && b->bas.bot.z == 0)
		return (20);
	if (ft_pars_double(&b->size, str) || ft_pars_double(&b->relief, str))
		return (18);
	i = 0;
	while ((*str)[i] && !ft_isspace((*str)[i]))
		i++;
	if (i < 4 || (*str)[i - 4] != '.' || (*str)[i - 3] != 'x'
			|| (*str)[i - 2] != 'p' || (*str)[i - 1] != 'm')
		return (19);
	name = ft_substr(*str, 0, i);
	*str += ft_strlen(name);
	if (!name)
		return (19);
	b->map.iid = mlx_xpm_file_to_image(window->cid, name, &b->map.w, &b->map.h);
	if (!ft_free(name) && b->map.iid == NULL)
		return (19);
	b->map.iad = mlx_get_data_addr(b->map.iid, &b->map.bpp, &b->map.opl,
			&b->map.end);
	return (0);
}

int	ft_bonus_param(t_win *window, t_sdb *bns, char *str)
{
	t_vec	sdb;
	int		err;

	if (ft_coord(&sdb, &str) || (sdb.x != 0 && sdb.x != 1)
		|| (sdb.y != 0 && sdb.y != 1) || (sdb.z != 0 && sdb.z != 1))
		return (21);
	err = 0;
	if (sdb.x)
		if (ft_pars_double(&(bns->spc.siz), &str)
			|| ft_pars_double(&(bns->spc.har), &str))
			return (22);
	if (!err && sdb.y)
		err = ft_pars_bumpmap(window, &bns->bmp, &str);
	if (!err && sdb.z)
		err = ft_pars_color_disturb(&bns->dam, &str);
	if (err)
		return (22);
	return (err);
}
