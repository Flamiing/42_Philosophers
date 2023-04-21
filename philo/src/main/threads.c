/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:06:15 by alaaouam          #+#    #+#             */
/*   Updated: 2023/04/19 13:01:34 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>
#include <pthread.h>
#include <sys/time.h>

static void	ft_check_death(t_data *data, t_philo *philo)
{
	long long	count;

	count = 0;
	if (data->philo_count == 1)
	{
		usleep(data->time_die * 1000);
		ft_print_action(philo, ft_time(philo), DEAD);
		return ;
	}
	while (1)
	{
		if (philo[count].meal_count == data->max_meals)
		{
			data->have_to_eat--;
			if (data->have_to_eat <= 0)
				return ;
		}
		if (ft_gettime() - philo[count].last_meal > data->time_die)
		{
			pthread_mutex_lock(&data->printing);
			printf("%lld %lld %s", ft_time(philo + count), philo[count].id, DEAD);
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
		if (pthread_create(&list[count].thread_id, NULL, ft_tasks, (void *)&list[count]) != 0)
			return (1);
		usleep(100);
		count++;
	}
	ft_check_death(list->data, list);
	/* count = 0;
	while (count < size)
	{
		if (pthread_join(list[count].thread_id, NULL) != 0)
			return (1);
		count++;
	} */
	return (0);
}