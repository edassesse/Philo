/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edassess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 09:56:49 by edassess          #+#    #+#             */
/*   Updated: 2021/08/11 15:29:54 by edassess         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	innit_struct(t_philo *data, int ac, char **av)
{
	int	i;

	i = 0;
	data->philo = 0;
	data->n_philo = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	data->n_eat = -1;
	data->has_eaten = 0;
	data->dead = 0;
	data->start = 0;
	if (ac == 6)
		data->n_eat = ft_atoi(av[5]);
}

int	parsing(int ac, char **av, t_philo *data)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
	}
	innit_struct(data, ac, av);
	return (1);
}
