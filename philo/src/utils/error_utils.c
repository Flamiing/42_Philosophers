/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:03:15 by alaaouam          #+#    #+#             */
/*   Updated: 2023/04/03 13:52:41 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>
#include <unistd.h>

int	ft_how_to_use(void)
{
	write(2, "Usage: ./philo <number_of_philosophers> <time_to_die>", 53);
	write(2, " <time_to_eat> <time_to_sleep> ", 30);
	write(2, " [number_of_times_each_philosopher_must_eat]\n", 45);
	return (WRONG_NUMBER_ARGS);
}

int	ft_print_error(char	*error)
{
	int	len;

	if (!error)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	len = ft_strlen(error);
	write(2, "Error: ", 7);
	write(2, error, len);
	return (len);
}
