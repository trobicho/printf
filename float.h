/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 13:06:23 by trobicho          #+#    #+#             */
/*   Updated: 2019/07/23 14:11:11 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOAT_H
# define FLOAT_H

# include "format.h"
# include <stdint.h>

typedef	struct	s_doublefield
{
	uint64_t	mantissa : 52;
	uint64_t	exp : 11;
	uint64_t	sign : 1;

}				t_double_field;

typedef union
{
	double			f;
	t_double_field	field;
}				t_double_union;

void conv_lf(t_info *info, t_param *param);
#endif
