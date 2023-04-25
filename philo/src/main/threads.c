/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:06:15 by alaaouam          #+#    #+#             */
/*   Updated: 2023/04/25 20:40:13 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>
#include <pthread.h>
#include <sys/time.h>

static void	ft_check_death(t_data *data, t_philo *philo)
{
	long long	count;

	count = 0;
	while (1)
	{
		if (data->ate == data->philo_count)
		{
			pthread_mutex_lock(&data->printing);
			return ;
		}
		if (ft_gettime() - philo[count].last_meal > data->time_die)
		{
			pthread_mutex_lock(&data->printing);
			printf("%lld %lld %s", ft_time(philo + count),
				philo[count].id, DEAD);
			return ;
		}
		count = (count + 1) % data->philo_count;
		usleep(500);
	}
}

int	ft_create_threads(t_philo *list, long long size)
{
	long long	count;

	count = 0;
	while (count < size)
	{
		if (pthread_create(&list[count].thread_id, NULL, ft_tasks,
				(void *)&list[count]) != 0)
			return (1);
		usleep(100);
		count++;
	}
	if (list->data->philo_count == 1)
	{
		ft_usleep(list->data->time_die);
		ft_print_action(list, DEAD);
		return (0);
	}
	ft_check_death(list->data, list);
	return (0);
}
