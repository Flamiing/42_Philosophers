/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 21:26:47 by alaaouam          #+#    #+#             */
/*   Updated: 2023/04/22 21:12:55 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>
#include <pthread.h>

static t_philo	ft_newnode(t_data *data, long long id)
{
	t_philo	node;

	node.id = id;
	node.thread_id = NULL;
	node.meal_count = 0;
	if (id == data->philo_count)
	{
		node.right_fork = 0;
		node.left_fork = id - 1;
	}
	else
	{
		node.right_fork = id;
		node.left_fork = id - 1;
	}
	node.data = data;
	return (node);
}

static t_philo	*ft_create_list(t_data *data, long long size)
{
	long long		count;

	count = 0;
	data->list = (t_philo *)malloc(size * sizeof(t_philo));
	if (!data->list)
		return (NULL);
	while (count < size)
	{
		data->list[count] = ft_newnode(data, count + 1);
		count++;
	}
	return (data->list);
}

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
	data->ate = 0;
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
