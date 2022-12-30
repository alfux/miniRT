/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:07:27 by efunes            #+#    #+#             */
/*   Updated: 2022/12/30 13:19:02 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	ft_pars_double(double *shr, char **str)
{
	size_t	i;

	i = 0;
	while (**str && ft_isspace(**str))
		(*str)++;
	if ((*str)[i] && (*str)[i] == '-')
		i++;
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
	if (!i || ((*str)[i] && ((i == 1 && **str == '-')
			|| !ft_isspace((*str)[i]))))
		return (1);
	*shr = ft_atof(*str);
	*str += i;
	while (**str && ft_isspace(**str))
		(*str)++;
	return (0);
}
