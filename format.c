/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 08:20:30 by trobicho          #+#    #+#             */
/*   Updated: 2019/07/24 13:37:11 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"
#include "convert_arg.h"

static int	convert_format(t_info *info, t_param param)
{
	unsigned char	c;

	param.param = *info->sp;
	if (param.prec != -1 && (param.attrib & A_0))
		param.attrib &= ~A_0;
	if (*info->sp == 'x' || *info->sp == 'X')
		conv_x(info, param);
	if (*info->sp == 'd' || *info->sp == 'i')
	{
		param.param = 'd';
		conv_d(info, param);
	}
	if (*info->sp == 'u')
		conv_u(info, param);
	if (*info->sp == 'o')
		conv_o(info, param);
	else if (*info->sp == '%')
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
		conv_lf_bullshit(info, param);
	info->sp++;
	return (0);
}

static int	get_flag(t_info *info, t_param *param)
{
	if (*info->sp == 'h')
	{
		param->flag = f_h;
		if (info->sp[1] == 'h')
			param->flag = f_hh;
	}
	else if (*info->sp == 'l')
	{
		param->flag = f_l;
		if (info->sp[1] == 'l')
			param->flag = f_ll;
	}
	else if (*info->sp == 'L')
		param->flag = f_maj_l;
	else
		return (0);
	if (param->flag == f_hh || param->flag == f_ll)
		info->sp++;
	return (1);
}

static int	get_param(t_info *info, t_param *param)
{
	if (get_flag(info, param))
		return (1);
	else if (*info->sp == '#')
		param->attrib |= A_HASH;
	else if (*info->sp == '0')
		param->attrib |= A_0;
	else if (*info->sp == '+')
	{
		param->attrib |= A_PLUS;
		param->attrib &= ~A_SPACE;
	}
	else if (*info->sp == '-')
		param->attrib |= A_MINUS;
	else if (*info->sp == ' ')
	{
		if (!(param->attrib & A_PLUS))
			param->attrib |= A_SPACE;
	}
	else if (*info->sp == '.')
	{
		info->sp++;
		param->prec = littletoi(info);
	}
	else if (*info->sp > '0' && *info->sp <= '9')
		param->field_len = littletoi(info);
	else
		return (0);
	return (1);
}

int			parse_format(t_info *info)
{
	int		r;
	t_param	param;

	param.flag = f_none;
	param.prec = -1;
	param.field_len = 0;
	param.attrib = 0;
	while (get_param(info, &param))
	{
		info->sp++;
	}
	convert_format(info, param);
	return (0);
}
