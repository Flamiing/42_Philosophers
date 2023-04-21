/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:58:26 by alaaouam          #+#    #+#             */
/*   Updated: 2023/04/19 12:31:36 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>
#include <sys/time.h>

long long	ft_gettime(void)
{
	struct timeval	time;
	
	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long long	ft_time(t_philo *philo)
{
	return (ft_gettime() - philo->start);
}

void	ft_usleep(long long ms)
{
	long long	reference;

	reference = ms +  ft_gettime();
	while (ft_gettime() < reference)
		usleep(10);
}