/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_arg.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 19:19:22 by trobicho          #+#    #+#             */
/*   Updated: 2019/07/20 20:19:20 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_ARG_H
# define CONVERT_ARG_H

# include "ft_printf.h"

int	convert_arg(t_info *info);
int	conv_x(t_info *info, t_param param);
#endif
