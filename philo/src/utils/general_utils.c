/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:01:00 by alaaouam          #+#    #+#             */
/*   Updated: 2023/04/21 18:16:15 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

long long	ft_atoll(const char *string)
{
	long long		count;
	long long		sign;
	long long		number;

	count = 0;
	sign = 1;
	number = 0;
	while (string[count] == 32 || (string[count] > 8 && string[count] <= 13))
		count++;
	if (string[count] == 45 || string[count] == 43)
	{
		if (string[count] == 45)
			sign *= -1;
		count++;
	}
	while ((string[count] != '\0' && (string[count] >= 48
				&& string[count] <= 57)))
	{
		number += string[count] - 48;
		if (string[count + 1] >= 48 && string[count + 1] <= 57)
			number *= 10;
		count++;
	}
	return (number * sign);
}

long long	ft_strlen(const char *s)
{
	long long	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

static void	ft_bzero(void *s, size_t n)
{
	size_t			count;
	unsigned char	*ptr;

	count = 0;
	ptr = (unsigned char *)s;
	while (count < n)
	{
		ptr[count] = 0;
		count++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}
