/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 19:18:58 by trobicho          #+#    #+#             */
/*   Updated: 2019/07/20 20:20:18 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_arg.h"
#include "convert_utils.h"

int					conv_x(t_info *info, t_param param)
{
	unsigned long long int	p;
	unsigned long long int	x;
	char					c;
	int						l;

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
	p = count_pow(x, 16, &l);
	field_add(info, param, l);
	while (p >= 1)
	{
		if (x / p < 10)
			c = (x / p) + '0';
		else
			c = (x / p) - 10 + 'a';
		add_to_buffer(info, c);
		x = x % p;
		p /= 16;
	}
	return (0);
}
