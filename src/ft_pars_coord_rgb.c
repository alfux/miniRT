/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_coord_rgb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:23:33 by efunes            #+#    #+#             */
/*   Updated: 2022/12/23 14:26:11 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static int	ft_coord_format(char *str)
{
	char	nb;
	char	digit;

	nb = 0;
	while (*str && nb < 3)
	{
		digit = 0;
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
		if (nb != 3 && (!ft_isdigit(*str) || !digit))
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
	if (ft_coord_format(*str))
		return (4);
	vec->x = ft_atof(*str);
	while (**str && (ft_isdigit(**str) || **str == '.'))
		(*str)++;
	vec->y = ft_atof(*str);
	while (**str && (ft_isdigit(**str) || **str == '.'))
		(*str)++;
	vec->z = ft_atof(*str);
	while (**str && (ft_isdigit(**str) || **str == '.'))
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
		if (nb != 3 && (!ft_isdigit(*str) || !digit))
			return (1);
	}
	while (*str && ft_ispace(*str))
		str++;
	if (nb != 3 || *str)
		return (1);
	return (0);
}

int	ft_rgb(t_rgb *rgb, char **str)
{
	while (**str && ft_isspace(**str))
		(*str)++;
	if (ft_rgb_format(*str))
		return (5);
	rgb->r = ft_atoi(*str);
	while (**str && ft_isdigit(**str))
		(*str)++;
	rgb->g = ft_atoi(*str);
	while (**str && ft_isdigit(**str))
		(*str)++;
	rgb->b = ft_atoi(*str);
	while (**str && ft_isdigit(**str))
		(*str)++;
	while (**str && ft_isspace(**str))
		(*str)++;
	return (0);
}

int	ft_pars_float(float *shr, char **str)
{
	size_t	i;

	i = 0;
	while (**str && ft_isspace(**str))
		(*str)++;
	while ((*str)[i] && ft_isdigit((*str)[i]))
		i++;
	if ((*str)[i] && (*str)[i] == '.')
	{
		if (!(*str)[i + 1] || !ft_isdigit((*str)[i + 1]))
			return (1);
		i++;
	}
	while ((*str)[i] && ft_isdigit((*str)[i]))
		i++;
	if (!i || ((*str)[i] && !ft_isspace((*str)[i])))
		return (1);
	*shr = ft_atof(*str);
	*str += i;
	while (**str && ft_isspace(**str))
		(*str)++;
	return (0);
}
