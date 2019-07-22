/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 18:07:24 by trobicho          #+#    #+#             */
/*   Updated: 2019/07/21 08:51:06 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "format.h"

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
		{
			info.sp++;
			parse_format(&info);
		}
		add_to_buffer(&info, *info.sp);
		info.sp++;
	}
	va_end(info.va);
	if (info.buf_cur_size > 0)
		write(1, info.buf, info.buf_cur_size);
	return (0);
}
