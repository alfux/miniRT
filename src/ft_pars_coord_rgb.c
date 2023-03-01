/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_coord_rgb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:23:33 by efunes            #+#    #+#             */
/*   Updated: 2023/03/01 15:13:18 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static int	ft_coord_format(char *str, char nb, char digit)
{
	while (*str && nb < 3)
	{
		digit = 0;
		if (*str && *str == '-')
			str++;
		while (*str && ft_isdigit(*str) && ++digit)
			str++;
		if (*str && *str == '.')
		{
			digit = 0;
			str++;
		}
		while (*str && ft_isdigit(*str) && ++digit)
			str++;
		nb++;
		if (*str && *str == ',')
			str++;
		if (nb != 3 && ((!ft_isdigit(*str) && *str != '-' && *str != '+')
				|| !digit))
			return (1);
	}
	if (nb != 3 || !(*str) || !ft_isspace(*str))
		return (1);
	return (0);
}

int	ft_coord(t_vec *vec, char **str)
{
	while (**str && ft_isspace(**str))
		(*str)++;
	if (ft_coord_format(*str, 0, 0))
		return (4);
	vec->x = ft_atof(*str);
	while (**str && (ft_isdigit(**str) || **str == '.' || **str == '-'))
		(*str)++;
	vec->y = ft_atof(++*str);
	while (**str && (ft_isdigit(**str) || **str == '.' || **str == '-'))
		(*str)++;
	vec->z = ft_atof(++*str);
	while (**str && (ft_isdigit(**str) || **str == '.' || **str == '-'))
		(*str)++;
	while (**str && ft_isspace(**str))
		(*str)++;
	return (0);
}

static int	ft_rgb_format(char *str)
{
	char	nb;
	char	digit;

	nb = 0;
	while (*str && nb < 3)
	{
		digit = 0;
		while (*str && ft_isdigit(*str) && ++digit)
			str++;
		nb++;
		if (*str && *str == ',')
			str++;
		if (*str == '-' || (nb != 3 && (!ft_isdigit(*str) || !digit)))
			return (1);
	}
	while (*str && ft_isspace(*str))
		str++;
	if (nb != 3)
		return (1);
	return (0);
}

static int	ft_opacity(t_rgb *rgb, char **str)
{
	int	op;

	if (**str != ',')
		rgb->a = 255;
	else
	{
		(*str)++;
		op = ft_atoi(*str);
		if (op > 255 || op < 0)
			return (5);
		rgb->a = op;
		while (**str && ft_isdigit(**str))
		(*str)++;
	}
	while (**str && ft_isspace(**str))
		(*str)++;
	return (0);
}

int	ft_rgb(t_rgb *rgb, char **str)
{
	int	tmp[3];

	while (**str && ft_isspace(**str))
		(*str)++;
	if (ft_rgb_format(*str))
		return (5);
	tmp[0] = ft_atoi(*str);
	while (**str && ft_isdigit(**str))
		(*str)++;
	tmp[1] = ft_atoi(++*str);
	while (**str && ft_isdigit(**str))
		(*str)++;
	tmp[2] = ft_atoi(++*str);
	while (**str && ft_isdigit(**str))
		(*str)++;
	if (tmp[0] > 255 || tmp[1] > 255 || tmp[2] > 255
		|| tmp[0] < 0 || tmp[1] < 0 || tmp[2] < 0)
		return (5);
	rgb->r = (unsigned char)tmp[0];
	rgb->g = (unsigned char)tmp[1];
	rgb->b = (unsigned char)tmp[2];
	return (ft_opacity(rgb, str));
}
