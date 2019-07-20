/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 20:17:59 by trobicho          #+#    #+#             */
/*   Updated: 2019/07/20 20:22:35 by trobicho         ###   ########.fr       */
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

int				field_add(t_info *info, t_param param, int l)
{
	int	n;

	n = l;
	if (l < param.prec)
		n = param.prec;
	while (n < param.field_len)
	{
		add_to_buffer(info, ' ');
		n++;
	}
	while (l < param.prec)
	{
		add_to_buffer(info, '0');
		l++;
	}
	return (0);
}
