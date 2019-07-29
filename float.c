/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 13:06:25 by trobicho          #+#    #+#             */
/*   Updated: 2019/07/29 13:55:27 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "convert_utils.h"
#include "cast.h"

void		print_double_union(t_double_union d)
{
	uint64_t		and;
	char			s[54];
	int				i;

	printf("[%llx ", d.field.sign);
	printf("%lld ", (int64_t)(d.field.exp) - 1023);
	printf("%llx", d.field.mantissa);
	s[0] = '1';
	s[53] = '\0';
	i = 0;
	and = 1;
	while (i < 52)
	{
		s[52 - i] = (d.field.mantissa & and) ? '1' : '0';
		and <<= 1;
		i++;
	}
	printf(" [%s]]\n", s);
}

static void	add_to_buffer_mantissa_special_case(t_info *info, t_double_union d)
{
	if (d.field.mantissa == 0)
	{
		if (d.field.sign)
			add_to_buffer(info, '-');
		add_to_buffer(info, 'i');
		add_to_buffer(info, 'n');
		add_to_buffer(info, 'f');
	}
	else
	{
		add_to_buffer(info, 'n');
		add_to_buffer(info, 'a');
		add_to_buffer(info, 'n');
	}
}

static int	mantissa_detect_special_case(t_info *info, t_param param, double d)
{
	int				len;
	t_double_union	d_union;

	d_union.f = d;
	//print_double_union(d_union);
	if (d_union.field.exp == 0x7FF)
	{
		len = 3;
		if (d_union.field.mantissa == 0)
		{
			if (d_union.field.sign)
				len++;
		}
		param.prec = -1;
		field_take_care(info, param, len, 0);
		add_to_buffer_mantissa_special_case(info, d_union);
		field_take_care(info, param, len, 1);
		return (1);
	}
	return (0);
}

static int	pow_double(t_param param, long double d
	, long double *ph, long double *pl)
{
	long double	r;
	long double	d_tmp;
	int			len;
	int			p;

	param.prec = (param.prec == -1) ? 6 : param.prec;
	len = 1;
	*ph = 1.;
	d_tmp = d;
	while (d_tmp >= 10.0)
	{
		d_tmp /= 10.0;
		*ph *= 10.0;
		len += 1;
	}
	*pl = 1.;
	d_tmp = d - (int64_t)d;
	p = -1;
	while (++p < param.prec)
	{
		d_tmp = (d_tmp * 10.0) - (int64_t)(d_tmp * 10.0);
		*pl /= 10.0;
		len += 1;
	}
	return (len);
}

void		conv_f(t_info *info, t_param param)
{
	long double	d;
	long double	ph;
	long double	pl;
	int			len;
	int			c;

	if (param.flag == f_maj_l)
		d = (long double)va_arg(info->va, long double);
	else
		d = (long double)va_arg(info->va, double);
	if ((len = mantissa_detect_special_case(info, param, (double) d)) != 0)
		return ;
	len = pow_double(param, d, &ph, &pl);
	if (pl < 0.5 || (param.attrib & A_HASH))
		len += 1;
	param.prec = -1;
	field_take_care(info, param, len, 0);
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
