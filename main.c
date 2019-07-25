/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:37:55 by trobicho          #+#    #+#             */
/*   Updated: 2019/07/24 16:40:39 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(int ac, char **av)
{
	ft_printf("test (%5#-c)\n", 'j');
	printf("true (%5#-c)\n", 'j');

	ft_printf("test (%-5.2s)\n", "fdf", 12);
	printf("true (%-5.2s)\n", "fdf");
	
	ft_printf("double test (%f)\n", 0.2);
	ft_printf("double test (%f)\n", 21.0);
	printf("double true (%f)\n", 21.0);
	ft_printf("double test (%8f)\n", 0.123);
	printf("double true (%8f)\n", 0.123);
	return (0);
}
