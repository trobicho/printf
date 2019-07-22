/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 08:20:01 by trobicho          #+#    #+#             */
/*   Updated: 2019/07/21 08:50:04 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_H
# define FORMAT_H

# include "ft_printf.h"

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

int				parse_format(t_info *info);
#endif
