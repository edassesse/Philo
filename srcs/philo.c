/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edassess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:00:20 by edassess          #+#    #+#             */
/*   Updated: 2021/08/11 14:24:15 by edassess         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	check_eaten(t_philo *data, int nb, int t_eaten)
{
	if (t_eaten == data->n_eat)
	{
		pthread_mutex_lock(&data->print);
		printf("[%d] philo %d has eaten %d times\n", \
				get_time() - data->time, nb, data->n_eat);
		pthread_mutex_unlock(&data->print);
		data->has_eaten++;
		if (data->has_eaten == data->n_philo)
		{
			data->dead = 2;
			pthread_mutex_lock(&data->print);
		}
	}
}

void	*thread_philo(void *vargp)
{
	t_philo	*data;
	int		nb;
	int		t_eaten;
	int		time;

	data = vargp;
	nb = ++data->philo;
	t_eaten = 0;
	time = get_time();
	if (nb % 2 == 0)
		my_usleep(10);
	while (1)
	{
		action_eat(data, nb, time);
		time = get_time();
		t_eaten++;
		check_eaten(data, nb, t_eaten);
		action_sleep(data, nb, time);
	}
	return (NULL);
}

void	philo(t_philo *data)
{
	int			i;
	pthread_t	thread_id;

	i = -1;
	if (pthread_mutex_init(&data->print, NULL))
		return ;
	data->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
			* data->n_philo);
	while (++i < data->n_philo)
		if (pthread_mutex_init(&data->fork[i], NULL))
			return ;
	data->time = get_time();
	while (i--)
		pthread_create(&thread_id, NULL, thread_philo, data);
	while (!data->dead)
		;
	if (data->dead == 2)
		printf("[%d] all philos have eaten %d times\n", \
				get_time() - data->time, data->n_eat);
	return ;
}
