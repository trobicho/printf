/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 18:05:50 by trobicho          #+#    #+#             */
/*   Updated: 2019/07/21 08:46:56 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# define BUFF_SIZE	4096

typedef struct	s_info
{
	char		*sp;
	char		buf[BUFF_SIZE];
	int			buf_cur_size;
	va_list		va;
}				t_info;

void			add_to_buffer(t_info *info, char c);
int				ft_printf(const char *format, ...);
#endif
