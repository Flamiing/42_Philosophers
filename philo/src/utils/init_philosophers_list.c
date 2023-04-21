/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosophers_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:43:03 by alaaouam          #+#    #+#             */
/*   Updated: 2023/04/07 23:36:38 by alaaouam         ###   ########.fr       */
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

t_philo	*ft_create_list(t_data *data, long long size)
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
