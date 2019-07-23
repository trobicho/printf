/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 13:06:25 by trobicho          #+#    #+#             */
/*   Updated: 2019/07/23 15:12:16 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "convert_utils.h"
#include "cast.h"

void conv_lf(t_info *info, t_param *param)
{
	uint64_t		mantisse;
	int				exp;
	t_double_union	d;

	d.f = (double)va_arg(info->va, double);
	printf("%llx ", d.field.sign);
	printf("%lld ", (int64_t)(d.field.exp) - 1023);
	printf("%llx\n", d.field.mantissa);
}
