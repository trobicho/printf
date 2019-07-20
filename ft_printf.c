/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 18:07:24 by trobicho          #+#    #+#             */
/*   Updated: 2019/07/20 20:50:06 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "convert_arg.h"

void		add_to_buffer(t_info *info, char c)
{
	if (info->buf_cur_size == BUFF_SIZE)
	{
		write(1, info->buf, info->buf_cur_size);
		info->buf_cur_size = 0;
	}
	info->buf[info->buf_cur_size] = c;
	info->buf_cur_size++;
}

static int	convert_format(t_info *info, t_param param)
{
	if (*info->sp == 'x')
	{
		conv_x(info, param);
	}
	info->sp++;
	return (0);
}

static int	convert_flag(t_info *info)
{
	t_param	param;

	param.prec = 3;
	param.field_len = 5;
	param.attrib = 0;
	info->sp++;
	if (*info->sp == 'h')
	{
		info->sp++;
		param.flag = f_h;
		if (*info->sp == 'h')
		{
			info->sp++;
			param.flag = f_hh;
			convert_format(info, param);
		}
		else
			convert_format(info, param);
	}
	else if (*info->sp == 'l')
	{
		info->sp++;
		param.flag = f_l;
		if (*info->sp == 'l')
		{
			info->sp++;
			param.flag = f_ll;
			convert_format(info, param);
		}
		else
			convert_format(info, param);
	}
	else if (*info->sp == 'L')
	{
		info->sp++;
		param.flag = f_maj_l;
		convert_format(info, param);
	}
	else
		convert_format(info, param);
}

int			ft_printf(const char *format, ...)
{
	char	p;
	t_info	info;

	if (!format)
		return (0);
	info.sp = (char*)format;
	info.buf_cur_size = 0;
	va_start(info.va, format);
	while (*info.sp != '\0')
	{
		if (*info.sp == '%')
			convert_flag(&info);
		add_to_buffer(&info, *info.sp);
		info.sp++;
	}
	va_end(info.va);
	if (info.buf_cur_size > 0)
		write(1, info.buf, info.buf_cur_size);
	return (0);
}
