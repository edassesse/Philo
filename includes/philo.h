/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edassess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 10:04:42 by edassess          #+#    #+#             */
/*   Updated: 2021/08/11 14:22:22 by edassess         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_philo;
	int				n_eat;
	int				dead;
	int				time;
	int				has_eaten;
	int				start;
	pthread_mutex_t	print;
	pthread_mutex_t	*fork;
}				t_philo;

int			main(int ac, char **av);
int			parsing(int ac, char **av, t_philo *data);
void		philo(t_philo *data);

// ACTIONS

void		action_sleep(t_philo *data, int nb, int time);
void		action_death(t_philo *data, int time, int nb, int add_time);
void		action_eat(t_philo *data, int nb, int time);

// UTILS

int			get_time(void);
void		my_usleep(int sleep);
int			ft_isdigit(char c);
char		*ft_strchr(char *s, char c);
int			ft_atoi(const char *str);

#endif
