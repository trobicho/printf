/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 08:27:07 by trobicho          #+#    #+#             */
/*   Updated: 2019/07/22 09:17:30 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cast.h"

long long int			get_decimal_cast(t_info *info, t_param param)
{
	long long int	x;

	x = 0;
	if (param.flag == f_none)
		x = (int)va_arg(info->va, int);
	else if (param.flag == f_hh)
		x = (char)va_arg(info->va, int);
	else if (param.flag == f_h)
		x = (short int)va_arg(info->va, int);
	else if (param.flag == f_l)
		x = (long int)va_arg(info->va, long int);
	else if (param.flag == f_ll)
		x = va_arg(info->va, long long int);
	return (x);
}

unsigned long long int	get_unsigned_decimal_cast(t_info *info, t_param param)
{
	unsigned long long int	x;

	x = 0;
	if (param.flag == f_none)
		x = (unsigned int)va_arg(info->va, unsigned int);
	else if (param.flag == f_hh)
		x = (unsigned char)va_arg(info->va, unsigned int);
	else if (param.flag == f_h)
		x = (unsigned short int)va_arg(info->va, unsigned int);
	else if (param.flag == f_l)
		x = (unsigned long int)va_arg(info->va, unsigned long int);
	else if (param.flag == f_ll)
		x = (unsigned long long int)va_arg(info->va, unsigned long long int);
	return (x);
}
