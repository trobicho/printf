/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 20:18:36 by trobicho          #+#    #+#             */
/*   Updated: 2019/07/22 09:19:21 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_UTILS_H
# define CONVERT_UTILS_H

# include "format.h"

unsigned long long int	count_pow(unsigned long long int n, int p, int *len);
int						field_take_care(t_info *info, t_param param
	, int l, int after);
#endif
