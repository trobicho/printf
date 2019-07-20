/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 18:07:24 by trobicho          #+#    #+#             */
/*   Updated: 2019/07/19 19:09:26 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"

/*
static int	parse_format(const char *s, char **conv)
{
	char	*sp;
	int		i;

	i = 0;
	sp = (char*)s;
	while (*sp != '\0')
	{
		if (*sp == '%')
		{
			*conv = sp;
			return (i);
		}
		sp++;
		i++;
	}
	*conv = NULL;
	return (i);
}
*/

static int	convert_format(t_info *info)
{
	if (sp[1] == 'd')
	return (0);
}

int			ft_printf(const char *format, ...)
{
	char	p;
	t_info	info;

	if (!format)
		return (0);
	sp = (char*)format;
	info.buf_cur_size = 0;
	while (*sp != '\0')
	{
		if (*sp == '%')
			convert_format(&info);
		info.buf[info.buf_cur_size] = *info.sp;
		info.buf_cur_size++;
		if (info.buf_cur_size >= BUFF_SIZE)
		{
			write(1, info.buf, info.buf_cur_size);
			info.buf_cur_size = 0;
		}
		info.sp++;
	}
	write(1, info.buf, info.buf_cur_size);
	return (0);
}
