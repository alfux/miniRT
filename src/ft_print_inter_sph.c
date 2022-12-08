/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_inter_sph.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:00:42 by alfux             #+#    #+#             */
/*   Updated: 2022/12/08 10:02:38 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <miniRT.h>

void	ft_print_inter_sph(t_vec ray, t_sph *sph, t_2x3 inter)
{
	printf("Intersection dir");
	ft_print_vect(ray);
	printf(" on sphere pos");
	ft_print_vect(sph->pos);
	printf(" radius %f are ", sph->dia / 2);
	ft_print_vect(inter.top);
	printf(" and ");
	ft_print_vect(inter.bot);
	printf("\n");
}
