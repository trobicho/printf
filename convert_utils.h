/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 20:18:36 by trobicho          #+#    #+#             */
/*   Updated: 2019/07/21 11:50:23 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_UTILS_H
# define CONVERT_UTILS_H

# include "format.h"

unsigned int	count_pow(unsigned int n, int p, int *len);
int				field_add(t_info *info, t_param param, int l, int after);
long long int	get_decimal_cast(t_info *info, t_param param);
#endif
