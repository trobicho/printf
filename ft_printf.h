/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 18:05:50 by trobicho          #+#    #+#             */
/*   Updated: 2019/07/20 20:32:24 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# define BUFF_SIZE	4096

# define A_HASH		1
# define A_0		2
# define A_MINUS	4
# define A_PLUS		8
# define A_SPACE	16

typedef enum	{f_none, f_h, f_hh, f_l, f_ll, f_maj_l}t_flag;

typedef struct	s_param
{
	t_flag		flag;
	int			prec;
	int			field_len;
	int			attrib;
}				t_param;

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
