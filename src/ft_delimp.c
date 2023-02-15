/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delimp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 14:02:24 by alfux             #+#    #+#             */
/*   Updated: 2022/12/31 19:31:23 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	ft_delimp(t_imp *imp)
{
	if (!imp)
		return (0);
	(void)ft_free(imp->vtx);
	(void)ft_free(imp->txt);
	(void)ft_free(imp->nml);
	(void)ft_free(imp->idx);
	(void)ft_free(imp);
	return (0);
}
