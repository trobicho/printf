/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 19:18:58 by trobicho          #+#    #+#             */
/*   Updated: 2019/07/21 11:50:44 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_arg.h"
#include "convert_utils.h"

int	conv_x(t_info *info, t_param param)
{
	unsigned long long int	p;
	unsigned long long int	x;
	char					c;
	int						l;

	x = (unsigned long long)get_decimal_cast(info, param);
	p = count_pow(x, 16, &l);
	field_add(info, param, l, 0);
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
	if (param.attrib & A_MINUS)
		field_add(info, param, l, 1);
	return (0);
}
