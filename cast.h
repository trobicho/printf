/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 08:26:23 by trobicho          #+#    #+#             */
/*   Updated: 2019/07/22 08:31:37 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAST_H
# define CAST_H

# include "format.h"

long long int			get_decimal_cast(t_info *info, t_param param);
unsigned long long int	get_unsigned_decimal_cast(t_info *info, t_param param);
#endif
