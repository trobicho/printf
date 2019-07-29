/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:37:55 by trobicho          #+#    #+#             */
/*   Updated: 2019/07/29 17:31:22 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
	ft_printf("test (%5#-c)\n", 'j');
	printf("true (%05#-c)\n", 'j');

	ft_printf("test (%-5.2%)\n", "fdf", 12);
	printf("true (%-5.2%)\n", "fdf");
	
	ft_printf("true (%%)\n");
	printf("true (%%)\n");
	ft_printf("double test (%5d)\n", 2);
	ft_printf("double test (%5d)\n", 2);
	printf("double true (%f)\n", 21.0);
	ft_printf("double test (%.2f)\n", 0.129);
	printf("double true (%.2f)\n", 0.129);
	double d = 1.0 / 0.0;
	d *= -1;
	ft_printf("double test (%5.010f)\n", d);
	printf("double true (%5.010f)\n", d);
	ft_printf("double test (%5p)\n", NULL);
	printf("double true (%5p)\n", NULL);
	ft_printf("ft = _%010.5s_\n", "bonjouroutlemonde");
	printf("lc = _%010.5s_\n", "bonjouroutlemonde");
	return (0);
}
