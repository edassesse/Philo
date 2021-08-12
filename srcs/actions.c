/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edassess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:22:48 by edassess          #+#    #+#             */
/*   Updated: 2021/08/12 23:54:37 by user             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	action_death(t_philo *data, int time, int nb, int add_time)
{
	if (get_time() + add_time > time + data->t_die + 1)
	{
		my_usleep(50);
		pthread_mutex_lock(&data->print);
		data->dead = 1;
		printf("%5d philo %d has died\n", time - data->time + data->t_die, nb);
	}
	return ;
}

void	action_sleep(t_philo *data, int nb, int time)
{
	action_death(data, time, nb, data->t_sleep);
	pthread_mutex_lock(&data->print);
	printf("%5d philo %d is sleeping\n", get_time() - data->time, nb);
	pthread_mutex_unlock(&data->print);
	my_usleep(data->t_sleep);
	pthread_mutex_lock(&data->print);
	printf("%5d philo %d is thinking\n", get_time() - data->time, nb);
	pthread_mutex_unlock(&data->print);
}

int	check_eaten(t_philo *data, int nb, int t_eaten)
{
	if (t_eaten == data->n_eat)
	{
		pthread_mutex_lock(&data->print);
		printf("%5d philo %d has eaten %d times\n", \
				get_time() - data->time, nb, data->n_eat);
		data->has_eaten++;
		if (data->has_eaten == data->n_philo)
		{
			data->dead = 2;
			return (1);
		}
		pthread_mutex_unlock(&data->print);
		return (1);
	}
	return (0);
}

void	take_fork(t_philo *data, int nb, int time)
{
	int	l_fork;
	int	r_fork;

	l_fork = nb - 1;
	r_fork = nb;
	if (nb == data->n_philo)
		r_fork = 0;
	pthread_mutex_lock(&data->fork[r_fork]);
	pthread_mutex_lock(&data->print);
	printf("%5d philo %d has taken a fork\n", get_time() - data->time, nb);
	pthread_mutex_unlock(&data->print);
	pthread_mutex_lock(&data->fork[l_fork]);
	pthread_mutex_lock(&data->print);
	printf("%5d philo %d has taken a 2nd fork\n", get_time() - data->time, nb);
	pthread_mutex_unlock(&data->print);
	action_death(data, time, nb, 0);
}

void	action_eat(t_philo *data, int nb, int time)
{
	int	l_fork;
	int	r_fork;

	l_fork = nb - 1;
	r_fork = nb;
	if (nb == data->n_philo)
		r_fork = 0;
	action_death(data, time, nb, data->t_eat);
	take_fork(data, nb, time);
	pthread_mutex_lock(&data->print);
	printf("%5d philo %d is eating\n", get_time() - data->time, nb);
	pthread_mutex_unlock(&data->print);
	action_death(data, time, nb, data->t_eat);
	my_usleep(data->t_eat);
	pthread_mutex_unlock(&data->fork[l_fork]);
	pthread_mutex_unlock(&data->fork[r_fork]);
}
