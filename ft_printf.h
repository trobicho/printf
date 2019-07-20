/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 18:05:50 by trobicho          #+#    #+#             */
/*   Updated: 2019/07/19 19:04:45 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BUFF_SIZE	500

typedef struct	s_info
{
	char	*sp;
	char	buf[BUFF_SIZE];
	int		buf_cur_size;
}				t_info;

int	ft_printf(const char *format, ...);
#endif
