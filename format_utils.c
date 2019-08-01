/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 17:22:35 by trobicho          #+#    #+#             */
/*   Updated: 2019/08/01 13:49:46 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"
#include "convert_arg.h"
#include "float.h"

static int	convert_numeric(t_info *info, t_param param)
{
	if (param.prec != -1 && (param.attrib & A_0))
		param.attrib &= ~A_0;
	if (*info->sp == 'x' || *info->sp == 'X')
		conv_x(info, param);
	else if (*info->sp == 'd' || *info->sp == 'i')
	{
		param.param = 'd';
		conv_d(info, param);
	}
	else if (*info->sp == 'u')
		conv_u(info, param);
	else if (*info->sp == 'o')
		conv_o(info, param);
	else
		return (0);
	return (1);
}

int			convert_format(t_info *info, t_param param)
{
	param.param = *info->sp;
	if (*info->sp == '%')
	{
		param.prec = -1;
		conv_c(info, param);
	}
	else if (*info->sp == 'c')
	{
		param.prec = -1;
		conv_c(info, param);
	}
	else if (*info->sp == 's')
		conv_s(info, param);
	else if (*info->sp == 'f')
		conv_f(info, param);
	else if (*info->sp == 'p')
		conv_p(info, param);
	else
		return (convert_numeric(info, param));
	info->sp++;
	return (0);
}
