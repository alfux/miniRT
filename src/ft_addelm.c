/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addelm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 12:44:12 by alfux             #+#    #+#             */
/*   Updated: 2023/01/01 12:54:47 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static int	ft_setvtn(char const **str, t_vtn *set)
{
	set->v = ft_atoi(*str);
	if (ft_skipdigit(str) || !ft_isdigit(*(++(*str))))
		return (1);
	set->t = ft_atoi(*str);
	if (ft_skipdigit(str) || !ft_isdigit(*(++(*str))))
		return (1);
	set->n = ft_atoi(*str);
	if (ft_skipdigit(str))
		return (1);
	return (0);
}

static int	ft_addidx(char const *str, t_list **f)
{
	t_idx	*new;

	new = ft_calloc(1, sizeof(t_idx));
	if (!new || (ft_lstadd_new(f, new) && !ft_free(new)))
		return (1);
	if (ft_skipnodigit(&str) || ft_setvtn(&str, &new->a) || ft_skipspace(&str))
		return (1);
	if (ft_skipnodigit(&str) || ft_setvtn(&str, &new->b) || ft_skipspace(&str))
		return (1);
	if (ft_skipnodigit(&str) || ft_setvtn(&str, &new->c) || !ft_skipspace(&str))
		return (1);
	return (0);
}

static int	ft_addtxt(char const *str, t_list **v)
{
	t_vec	*new;

	new = ft_calloc(1, sizeof (t_vec));
	if (!new || (ft_lstadd_new(v, new) && !ft_free(new)))
		return (1);
	if (ft_skipnodigit(&str))
		return (1);
	new->x = ft_atof(str);
	if (ft_skipdigit(&str) || ft_skipnodigit(&str))
		return (1);
	new->y = ft_atof(str);
	return (0);
}

static int	ft_addvec(char const *str, t_list **v)
{
	t_vec	*new;

	new = ft_calloc(1, sizeof (t_vec));
	if (!new || (ft_lstadd_new(v, new) && !ft_free(new)))
		return (1);
	if (ft_skipnodigit(&str))
		return (1);
	new->x = ft_atof(str);
	if (ft_skipdigit(&str) || ft_skipnodigit(&str))
		return (1);
	new->y = ft_atof(str);
	if (ft_skipdigit(&str) || ft_skipnodigit(&str))
		return (1);
	new->z = ft_atof(str);
	return (0);
}

int	ft_addelm(char const *line, t_dat *dat)
{
	if (ft_datatp(line) == ' ')
		return (ft_addvec(line, &dat->v));
	if (ft_datatp(line) == 't')
		return (ft_addtxt(line, &dat->vt));
	if (ft_datatp(line) == 'n')
		return (ft_addvec(line, &dat->vn));
	if (ft_datatp(line) == 'f')
		return (ft_addidx(line, &dat->f));
	return (0);
}
