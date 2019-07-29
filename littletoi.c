/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   littletoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 11:58:58 by trobicho          #+#    #+#             */
/*   Updated: 2019/07/25 09:57:05 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	littletoi(t_info *info)
{
	unsigned int	r;

	r = 0;
	while (*info->sp >= '0' && *info->sp < '9')
	{
		r *= 10;
		r += *info->sp - '0';
		info->sp++;
	}
	info->sp--;
	return (r);
}
