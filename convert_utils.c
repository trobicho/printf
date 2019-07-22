/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 20:17:59 by trobicho          #+#    #+#             */
/*   Updated: 2019/07/22 10:16:18 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_utils.h"

static void				field_add(t_info *info, int n, char c)
{
	int i;

	i = 0;
	while (i < n)
	{
		add_to_buffer(info, c);
		i++;
	}
}

static void				field_add_sign(t_info *info, t_param param, int after)
{
	if (param.param == 'd' && !after)
	{
		if ((param.attrib & A_NEG))
			add_to_buffer(info, '-');
		else if (param.attrib & A_PLUS)
			add_to_buffer(info, '+');
		else if (param.attrib & A_SPACE)
			add_to_buffer(info, ' ');
	}
	if (param.param == 'o' && !after)
	{
		add_to_buffer(info, '0');
	}
}

static void				field_add_hash(t_info *info, t_param param, int after)
{
	if (param.attrib & A_HASH)
	{
		if (!after && (param.param == 'x' || param.param == 'X'))
		{
			add_to_buffer(info, '0');
			add_to_buffer(info, param.param);
		}
	}
}

unsigned long long int	count_pow(unsigned long long int n, int p, int *len)
{
	unsigned long long int	r;

	r = 1;
	*len = 1;
	while (n >= p)
	{
		n /= p;
		r *= p;
		*len += 1;
	}
	return (r);
}

int						field_take_care(t_info *info, t_param param
	, int l, int after)
{
	int	n;

	if ((param.param == 'x' || param.param == 'X') && (param.attrib & A_0))
		field_add_hash(info, param, after);
	if ((!(param.attrib & A_MINUS) && !after)
		|| ((param.attrib & A_MINUS) && after))
	{
		n = (l < param.prec) ? param.prec : l;
		n += (param.param == 'o') ? 1 : 0;
		if (param.param == 'd' && ((param.attrib & A_NEG)
			| (param.attrib & A_SPACE) || (param.attrib & A_PLUS)))
			n += 1;
		if (param.attrib & A_HASH)
		{
			if (param.param == 'x' || param.param == 'X')
				n += 2;
		}
		field_add(info, param.field_len - n, (param.attrib & A_0) ? '0' : ' ');
	}
	field_add_sign(info, param, after);
	if ((param.param != 'x' && param.param != 'X') || !(param.attrib & A_0))
		field_add_hash(info, param, after);
	if (!after)
		field_add(info, param.prec - l, '0');
	return (0);
}
