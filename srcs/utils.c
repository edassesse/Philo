/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edassess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:25:10 by edassess          #+#    #+#             */
/*   Updated: 2021/08/11 16:41:53 by edassess         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

char	*ft_strchr(char *s, char c)
{
	while (*s)
		if (*s++ == c)
			return (s);
	return (NULL);
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	long int	res;
	int			sign;

	res = 0;
	sign = 1;
	while (ft_strchr("\t\v\n\r\f ", *str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + *str++ - '0';
	return (res * sign);
}

int	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void	my_usleep(int sleep)
{
	int	time;

	time = get_time();
	while (1)
	{
		if (get_time() - time >= sleep)
			break ;
		usleep(20);
	}
}
