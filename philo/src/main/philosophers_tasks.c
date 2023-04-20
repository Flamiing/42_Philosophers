/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_tasks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:19:01 by alaaouam          #+#    #+#             */
/*   Updated: 2023/04/19 14:44:52 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>
#include <pthread.h>
#include <stdbool.h>

static void	*ft_check_death(void *arg)
{
	t_philo	*philo;
	long long	last_meal;

	philo = (t_philo *)arg;
	while (philo->data->philo_dead == false)
	{
		pthread_mutex_lock(&philo->data->death);
		last_meal = ft_get_time(philo->last_meal);
		if (last_meal >= philo->data->time_die
			&& philo->data->philo_dead == false)
		{
			pthread_mutex_lock(&philo->data->printing);
			philo->data->philo_dead = true;
			printf("%lld %lld %s", ft_get_time(philo->start), philo->id, DEAD);
			pthread_mutex_unlock(&philo->data->printing);
			pthread_mutex_unlock(&philo->data->death);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->data->death);
	}
	return (NULL);
}

void	*ft_tasks(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	gettimeofday(&philo->start, NULL);
	philo->last_meal = philo->start;
	if (pthread_create(&philo->death_check, NULL, ft_check_death, (void *)philo) != 0)
			return (NULL);
	pthread_detach(philo->death_check);
	if (philo->data->philo_count == 1)
		usleep(philo->data->time_die * 1000);
	while (1)
	{
		if (philo->id % 2 != 0)
		{
			pthread_mutex_lock(&philo->data->lock);
			pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
			pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
			pthread_mutex_unlock(&philo->data->lock);
			if (ft_print_action(philo, ft_get_time(philo->start), philo->id, FORK) != 0
				|| ft_print_action(philo, ft_get_time(philo->start), philo->id, FORK) != 0)
			{
				pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
				pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
				return (NULL);
			}
		}
		else
		{
			pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
			pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
			if (ft_print_action(philo, ft_get_time(philo->start), philo->id, FORK) != 0
				|| ft_print_action(philo, ft_get_time(philo->start), philo->id, FORK) != 0)
			{
				pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
				pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
				return (NULL);
			}
		}
		gettimeofday(&philo->last_meal, NULL);
		philo->time = ft_get_time(philo->start);
		if (ft_print_action(philo, philo->time, philo->id, EAT) != 0)
		{
			pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
			pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
			return (NULL);
		}
		ft_usleep(philo->data->time_eat);
		pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
		pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
		philo->time = ft_get_time(philo->start);
		if (ft_print_action(philo, philo->time, philo->id, SLEEP) != 0)
			return (NULL);
		ft_usleep(philo->data->time_sleep);
		if (ft_print_action(philo, philo->time, philo->id, THINK) != 0)
			return (NULL);
	}
	return (NULL);
}