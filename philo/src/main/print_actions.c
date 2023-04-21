/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:39:31 by alaaouam          #+#    #+#             */
/*   Updated: 2023/04/19 12:44:40 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>
#include <stdio.h>
#include <sys/time.h>

int	ft_print_action(t_philo *philo, char *does)
{
	pthread_mutex_lock(&philo->data->printing);
	printf("%lld %lld %s", ft_time(philo), philo->id, does);
	pthread_mutex_unlock(&philo->data->printing);
	return (0);
}
