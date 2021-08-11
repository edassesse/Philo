/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edassess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:48:09 by edassess          #+#    #+#             */
/*   Updated: 2021/08/11 16:29:06 by edassess         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_philo	*data;

	data = (t_philo *)malloc(sizeof(t_philo));
	if (!data)
		return (-1);
	if ((ac != 5 && ac != 6) || !parsing(ac, av, data))
	{
		printf("pas bon\n");
		return (-1);
	}
	philo(data);
	return (1);
}
