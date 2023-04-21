/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 21:26:47 by alaaouam          #+#    #+#             */
/*   Updated: 2023/04/21 18:16:28 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>
#include <pthread.h>

static int	ft_init_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->printing, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->death, NULL) != 0)
		return (1);
	return (0);
}

static int	ft_init_fork_mutex(t_data *data, long long size)
{
	long long		count;
	pthread_mutex_t	*forks;

	forks = (pthread_mutex_t *)ft_calloc(size, sizeof(pthread_mutex_t));
	if (!forks)
		return (1);
	count = 0;
	while (count < size)
	{
		if (pthread_mutex_init(&forks[count], NULL) != 0)
			return (1);
		count++;
	}
	data->forks = forks;
	return (0);
}

t_data	*ft_init_data(char **args)
{
	t_data	*data;

	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	data->philo_count = ft_atoll(args[1]);
	data->time_die = ft_atoll(args[2]);
	data->time_eat = ft_atoll(args[3]);
	data->time_sleep = ft_atoll(args[4]);
	if (args[5])
		data->max_meals = ft_atoll(args[5]);
	else
		data->max_meals = -1;
	data->have_to_eat = data->max_meals;
	data->philo_dead = FALSE;
	if (ft_init_fork_mutex(data, data->philo_count) != 0)
		return (ft_free_and_return(data));
	if (ft_init_mutex(data) != 0)
		return (ft_free_and_return(data));
	data->list = ft_create_list(data, data->philo_count);
	if (!data->list)
		return (ft_free_and_return(data));
	return (data);
}
