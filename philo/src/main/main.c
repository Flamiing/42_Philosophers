/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:54:01 by alaaouam          #+#    #+#             */
/*   Updated: 2023/04/21 18:16:58 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 5 && argc != 6)
		return (ft_how_to_use());
	data = ft_parser(argv);
	if (!data)
		return (ft_print_error(PARSING_ERROR));
	if (ft_create_threads(data->list, data->philo_count) != 0)
	{
		ft_free_data(data);
		return (ft_print_error(THREADS_ERROR));
	}
	ft_free_data(data);
	return (0);
}
