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
#include <stdbool.h>
#include <sys/time.h>

int	ft_create_threads(t_philo *list, long long size)
{
	long long	count;

	count = 0;
	while (count < size)
	{
		if (pthread_create(&list[count].thread_id, NULL, ft_tasks, (void *)&list[count]) != 0)
			return (1);
		count++;
	}
	count = 0;
	while (count < size)
	{
		if (pthread_join(list[count].thread_id, NULL) != 0)
			return (1);
		count++;
	}
	return (0);
}