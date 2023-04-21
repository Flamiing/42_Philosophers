/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 21:47:40 by alaaouam          #+#    #+#             */
/*   Updated: 2023/04/18 11:32:10 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>
#include <pthread.h>

void	ft_free_data(t_data *data)
{
	long long	count;

	if (!data)
		return ;
	count = 0;
	if (data->list)
		free(data->list);
	while (count < data->philo_count)
	{
		pthread_mutex_destroy(&data->forks[count]);
		count++;
	}
	free(data->forks);
	pthread_mutex_destroy(&data->printing);
	pthread_mutex_destroy(&data->death);
	free(data);
}

void	*ft_free_and_return(t_data *data)
{
	ft_free_data(data);
	return (NULL);
}
