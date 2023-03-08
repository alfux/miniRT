/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setamb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:41:33 by alfux             #+#    #+#             */
/*   Updated: 2023/03/08 16:05:36 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_amb	ft_setamb(double rat, t_rgb col)
{
	t_amb	set;

	set.rat = rat;
	set.col = col;
	return (set);
}

static int	ft_ambrat(double *rat, char *str)
{
	if (*rat != -1)
		return (1);
	*rat = ft_atof(str);
	return (0);
}

int	ft_pars_amb(t_amb *amb, char *str)
{
	size_t	i;
	char	digit;

	i = 0;
	digit = 0;
	while (*str && ft_isspace(*str))
		(str)++;
	while ((str)[i] && ft_isdigit((str)[i]) && ++digit)
			i++;
	if ((str)[i] && (str)[i] == '.' && ++i)
		digit = 0;
	while ((str)[i] && ft_isdigit((str)[i]) && ++digit)
		i++;
	if (!digit || !(str)[i] || !ft_isspace((str)[i])
			|| ft_ambrat(&amb->rat, str) || amb->rat > 1)
		return (10);
	str += i;
	while (*str && ft_isspace(*str))
		str++;
	if (ft_rgb(&amb->col, &str))
		return (5);
	if (*str)
		return (10);
	return (0);
}
