/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 08:20:30 by trobicho          #+#    #+#             */
/*   Updated: 2019/07/21 11:32:38 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"
#include "convert_arg.h"

static int	convert_format(t_info *info, t_param param)
{
	unsigned char	c;

	if (*info->sp == 'x')
	{
		conv_x(info, param);
	}
	else if (*info->sp == '%')
		add_to_buffer(info, '%');
	else if (*info->sp == 'c')
	{
		c = (unsigned char)va_arg(info->va, int);
		add_to_buffer(info, c);
	}
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
		param->attrib |= A_PLUS;
	else if (*info->sp == '-')
		param->attrib |= A_MINUS;
	else if (*info->sp == ' ')
		param->attrib |= A_SPACE;
	else
		return (0);
	return (1);
}

int			parse_format(t_info *info)
{
	int r;
	t_param	param;

	param.prec = 3;
	param.field_len = 5;
	param.attrib = 0;
	while (get_param(info, &param))
	{
		info->sp++;
	}
	convert_format(info, param);
}
