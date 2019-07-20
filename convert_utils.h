/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 20:18:36 by trobicho          #+#    #+#             */
/*   Updated: 2019/07/20 20:19:54 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_UTILS_H
# define CONVERT_UTILS_H

# include "ft_printf.h"

unsigned int	count_pow(unsigned int n, int p, int *len);
int				field_add(t_info *info, t_param param, int l);
#endif
