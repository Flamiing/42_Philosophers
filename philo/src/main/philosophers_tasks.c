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

void	*ft_tasks(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_meal = ft_gettime();
	philo->start = philo->last_meal;
	if (philo->id % 2 == 0)
		usleep(10);
	while (1)
	{
		pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
		ft_print_action(philo, ft_time(philo), FORK);
		pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
		ft_print_action(philo, ft_time(philo), FORK);
		philo->meal_count++;
		ft_print_action(philo, ft_time(philo), EAT);
		philo->last_meal = ft_gettime();
		usleep(philo->data->time_eat * 1000);
		pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
		ft_print_action(philo, ft_time(philo), SLEEP);
		usleep(philo->data->time_sleep * 1000);
		ft_print_action(philo, ft_time(philo), THINK);
	}
	return (NULL);
}