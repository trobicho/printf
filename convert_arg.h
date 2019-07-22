/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_arg.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 19:19:22 by trobicho          #+#    #+#             */
/*   Updated: 2019/07/22 10:35:04 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_ARG_H
# define CONVERT_ARG_H

# include "format.h"

int	conv_c(t_info *info, t_param param);
int	conv_s(t_info *info, t_param param);
int	conv_x(t_info *info, t_param param);
int	conv_d(t_info *info, t_param param);
int	conv_u(t_info *info, t_param param);
int	conv_o(t_info *info, t_param param);
#endif
