/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:58:26 by alaaouam          #+#    #+#             */
/*   Updated: 2023/04/19 12:31:36 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>
#include <sys/time.h>

long long	ft_time_to_ms(struct timeval time)
{
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long long	ft_time_elapsed(struct timeval start, struct timeval end)
{
	long long	start_ms;
	long long	end_ms;
	
	start_ms = ft_time_to_ms(start);
	end_ms = ft_time_to_ms(end);
	return (end_ms - start_ms);
}

long long	ft_get_time(struct timeval start)
{
	struct timeval	current_time;
	
	gettimeofday(&current_time, NULL);
	return (ft_time_elapsed(start, current_time));
}

long long	ft_usleep(long long ms)
{
	struct timeval	current_time;
	long long	reference;

	gettimeofday(&current_time, NULL);
	reference = ft_time_to_ms(current_time) + ms;
	while(ft_time_to_ms(current_time) < reference)
	{
		gettimeofday(&current_time, NULL);
		usleep(1000);
	}
	return (0);
}