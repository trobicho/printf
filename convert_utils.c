/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 20:17:59 by trobicho          #+#    #+#             */
/*   Updated: 2019/07/21 11:50:15 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "convert_utils.h"

unsigned int	count_pow(unsigned int n, int p, int *len)
{
	unsigned long long int	r;

	r = 1;
	*len = 1;
	while (n >= p)
	{
		n /= p;
		r *= p;
		*len+=1;
	}
	return (r);
}

int				field_add(t_info *info, t_param param, int l, int after)
{
	int	n;

	n = l;
	if ((!(param.attrib & A_MINUS) && !after)
		|| (param.attrib & A_MINUS) && after)
	{
		if (l < param.prec)
			n = param.prec;
		while (n < param.field_len)
		{
			if (param.attrib & A_0)
				add_to_buffer(info, '0');
			else
				add_to_buffer(info, ' ');
			n++;
		}
	}
	while (!after && l < param.prec)
	{
		add_to_buffer(info, '0');
		l++;
	}
	return (0);
}

long long int	get_decimal_cast(t_info *info, t_param param)
{
	long long int	x;

	x = 0;
	if (param.flag == f_none)
		x = (unsigned long long int)va_arg(info->va, unsigned int);
	else if (param.flag == f_hh)
		x = (unsigned char)va_arg(info->va, unsigned int);
	else if (param.flag == f_h)
		x = (unsigned short int)va_arg(info->va, unsigned int);
	else if (param.flag == f_l)
		x = (unsigned long long int)va_arg(info->va, unsigned long int);
	else if (param.flag == f_ll)
		x = va_arg(info->va, unsigned long long int);
	return (x);
}
