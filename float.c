/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 13:06:25 by trobicho          #+#    #+#             */
/*   Updated: 2019/07/24 16:31:31 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "convert_utils.h"
#include "cast.h"

static int	pow_double(t_param param, double d, double *ph, double *pl)
{
	double	r;
	double	d_tmp;
	int		len;
	int		p;

	len = 1;
	*ph = 1;
	d_tmp = d;
	while (d_tmp >= 10.0)
	{
		d_tmp /= 10.0;
		*ph *= 10.0;
		len += 1;
	}
	*pl = 1;
	d_tmp = d - (int64_t)d;
	if (param.prec == -1)
		param.prec = 6;
	p = 0;
	while (d_tmp > 0.0 && p < param.prec)
	{
		d_tmp *= 10.0;
		d_tmp = d_tmp - (int64_t)d_tmp;
		*pl /= 10.0;
		len += 1;
		p++;
	}
	return (len);
}

void	conv_lf_bullshit(t_info *info, t_param param)
{
	double	d;
	double	ph;
	double	pl;
	int		len;
	int		c;

	d = (double)va_arg(info->va, double);
	len = pow_double(param, d, &ph, &pl);

	if (pl < 0.5 || (param.attrib & A_HASH))
		len += 1;
	field_take_care(info, param, len, 0);
	param.prec = -1;
	while (ph + ph > pl)
	{
		c = (int)(d / ph);
		d = (d / ph - c) * ph;
		add_to_buffer(info, (char)(c + '0'));
		if (ph < 1.5 && ph > 0.5 && (pl < 0.5 || (param.attrib & A_HASH)))
			add_to_buffer(info, '.');
		ph /= 10;
	}
	field_take_care(info, param, len, 1);

}

void	print_double_union(t_double_union d)
{
	printf("%llx ", d.field.sign);
	printf("%lld ", (int64_t)(d.field.exp) - 1023);
	printf("%llx", d.field.mantissa);

	char s[54];

	s[0] = '1';
	s[53] = '\0';

	uint64_t and = 1;
	for (int i = 0; i < 52; i++)
	{
		s[52 - i] = (d.field.mantissa & and) ? '1' : '0';
		and <<= 1;
	}
	printf(" [%s]\n", s);
}

void	conv_lf(t_info *info, t_param *param)
{
	t_double_union	d;

	d.f = (double)va_arg(info->va, double);
	print_double_union(d);
}
