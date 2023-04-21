/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:15:54 by alaaouam          #+#    #+#             */
/*   Updated: 2023/04/21 18:18:20 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static int	ft_is_numeric(char **args)
{
	size_t		count;
	long long	pos;
	long long	not_number;

	count = 1;
	while (args[count])
	{	
		pos = 0;
		not_number = 0;
		while (args[count][pos])
		{
			if (args[count][pos] < 48 || args[count][pos] > 57)
				not_number++;
			pos++;
		}
		if (not_number > 0)
			return (0);
		count++;
	}
	return (1);
}

static int	ft_no_overflow(char **args)
{
	size_t	count;

	count = 1;
	while (args[count])
	{
		if (ft_atoll(args[count]) <= 0)
			return (0);
		count++;
	}
	return (1);
}

static int	ft_valid_args(char **args)
{
	if (!args)
		return (0);
	if (ft_is_numeric(args))
	{
		if (ft_no_overflow(args))
			return (1);
	}
	return (0);
}

t_data	*ft_parser(char **args)
{
	t_data	*data;

	data = NULL;
	if (ft_valid_args(args))
	{
		data = ft_init_data(args);
		if (!data)
			return (NULL);
	}
	return (data);
}
