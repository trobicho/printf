/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_arg_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 10:21:30 by trobicho          #+#    #+#             */
/*   Updated: 2019/07/22 10:21:31 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_arg.h"
#include "convert_utils.h"
#include "cast.h"

int	conv_x(t_info *info, t_param param)
{
	unsigned long long int	p;
	unsigned long long int	x;
	int						l;

	x = get_unsigned_decimal_cast(info, param);
	p = count_pow(x, 16, &l);
	if (x == 0)
		param.attrib &= (~A_HASH);
	if (param.prec == 0 && x == 0)
		l = 0;
	field_take_care(info, param, l, 0);
	while (p >= 1 && l)
	{
		if (x / p < 10)
			add_to_buffer(info, (x / p) + '0');
		else if (param.param == 'x')
			add_to_buffer(info, (x / p) - 10 + 'a');
		else
			add_to_buffer(info, (x / p) - 10 + 'A');
		x = x % p;
		p /= 16;
	}
	field_take_care(info, param, l, 1);
	return (0);
}

int	conv_d(t_info *info, t_param param)
{
	unsigned long long int	p;
	long long int			xs;
	unsigned long long int	x;
	int						l;

	xs = get_decimal_cast(info, param);
	x = xs;
	if (xs < 0)
	{
		x = -xs;
		param.attrib |= A_NEG;
	}
	p = count_pow(x, 10, &l);
	if (param.prec == 0 && x == 0)
		l = 0;
	field_take_care(info, param, l, 0);
	while (p >= 1 && l)
	{
		add_to_buffer(info, (x / p) + '0');
		x = x % p;
		p /= 10;
	}
	field_take_care(info, param, l, 1);
	return (0);
}

int	conv_u(t_info *info, t_param param)
{
	unsigned long long int	p;
	unsigned long long int	x;
	int						l;

	x = get_unsigned_decimal_cast(info, param);
	p = count_pow(x, 10, &l);
	if (param.prec == 0 && x == 0)
		l = 0;
	field_take_care(info, param, l, 0);
	while (p >= 1 && l)
	{
		add_to_buffer(info, (x / p) + '0');
		x = x % p;
		p /= 10;
	}
	field_take_care(info, param, l, 1);
	return (0);
}

int	conv_o(t_info *info, t_param param)
{
	unsigned long long int	p;
	unsigned long long int	x;
	int						l;

	x = get_unsigned_decimal_cast(info, param);
	p = count_pow(x, 8, &l);
	if (param.prec == 0 && x == 0)
		l = 0;
	field_take_care(info, param, l, 0);
	while (p >= 1 && l)
	{
		add_to_buffer(info, (x / p) + '0');
		x = x % p;
		p /= 8;
	}
	field_take_care(info, param, l, 1);
	return (0);
}
