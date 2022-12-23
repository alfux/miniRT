/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setamb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:41:33 by alfux             #+#    #+#             */
/*   Updated: 2022/12/23 16:47:43 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_amb	ft_setamb(float rat, t_rgb col)
{
	t_amb	set;

	set.rat = rat;
	set.col = col;
	return (set);
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
	if ((str)[i] && (str)[i] == '.')
	{
		digit = 0;
		i++;
	}
	while ((str)[i] && ft_isdigit((str)[i]) && ++digit)
		i++;
	amb->rat = ft_atof(str);
	if (!digit || !(str)[i] || !ft_isspace((str)[i]) || amb->rat > 1)
		return (7);
	str += i;
	while (*str && ft_isspace(*str))
		str++;
	if (ft_rgb(&amb->col, &str))
		return (5);
	if (*str)
		return (10);
	return (0);
}
