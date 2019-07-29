/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 19:18:58 by trobicho          #+#    #+#             */
/*   Updated: 2019/07/29 17:09:37 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_arg.h"
#include "convert_utils.h"
#include "cast.h"
#include <string.h>

static size_t	get_len_s(t_param param, const char *str)
{
	size_t	i;

	i = 0;
	if (param.prec >= 0)
	{
		while (str[i] != '\0' && i != (size_t)param.prec)
		{
			i++;
		}
	}
	else
	{
		while (str[i] != '\0')
		{
			i++;
		}
	}
	return (i);
}

int				conv_c(t_info *info, t_param param)
{
	unsigned char c;

	if (param.param == '%')
		c = '%';
	else
		c = (unsigned char)va_arg(info->va, int);
	field_take_care(info, param, 1, 0);
	add_to_buffer(info, c);
	field_take_care(info, param, 1, 1);
	return (0);
}

int				conv_s(t_info *info, t_param param)
{
	static char	*nul = "(null)";
	const char	*s;
	size_t		len;
	size_t		i;

	s = (const char*)va_arg(info->va, const char *);
	if (!s)
		s = (const char*)nul;
	len = get_len_s(param, s);
	param.prec = -1;
	field_take_care(info, param, len, 0);
	i = 0;
	while (i < len)
	{
		add_to_buffer(info, s[i]);
		i++;
	}
	field_take_care(info, param, len, 1);
	return (0);
}

int	conv_p(t_info *info, t_param param)
{
	unsigned long long int	p;
	unsigned long long int	x;
	int						l;

	x = (unsigned long long int)va_arg(info->va, void*);
	p = count_pow(x, 16, &l);
	param.param = 'x';
	param.attrib |= (A_HASH);
	if (param.prec == 0 && x == 0)
		l = 0;
	field_take_care(info, param, l, 0);
	while (p >= 1 && l)
	{
		if (x / p < 10)
			add_to_buffer(info, (x / p) + '0');
		else if (param.param == 'x')
			add_to_buffer(info, (x / p) - 10 + 'a');
		else
			add_to_buffer(info, (x / p) - 10 + 'A');
		x = x % p;
		p /= 16;
	}
	field_take_care(info, param, l, 1);
	return (0);
}
